/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:42:56 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:44:52 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exit_pipex(t_pipex *pipex, char *message, int code)
{
	ft_free_pipex(pipex);
	printf("%s", message);
	exit(code);
}
