/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/10 20:57:34 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	fn_freestr(char *str)
{
	
	free(str);
	str = NULL;
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buf;
	char		*line;
	char		*temp;
	int		splitlength;
	//int		i;
	int		nread;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	nread = 1;
	while (nread > 0)
	{
		nread = read(fd, buf, BUFFER_SIZE);
		buf[nread] = '\0';
		if (nread == -1)
			fn_freestr(buf);
		if (!stash)
			stash = ft_strdup("");
		if (fn_checknl(stash))
		{
			splitlength = fn_splitlength(stash) + 1;
			//printf("splitlength = %d\n", splitlength);
			//printf("buf = %s\n", buf);
			if (!(line = (char *)malloc(sizeof(char) * (splitlength + 1))))
				return (0);
			ft_strlcpy(line, stash, splitlength);
			//printf("line = %s\n", line);
			//printf("stash before split = %s\n", stash);
			temp = &stash[splitlength];
			stash = ft_strjoin(temp, buf);
			return (line);
		}
		else if (!(fn_checknl(stash)))
		{
			//printf("stash_before = %s\n", stash);
			temp = stash;
			fn_freestr(stash);
			stash = ft_strjoin(temp, buf);
		}
	}
	fn_freestr(buf);
//	free(line);
	return (0);
}

int	main(void)
{
	int     fd;
    char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
    while (line)
	{
		printf("%s\n",line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}