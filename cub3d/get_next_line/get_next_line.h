/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:57:27 by sjin              #+#    #+#             */
/*   Updated: 2021/07/01 21:05:40 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define OPEN_MAX 32

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen1(const char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strdup1(char *str);

#endif
