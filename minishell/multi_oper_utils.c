/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_oper_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 05:06:15 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/27 16:41:40 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	multi_chk1(t_shell *mini, t_list *list)
{
	t_list	*tlist;
	int		i;

	i = 0;
	tlist = list;
	mini->i = 0;
	while (tlist)
	{
		if ((((t_ops *)(tlist->content))->type == '<' || \
		((t_ops *)(tlist->content))->type == '{') && \
		(((t_ops *)(tlist->next->content))->type == '>' || \
		((t_ops *)(tlist->next->content))->type == '}'))
			i = 1;
		tlist = tlist->next;
	}
	return (i);
}

int	multi_chk2(t_shell *mini, t_list *list)
{
	t_list	*tlist;
	int		i;

	i = 0;
	(void)mini;
	tlist = list;
	while (tlist)
	{
		if ((((t_ops *)(tlist->content))->type == '<' || \
		((t_ops *)(tlist->content))->type == '{') && \
		(((t_ops *)(tlist->next->content))->type == '|'))
			i = 1;
		if (((t_ops *)(tlist->content))->type == ';')
			return (i);
		tlist = tlist->next;
	}
	return (i);
}

void	m_chk(t_list *list, t_shell *mini)
{
	t_list	*tlist;
	int		i;

	i = 0;
	tlist = list;
	while (tlist)
	{
		if (((t_ops *)(tlist->content))->type == '{' || \
		((t_ops *)(tlist->content))->type == '<')
			i++;
		tlist = tlist->next;
	}
	if (i > 1)
		mini->i++;
}

void	heredoc_count(t_list *list, int *here)
{
	while (list)
	{
		if (((t_ops *)(list->content))->type == '{')
			(*here)++;
		list = list->next;
	}
}

int	input_num(t_list *list)
{
	t_list	*tlist;
	int		num;

	num = 0;
	tlist = list;
	while (tlist)
	{
		if (((t_ops *)(tlist->content))->type == '<' || \
		((t_ops *)(tlist->content))->type == '{')
			num++;
		tlist = tlist->next;
	}
	return (num - 1);
}
