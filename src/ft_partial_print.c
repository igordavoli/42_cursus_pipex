#include "pipex.h"

void	partial_print(t_pipex *pipex)
{
	int		i;
	int		j;

	printf("argc:....%d\n", pipex->argc);
	printf("argv:\n");
	i = -1;
	while (pipex->argv[++i])
		printf("     [%d] %s\n", i, pipex->argv[i]);
	printf("n_cmds:..%d\n", pipex->n_cmds);
	printf("cmdpath:.%s\n", pipex->cmdpath);
	printf("cmds:\n");
	i = 0;
	while (pipex->cmds[i])
	{
		j = 0;
		printf("splitted cmd [%d]: ", i);
		while (pipex->cmds[i][j])
			printf("'%s' ", pipex->cmds[i][j++]);
		i++;
		printf("\n");
	}
	printf("infile:..%s\n", pipex->infile);
	printf("outfile:.%s\n", pipex->outfile);
	printf("curr_fd:.%d\n", pipex->curr_in_fd);
}
