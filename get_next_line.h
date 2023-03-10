/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:55:49 by jdaly             #+#    #+#             */
/*   Updated: 2023/03/11 03:10:04 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 5

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>


char	*get_next_line(int fd);
int	fn_checknl(char *str);
int	fn_splitlength(char *str);
char	*readfd(int fd, char *stash);
char	*createline(char *stash, int linelength);
char	*keep(char *stash, int linelength);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);


#endif
