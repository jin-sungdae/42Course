/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:03:35 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 13:32:01 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operator_pipe(t_list *list, t_shell *mini)
{
	pid_t	pid;

	mini->args = ((t_ops *)(list->content))->args;
	pipe(((t_ops *)(list->content))->fds);
	pid = fork();
	if (pid == 0)
	{
		close(((t_ops *)(list->content))->fds[0]);
		dup2(mini->prev_pipe, STDIN_FILENO);
		dup2(((t_ops *)(list->content))->fds[1], 1);
		exec_cmp(mini, mini->args, list);
		exit(2);
	}
	wait(&pid);
	close(((t_ops *)(list->content))->fds[1]);
	mini->prev_pipe = ((t_ops *)(list->content))->fds[0];
	return (0);
}

int	redirect_output(t_list *list, t_shell *mini)
{
	char	*filename;

	ft_close(mini->fds[1]);
	filename = ((t_ops *)(list->next->content))->args[0];
	if (((t_ops *)(list->content))->type == '>')
		mini->fds[1] = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		mini->fds[1] = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (mini->fds[1] == -1)
		return (-1);
	dup2(mini->fds[1], STDOUT_FILENO);
	return (0);
}

int	append_output(t_list *list, t_shell *mini)
{
	int		fd;
	char	*filename;

	mini->fds[0] = dup(STDOUT_FILENO);
	filename = ((t_ops *)(list->next->content))->args[0];
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (-1);
	dup2(fd, STDOUT_FILENO);
	mini->rv = exec_cmp(mini, mini->args, list);
	dup2(mini->fds[0], STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_input(t_list *list, t_shell *mini)
{
	char	*filename;

	ft_close(mini->fds[0]);
	filename = ((t_ops *)(list->next->content))->args[0];
	mini->fds[0] = open(filename, O_RDONLY);
	if (mini->fds[0] == -1)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": no such file or directory\n", 2);
		return (-1);
	}
	dup2(mini->fds[0], STDIN_FILENO);
	return (0);
}

void	make_heredoc(t_shell *mini, t_list *list)
{
	char	*str;
	int		fd;

	(void)mini;
	fd = open(((t_ops *)(list->next->content))->args[0], \
	O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exit(1);
	str = readline("> ");
	while (str != NULL && ft_strcmp(str, \
	((t_ops *)(list->next->content))->args[0]))
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline("> ");
	}
	free(str);
	close(fd);
}
