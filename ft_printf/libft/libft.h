/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:28:22 by sjin              #+#    #+#             */
/*   Updated: 2021/03/10 20:28:26 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t n, size_t size);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *ptr, int value, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n);
void	*ft_memchr(const void *ptr, int value, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char const *str, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t num);
int		ft_strlen(char *str);
char	*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_putchar(char c);
void	ft_putnbr(int nb);
char	*ft_itoa(long nb);
void	ft_putstr(char *str);
char	*ft_itoa_base(long long nb, int base);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
#endif
