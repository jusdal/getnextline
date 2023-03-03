/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/03 23:23:15 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int fn_checknl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return 0;
}

char *get_next_line(int fd)
{
	static char *stash;
	char *buf;
	char *line;
	int read;

	while (read(fd, buf, n) != 0)
	{
		read(fd, buf, n);
		stash = buff;
		if (fn_checknl(stash))
		{

		}
	}
}
