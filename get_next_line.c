/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/05 01:49:42 by jdaly            ###   ########.fr       */
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

int	fn_splitlength(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n')
		i++;
	return (i);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i + 1);
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
	int		splitlength;
	int		i;
	int		nread;

	i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nread = read(fd, stash, BUFFER_SIZE);
	if (!stash || fd < 0)
		return (0);
	while (nread != 0)
	{
		if (!fn_checknl(stash))
		{
			printf("stash = %s\n", stash);
			stash = ft_strjoin(stash, buf);
			printf("stash = %s\n", stash);

		}
		else 
		{
			printf ("new line found\n");
			/*splitlength = fn_splitlength(buf);
			line = (char *)malloc(sizeof(char) * (ft_strlen(stash) + splitlength + 1));
			ft_strcat(stash, buf, splitlength + 1);
			line = stash + char before new line in buf
			splitlength = fn_splitlength(buf) + 1;
			line = (char *)malloc(sizeof(char) * (ft_strlen(stash) + splitlength + 1));
			if (!line)
				return (0);
			while (i < splitlength)
			{
				line[ft_strlen(stash)] = buf[i];
				i++;
			}
			line[ft_strlen(line)] = '\0';
			printf("line = %s", line);
			printf("stash before split = %s\n", stash);
			//free(stash);
			stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE - splitlength) + 1);
			while (i >= splitlength && i < BUFFER_SIZE)
			{
				stash[i] = buf[splitlength];
				splitlength++;
				i++;
			}
			stash[i] = '\0';
			//stash = char after new line if buf
			printf("stash after join = %s\n", stash);*/
			return (line);
		}
		nread = read(fd, buf, BUFFER_SIZE);
	}
	//free(buf);
	//free(line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("FINAL = %s\n", get_next_line(fd));
	//printf("NEXTCALL = %s", get_next_line(fd));
	//printf("NEXTCALL = %s", get_next_line(fd));
}
