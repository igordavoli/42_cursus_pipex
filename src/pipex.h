/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/23 00:50:27 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <wait.h>
# include "../libs/libft/src/libft.h"

# include <stdio.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*cmdpath;
	char	*infile;
	int		n_cmds;
	char	***cmds;
	char	*outfile;
}	t_pipex;

void	ft_check_args(int argc, char **argv);
void	ft_pipex_init(t_pipex *pipex, int argc, char **argv, char **envp);
int		ft_open(t_pipex *pipex, char *file, int oflag);
void	ft_get_cmds( t_pipex *pipex);
void	ft_get_path(t_pipex *pipex);
void	ft_exec_cmds(t_pipex *pipex);
void	ft_free_pipex(t_pipex *pipex);
void	ft_exit_pipex(t_pipex *pipex, char *message, int code, int free_msg);

#endif
