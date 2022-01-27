/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:20:14 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/31 14:20:15 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	i_jump(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ' && \
	(line[i] != '\'' && line[i] != '\"'))
		i++;
	i--;
	return (i);
}

void	cmd_jump(char **cmd, int *i)
{
	if ((*cmd)[*i] && ((*cmd)[*i + 1] == '>' || (*cmd)[*i + 1] == '<'))
		(*cmd) += 1;
	(*cmd) += *i + 1;
	*i = 0;
}

int	quote_skip(char *cmd, int i, char q, t_ops *ops)
{
	ops->in_quotes = 1;
	while (1)
	{
		i++;
		if (cmd[i] == q)
			return (i);
	}
}

int	q_count(char **cmd)
{
	int		i;
	int		re;
	char	q;

	i = -1;
	re = 0;
	while ((*cmd)[++i])
	{
		if ((*cmd)[i] == '\'' || (*cmd)[i] == '\"')
		{
			q = (*cmd)[i];
			i++;
			while ((*cmd)[i] != '\0' && (*cmd)[i] != q)
				i++;
			if ((*cmd)[i] == '\0')
				re = 1;
		}
	}
	return (re);
}
