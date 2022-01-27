/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:35:04 by sjin              #+#    #+#             */
/*   Updated: 2021/09/06 16:12:53 by sjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *curr)
{
	if (!curr)
	{
		ft_putstr_len("ERROR: incorrect command\n");
		exit(1);
	}
}

void	ft_testpaths(char *cmd, char **args, char **paths)
{
	int		i;
	char	*temp;
	char	*newpath;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		newpath = ft_strjoin(temp, cmd);
		if (execve(newpath, args, environ) != -1)
		{
			free(newpath);
			ft_freeall(paths);
			return ;
		}
		free(newpath);
		i++;
	}
	if (i == ft_freelen(paths))
		ft_putstr_len("No such command found.");
}

void	ft_exec(char *cmd, char **args)
{
	int		i;
	char	**paths;

	paths = NULL;
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			environ[i] += 5;
			paths = ft_split(environ[i], ':');
			break ;
		}
		i++;
	}
	ft_testpaths(cmd, args, paths);
}

char	*get_path(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strstr(env[i], "PATH") != 0)
			return (env[i] + 5);
	}
	return (NULL);
}

char	*parse_path(char *path, char *cmd)
{
	char	**dir;
	char	*curr;
	int		i;

	i = -1;
	dir = ft_split(path, ':');
	while (dir[++i])
	{
		if (cmd[0] == '/')
			curr = ft_strjoin(dir[i], &cmd[4]);
		else
			curr = ft_strjoin(ft_strjoin(dir[i], "/"), cmd);
		if (!access(curr, F_OK))
			return (curr);
	}
	return (NULL);
}
