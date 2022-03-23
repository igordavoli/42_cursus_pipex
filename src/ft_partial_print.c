#include "pipex.h"

void	partial_print(t_pipex *pipex)
{
	int		i;
	int		j;

	ft_printf("argc:....%d\n", pipex->argc);
	ft_printf("argv:\n");
	i = -1;
	while (pipex->argv[++i])
		ft_printf("     [%d] %s\n", i, pipex->argv[i]);
	ft_printf("n_cmds:..%d\n", pipex->n_cmds);
	ft_printf("cmdpath:.%s\n", pipex->cmdpath);
	ft_printf("cmds:\n");
	i = 0;
	while (pipex->cmds[i])
	{
		j = 0;
		ft_printf("splitted cmd [%d]: ", i);
		while (pipex->cmds[i][j])
			ft_printf("'%s' ", pipex->cmds[i][j++]);
		i++;
		ft_printf("\n");
	}
	ft_printf("infile:..%s\n", pipex->infile);
	ft_printf("outfile:.%s\n", pipex->outfile);
}
