/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:16:59 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:45:13 by idavoli-         ###   ########.fr       */
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

# include <stdio.h>

# include "../libs/libft/libft.h"

// # include "../libs/gnl/get_next_line.h"
// # include "../libs/minilibx/mlx.h"
// # include "../libs/ft_printf/ft_printf.h"
// # include "so_long_defines.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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
	int		curr_in_fd;
	int		out_fd;
}	t_pipex;

// void	ft_check_args(int argc, char **argv);
char	*ft_load_file(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd, int lf);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy( void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_arglen(const char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_arglen(const char **argv);
void	ft_free_pipex(t_pipex *pipex);
void	ft_get_cmds( t_pipex *pipex);
void	ft_pipex_init(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_get_path(t_pipex *pipex);
void	ft_exit_pipex(t_pipex *pipex, char *message, int code);
// void	ft_close_message(t_game *game, char *message, int code);
// int		ft_close(void *_game);

#endif
