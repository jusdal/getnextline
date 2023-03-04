/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:28:45 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/04 13:34:05 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			read;

	while (read(fd, buf, n) != 0)
	{
		if (!fn_checknl(buf))
		{
			stash = ft_strjoin(stash, buff);
		}
		else 
		{
			//copy/join buf & stash
		}
	}
}
