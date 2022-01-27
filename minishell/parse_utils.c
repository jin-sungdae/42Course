/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 02:20:40 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 13:59:58 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	plus_cmd(char **cmd)
{
	char	*tmp;
	int		j;

	j = 1;
	while ((*cmd)[ft_strlen(*cmd) - j] == ' ')
		j++;
	if ((*cmd)[ft_strlen(*cmd) - j] == '|')
	{
		tmp = readline("pipe> ");
		while (1)
		{
			*cmd = pipe_join(cmd, tmp);
			free(tmp);
			while ((*cmd)[ft_strlen(*cmd) - j] == ' ')
				j++;
			if ((*cmd)[ft_strlen(*cmd) - j] != '|')
				break ;
			tmp = readline("pipe> ");
		}
	}
}

int	oper_err_msg(char **cmd, int i)
{
	if (ft_strchr("<>|", (*cmd)[i++]))
	{
		if ((*cmd)[0] == '|')
		{
			ft_putstr_fd(\
			"minishell: syntax error near unexpected token '|'\n", 2);
			return (1);
		}
		while (((*cmd)[i] == '<' || (*cmd)[i] == '>') || \
		((*cmd)[i] && (*cmd)[i] == ' '))
			i++;
		if (!(*cmd)[i])
		{
			ft_putstr_fd(\
			"minishell: syntax error near unexpected token \'newline\'\n", 2);
			return (1);
		}
	}
	plus_cmd(cmd);
	if (q_count(cmd))
	{
		ft_putstr_fd("minishell: Quotes Error\n", 2);
		return (1);
	}
	return (0);
}

int	add_list(t_list **list, char *cmd, int i)
{
	int		j;
	t_ops	*ops;

	j = 1;
	if (cmd[i])
	{
		while (cmd[i + j] && cmd[i + j] == ' ')
			j++;
		if (!cmd[i + j])
		{
			if (cmd[i] == '<' || cmd[i] == '>')
			{
				ft_putstr_fd("minishell: syntax error ", 2);
				ft_putstr_fd("near unexpected token `newline'\n", 2);
			}
			free_list(list);
			return (1);
		}
	}
	ops = set_ops(cmd, i);
	ft_lstadd_back(list, ft_lstnew(ops));
	return (0);
}

int	cmd_chk(char **cmd)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	if ((*cmd)[0] == '\'' || (*cmd)[0] == '\"')
	{
		q = 1;
		i++;
	}
	while ((*cmd)[i] == ' ')
		i++;
	if (!(*cmd)[i])
		return (1);
	i = 0;
	if (oper_err_msg(cmd, i))
		return (1);
	return (0);
}

int	line_chk(char *line, int i)
{
	(void)line;
	return (i);
}
// return (((line[0] == '\"' || line[0] == '\'' || !line[i + 1] || \
	// (line[i] != ' ' && line[i + 1] == ' ')) && i > 0) || \
	// (i == 0 && line[0] && !line[1]) || \
	// (i == 1 && line[i] == ' ' && line[i + 1] != ' '));