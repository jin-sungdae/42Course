/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:54:53 by sangcpar          #+#    #+#             */
/*   Updated: 2020/10/13 22:47:48 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_putnstr(char *str, int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char *s1, char *s2, int f);
char				*ft_substr(char const *s, unsigned int start, size_t len);

void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *b, int c, size_t n);
int					ft_memcmp(const void *b1, const void *b2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t				ft_strlcat(char *dest, const char *src, size_t destsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, \
const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *str);

int					ft_cleanup(char **cpy, char **line, int fd, int rd_ret);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_lentoc(char *str, char c);

char				**ft_split2(char *s, char c);
int					check_row(char *str, char c);
int					find_new_column(const char *str);
char				**malloc_free(char **new_str);
size_t				find_column(char const *s, char c);
size_t				ft_strlcpy_new_str1(char *dst, \
char const *src, size_t size);

void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);

#endif
