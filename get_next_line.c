/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/10 22:15:02 by jdaly            ###   ########.fr       */
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

int	fn_getlength(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

/*void	fn_freestr(char *str)
{
	
	free(str);
	str = NULL;
}*/
char	*readfile(int fd, char *stash)
{
	char	*buf;
	int		nread;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	nread = 1;
	while (nread > 0)
	{
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread < 0)
		{
			free(buf);
			return (0);
		}
		buf[nread] = '\0';
		stash = ft_strjoin(stash, buf);
		if (fn_checknl(buf))
			break;
	}
	free(buf);
	return(stash);
}

char	*createline(char *stash, int linelength)
{
	char	*line;

	if (stash == NULL)
		return (0);
	if (!(line = malloc(sizeof(char) * (fn_getlength(stash) + 1))))
		return (0);
	ft_strlcpy(line, stash, linelength);
		return (line);
}

char	*keep(char *stash, int linelength)
{
	char	*temp;

	if (stash[linelength + 1] = '\0')
	{
		free(stash);
		return (0);
	}
	if (!(temp = malloc(1)))
		return (0);
	temp[0] = '\0';
	ft_strlcpy(temp, &stash[linelength], ft_strlen(stash - linelength));
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	//char		*buf;
	char		*line;
	//char		*temp;
	int			linelength;
	//int			nread;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	stash = readfile(fd, stash);
	if (!stash[0])
	{
		free(stash);
		return (0);
	}
	linelength = fn_getlength(stash) + 1;
	line = createline(stash, linelength);
	stash = keep(stash, linelength);
	return (line);
}
	
	/*if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
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
*/
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