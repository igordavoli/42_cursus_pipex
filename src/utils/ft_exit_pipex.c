/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:42:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/23 00:07:31 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exit_pipex(t_pipex *pipex, char *message, int code, int free_msg)
{
	ft_free_pipex(pipex);
	ft_printf("%s\n", message);
	if (free_msg)
		free(message);
	exit(code);
}
