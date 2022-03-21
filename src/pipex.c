/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:44:50 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:48:17 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	partial_print(t_pipex *pipex);

void	ft_exec_cmd(t_pipex *pipex, int i, int *curr_fd)
{
	int		pid;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		ft_exit_pipex(pipex, "cannot create pipe", 1);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fds[0]);
		dup2(pipex->curr_in_fd, STDIN_FILENO);
		if (i == (pipex->n_cmds - 1))
			dup2(pipex->out_fd, STDOUT_FILENO);
		else
			dup2(pipe_fds[1], STDOUT_FILENO);
		execve(pipex->cmds[i][0], pipex->cmds[i], pipex->envp);
		close(pipex->curr_in_fd);
		close(pipe_fds[1]);
		exit(0);
	}
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

	i = 0;
	while (i < pipex->n_cmds)
		ft_exec_cmd(pipex, i++, &pipex->curr_in_fd);
	printf("Fim!\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_pipex_init(&pipex, argc, argv, envp);
	partial_print(&pipex);
	ft_exec_cmds(&pipex);
	ft_free_pipex(&pipex);
	printf("OK!\n");
	return (0);
}
