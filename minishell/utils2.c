/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:58:15 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 13:44:12 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_fds(t_shell *mini)
{
	mini->pipe[0] = -1;
	mini->pipe[1] = -1;
	mini->fds[0] = -1;
	mini->fds[1] = -1;
	mini->prev_pipe = -1;
	mini->pipe_chk = 0;
}

void	full_reset(t_shell *mini)
{
	dup2(mini->in, STDIN_FILENO);
	dup2(mini->out, STDOUT_FILENO);
	ft_close(mini->fds[0]);
	ft_close(mini->fds[1]);
	reset_fds(mini);
}

void	mini_c_p(t_shell *mini, t_list *list)
{
	mini->prev_pipe = STDIN_FILENO;
	mini->count = ft_lstsize(list);
	mini->i = 0;
}

void	list_jmp(t_shell *mini, t_list **list)
{
	int	i;

	i = -1;
	*list = (*list)->next;
	while (mini->i > 0)
	{
		*list = (*list)->next;
		mini->i--;
	}
	while (mini->here_ck && mini->heredoc_name[++i])
	{
		unlink(mini->heredoc_name[i]);
		free(mini->heredoc_name[i]);
	}
	if (mini->here_ck && mini->heredoc_name)
		free(mini->heredoc_name);
	mini->i = 0;
}
