/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:35:09 by sjin              #+#    #+#             */
/*   Updated: 2021/09/06 16:13:34 by sjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	child(int fdpid, char *cmd2, t_pid *p)
{
	int	fd;

	fd = open(p->file2, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		ft_putstr_len("Can't write into file.\n");
	dup2(fdpid, STDIN_FILENO);
	close(fdpid);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (p->cmd2[0][0] == '/')
	{
		if (execve(cmd2, p->cmd2, environ) == -1)
			ft_putstr_len("ERROR: can't apply second command.\n");
	}
	else
		ft_exec(p->cmd2[0], p->cmd2);
	free(cmd2);
	return (0);
}

int	parent(int fdpid, char *path, t_pid *p)
{
	int	fd;

	fd = open(p->file1, O_RDONLY);
	if (fd == -1)
		ft_putstr_len("Can't read file.\n");
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdpid, STDOUT_FILENO);
	close(fdpid);
	if (p->cmd1[0][0] == '/')
	{
		if (execve(path, p->cmd1, environ) == -1)
			ft_putstr_len("ERROR: can't apply first command.\n");
	}
	else
		ft_exec(p->cmd1[0], p->cmd1);
	free(path);
	return (0);
}

int	ft_pipex(t_pid *p)
{
	pid_t	pid;
	int		mypipefd[2];
	char	*curr;

	if (pipe(mypipefd))
		ft_putstr_len("ERROR\n");
	pid = fork();
	if (pid == 0)
	{
		close(mypipefd[0]);
		curr = parse_path(p->path, p->cmd1[0]);
		ft_error(curr);
		parent(mypipefd[1], curr, p);
	}
	else if (pid > 0)
	{
		close(mypipefd[1]);
		curr = parse_path(p->path, p->cmd2[0]);
		ft_error(curr);
		child(mypipefd[0], curr, p);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_pid	p;

	if (argc != 5)
	{
		ft_putstr_len("NO UNUSAGE\n");
		return (0);
	}
	p.file1 = argv[1];
	p.file2 = argv[4];
	p.path = "PATH";
	p.cmd1 = ft_split2(argv[2], ' ');
	p.cmd2 = ft_split2(argv[3], ' ');
	p.path = get_path(environ);
	if (!(p.path))
		ft_putstr_len("ERROR: can't find path.\n");
	if (!(p.cmd1) || !(p.cmd2))
	{
		ft_putstr_len("NO COMMNAND\n");
		return (0);
	}
	ft_pipex(&p);
	return (0);
}
