/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:32:20 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 20:51:02 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_load_file(int fd)
{
	int		i;
	char	*filecontent;
	char	*swp;
	char	*swp2;

	filecontent = (char *)malloc(sizeof(char));
	filecontent[0] = 0;
	i = 0;
	while (1)
	{
		swp = get_next_line(fd, 1);
		if (swp == NULL)
			break ;
		swp2 = filecontent;
		filecontent = ft_strjoin(filecontent, swp);
		free(swp);
		free(swp2);
		i++;
	}
	return (filecontent);
}
