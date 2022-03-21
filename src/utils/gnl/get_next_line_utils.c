/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:36:15 by idavoli-          #+#    #+#             */
/*   Updated: 2022/03/21 00:40:18 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// static void	*ft_memcpy( void *dst, const void *src, size_t n)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	if (dst != NULL && src != NULL)
// 	{
// 		d = (unsigned char *) dst;
// 		s = (unsigned char *) src;
// 		while (n--)
// 			*d++ = *s++;
// 	}
// 	return (dst);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	srclen;

// 	srclen = 0;
// 	while (src[srclen])
// 		srclen++;
// 	if (dstsize > srclen + 1)
// 		ft_memcpy(dst, src, srclen + 1);
// 	else if (dstsize != 0)
// 	{
// 		ft_memcpy(dst, src, dstsize - 1);
// 		dst[dstsize - 1] = '\0';
// 	}
// 	return (srclen);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*str_dup;
// 	size_t	len;

// 	len = 0;
// 	while (s1[len])
// 		len++;
// 	str_dup = (char *)malloc(len + 1);
// 	ft_strlcpy(str_dup, s1, len + 1);
// 	return (str_dup);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	dstlen;
// 	size_t	srclen;
// 	int		to_add;

// 	dstlen = 0;
// 	while (dst[dstlen])
// 		dstlen++;
// 	srclen = 0;
// 	while (src[srclen])
// 		srclen++;
// 	to_add = dstsize - dstlen - 1;
// 	if (dstsize - 1 == dstlen)
// 		return (dstlen + srclen);
// 	if (!dstsize || ((dstsize - 1) <= dstlen))
// 		return (srclen + dstsize);
// 	if ((dstsize - 1) > (dstlen + srclen))
// 		ft_memcpy(dst + dstlen, src, srclen + 1);
// 	else if (dstsize != 0)
// 	{
// 		ft_memcpy(dst + dstlen, src, to_add);
// 		dst[dstsize - 1] = '\0';
// 	}
// 	return (dstlen + srclen);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	ch;
// 	size_t			size;

// 	ch = c;
// 	size = 0;
// 	while (s[size])
// 		size++;
// 	size++;
// 	while (size--)
// 	{
// 		if (*s == ch)
// 			return ((char *)s);
// 		s++;
// 	}
// 	return (NULL);
// }
