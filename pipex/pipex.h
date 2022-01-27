/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:35:19 by sjin              #+#    #+#             */
/*   Updated: 2021/09/06 16:21:47 by sjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

extern char		**environ;

typedef struct s_pid
{
	int		in;
	int		out;
	int		pidefd[2];
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;
	char	*path;
	char	*file1;
	char	*file2;
}				t_pid;

typedef struct s_ef{
	size_t	row;
	size_t	i;
}				t_ef;

void	ft_error(char *curr);
void	ft_testpaths(char *cmd, char **args, char **paths);
void	ft_exec(char *cmd, char **args);
char	*get_path(char **env);
char	*parse_path(char *path, char *cmd);
char	**ft_split2(char *s, char c);
int		check_row(char *str, char c);
int		find_new_column(const char *str);
char	**malloc_free(char **new_str);
size_t	find_column(char const *s, char c);
size_t	ft_strlcpy_new_str1(char *dst, char const *src, size_t size);
void	ef_init(t_ef *ef);
void	plus_row(char *str, t_ef *ef, char c);
void	plus_i(char *str, t_ef *ef);

#endif
