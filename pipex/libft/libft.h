/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:36:14 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 19:36:15 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_freeall(char **matrix);
int		ft_freelen(char **matrix);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_cmpchar(char c1, char c2);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_len(char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *dst, const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strstr(char *str, char *to_find);
int		ft_strlen(char *s);

#endif
