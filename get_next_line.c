/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/06 21:01:58 by jdaly            ###   ########.fr       */
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
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (ft_strlen(&s[start]) <= len)
		len = ft_strlen(&s[start]);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int		splitlength;
	//int		i;
	int		nread;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nread = read(fd, buf, BUFFER_SIZE);
	if (!buf || fd < 0)
		return (0);
	while (nread != 0 && !(fn_checknl(stash)))
	{
		if (!fn_checknl(buf))
		{
			if (!stash)
			{
				stash = ft_strdup(buf);
				//printf("stash1 = %s\n", stash);
			}
			else
			{
				//printf("stash_before = %s\n", stash);
				//printf("buf = %s\n", buf);
				stash = ft_strjoin(stash, buf);
				//printf("stash_after = %s\n", stash);
			}

		}
		else 
		{
			//printf ("new line found\n");
			splitlength = fn_splitlength(buf) + 1;
			//printf("splitlength = %d\n", splitlength);
			//printf("buf = %s\n", buf);
			if (!(line = (char *)malloc(sizeof(char) * (ft_strlen(stash) + splitlength + 1))))
				return (0);
			line = stash;
			ft_strlcat(line, buf, ft_strlen(stash) + splitlength + 1);
			//printf("line = %s\n", line);
			//printf("stash before split = %s\n", stash);
			free(stash);
			stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE - splitlength) + 1);
			stash = ft_substr(buf, splitlength, BUFFER_SIZE - splitlength + 1);
			//printf("stash after join = %s\n", stash);
			return (line);
		}
		nread = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
//	free(line);
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("FINAL = %s", get_next_line(fd));
	printf("NEXTCALL = %s", get_next_line(fd));
	printf("NEXTCALL = %s", get_next_line(fd));
}
