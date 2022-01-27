/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 02:44:00 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 14:17:31 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	multi_pipe(t_list *list, t_shell *mini)
{
	pid_t	pid;

	m_chk(list, mini);
	mini->args = ((t_ops *)(list->content))->args;
	pipe(((t_ops *)(list->content))->fds);
	pid = fork();
	if (pid == 0)
	{
		close(((t_ops *)(list->content))->fds[0]);
		dup2(mini->prev_pipe, STDIN_FILENO);
		dup2(((t_ops *)(list->content))->fds[1], 1);
		redirect_input(list, mini);
		exit(0);
	}
	wait(&pid);
	close(((t_ops *)(list->content))->fds[1]);
	mini->prev_pipe = ((t_ops *)(list->content))->fds[0];
	if (((t_ops *)(list->content))->type == '{')
		unlink(((t_ops *)(list->next->content))->args[0]);
	return (0);
}

void	next_open(int	*fd, t_list **tlist, t_shell *mini)
{
	char	*filename;
	t_list	*list;

	list = *tlist;
	while (((t_ops *)(list->next->content))->type == '>' || \
	((t_ops *)(list->next->content))->type == '}')
	{
		mini->i++;
		list = list->next;
		filename = ((t_ops *)(list->next->content))->args[0];
		if (((t_ops *)(list->content))->type == '>')
			*fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (((t_ops *)(list->content))->type == '}')
			*fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
}

int	multi_red(t_shell *mini, t_list *list)
{
	int		fd;
	char	*filename;
	t_list	*tlist;

	tlist = list;
	while (((t_ops *)(list->content))->type != '>' && \
	((t_ops *)(list->content))->type != '}')
		list = list->next;
	mini->fds[0] = dup(STDOUT_FILENO);
	filename = ((t_ops *)(list->next->content))->args[0];
	if (((t_ops *)(list->content))->type == '>')
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (((t_ops *)(list->content))->type == '}')
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	next_open(&fd, &list, mini);
	if (fd == -1)
		return (-1);
	dup2(fd, STDOUT_FILENO);
	redirect_input(tlist, mini);
	dup2(mini->fds[0], STDOUT_FILENO);
	close(fd);
	return (0);
}

void	heredoc_chk(t_list *list, t_shell *mini)
{
	t_list	*tlist;
	int		here;

	tlist = list;
	here = 0;
	heredoc_count(tlist, &here);
	if (here > 0)
	{
		mini->heredoc_name = (char **)malloc(sizeof(char *) * (here + 1));
		mini->here_ck = 1;
	}
	tlist = list;
	here = 0;
	while (tlist)
	{
		if (((t_ops *)(tlist->content))->type == '{')
		{
			make_heredoc(mini, tlist);
			mini->heredoc_name[here++] = \
			ft_strdup(((t_ops *)(tlist->next->content))->args[0]);
			mini->heredoc_name[here] = NULL;
		}
		tlist = tlist->next;
	}
}

void	oper_norm(t_shell *mini, t_list **tlist, int *i)
{
	if (((t_ops *)((*tlist)->content))->type == '>' || \
	((t_ops *)((*tlist)->content))->type == '}')
		*i = redirect_output(*tlist, mini);
	else if (((t_ops *)((*tlist)->content))->type == '<' || \
	((t_ops *)((*tlist)->content))->type == '{')
		*i = redirect_input(*tlist, mini);
	mini->i++;
}
