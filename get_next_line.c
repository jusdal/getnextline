/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/04 20:03:31 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	fn_checknl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*fn_findnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (0);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize -1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (i > dstsize || dstsize == 0)
		return (dstsize + ft_strlen(src));
	j = 0;
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}

/*void	keep(char *str, char *before, char *after, char c)
{
	while (str)
	{
		if (str++ 

*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	char		**splitholder;
	int			nread;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nread = read(fd, buf, BUFFER_SIZE);
	if (!buf || fd < 0)
		return (0);
	while (nread != 0)
	{
		if (!fn_checknl(buf))
		{
			if (!stash)
				stash = (char *)malloc(sizeof(char) * 1);
				stash = "\0";
			stash = (char *)malloc(sizeof(char) * (2 * BUFFER_SIZE + 1));
			//printf("stash = %s\n", stash);
			stash = ft_strjoin(stash, buf);
			//printf("stash = %s\n", stash);;

		}
		else 
		{
			printf ("new line found\n"); //copy/join buf & stash
			//line = ft_strjoin(stash, );
			printf("stash before split = %s\n", stash);
			free(stash);
			stash = splitholder[1];
			printf("stash after join = %s\n", stash);
			return (line);
		}
		nread = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	free(line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("FINAL = %s\n", get_next_line(fd));
	printf("NEXTCALL = %s", get_next_line(fd));
	printf("NEXTCALL = %s", get_next_line(fd));
}
