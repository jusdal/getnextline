/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/07 04:12:33 by jdaly            ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int		splitlength;
	//int		i;
	int		nread;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	if (fd < 0)
		return (0);
	nread = 1;
	while (nread != 0 && !(fn_checknl(stash)))
	{
		nread = read(fd, buf, BUFFER_SIZE);
		buf[nread] = '\0';
		if (!fn_checknl(buf))
		{
			if (nread == -1)
			{
				free(buf);
				return (0);
			}
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
	}
	free(buf);
//	free(line);
	return (0);
}

/*int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("FINAL = %s", get_next_line(fd));
	printf("NEXTCALL = %s", get_next_line(fd));
	printf("NEXTCALL = %s", get_next_line(fd));
}*/
