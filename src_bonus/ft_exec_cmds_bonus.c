/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmds_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:21:03 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/24 20:28:25 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_here_doc(t_pipex *pipex)
{
	char	*str;
	int		fds[2];

	if (pipe(fds) == -1)
		ft_exit_pipex(pipex, "cannot create pipe!", 1, 0);
	ft_putstr_fd("here_doc", 1);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		str = get_next_line(STDIN_FILENO, 1);
		if (ft_strncmp(str, pipex->limiter, ft_strlen(pipex->limiter)) == 0
			&& str[ft_strlen(pipex->limiter)] == '\n')
		{
			close(fds[1]);
			free(str);
			close(0);
			str = get_next_line(STDIN_FILENO, 1);
			return (fds[0]);
		}
		ft_putstr_fd(str, fds[1]);
		free(str);
	}
}

static void	ft_child_task(t_pipex *pipex, int i, int *curr_fd, int *pipe_fds)
{
	close(pipe_fds[0]);
	dup2(*curr_fd, STDIN_FILENO);
	if (i == (pipex->n_cmds - 1))
		dup2(ft_open(pipex, pipex->outfile, O_WRONLY), STDOUT_FILENO);
	else
		dup2(pipe_fds[1], STDOUT_FILENO);
	if (execve(pipex->cmds[i][0], pipex->cmds[i], pipex->envp) == -1)
		ft_exit_pipex(pipex, ft_strjoin("cannot execute: ",
				pipex->cmds[i][0]), 1, 1);
	close(*curr_fd);
	close(pipe_fds[1]);
	exit(0);
}

static void	ft_exec_cmd(t_pipex *pipex, int i, int *curr_fd)
{
	int		pid;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		ft_exit_pipex(pipex, "cannot create pipe!", 1, 0);
	pid = fork();
	if (pid == 0)
		ft_child_task(pipex, i, curr_fd, pipe_fds);
	else
	{
		wait(NULL);
		*curr_fd = pipe_fds[0];
		close(pipe_fds[1]);
	}
}

void	ft_exec_cmds(t_pipex *pipex)
{
	int	i;
	int	curr_in_fd;

	if (pipex->is_hd)
		curr_in_fd = ft_here_doc(pipex);
	else
		curr_in_fd = ft_open(pipex, pipex->infile, O_RDONLY);
	i = 0;
	while (i < pipex->n_cmds)
		ft_exec_cmd(pipex, i++, &curr_in_fd);
	close(curr_in_fd);
}
