/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:14:31 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:35:53 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_get_cmds( t_pipex *pipex)
{
	int	i;

	pipex->cmds = (char ***)malloc(((pipex->n_cmds + 1) * sizeof(char **)));
	pipex->cmds[pipex->n_cmds] = NULL;
	i = 0;
	while (i < pipex->n_cmds)
	{
		pipex->cmds[i] = ft_split2(pipex->argv[i + 2], ' ');
		i++;
	}
}
