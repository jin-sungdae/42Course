/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_del.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:24:15 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 13:45:16 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_change(t_shell *mini, char **tmp, int	i, int qq)
{
	int		j;
	char	*tm;
	char	*tm2;
	char	*sub;
	int		chk;

	j = 0;
	chk = 0;
	tm2 = NULL;
	tm = ft_strdup("");
	while (tmp[i][j] && qq == 0 && env_chk(mini, &tmp[i][j]))
	{
		chk = 1;
		while (tmp[i][j] != '$')
			tm = fstr_join(&tm, tmp[i] + j++);
		sub = ft_substr(tmp[i], j + 1, env_len(tmp[i] + j));
		tm = ft_strjoin(tm, get_env(mini->c_evs, sub), 1);
		j += env_len(tmp[i] + j);
		fr_jplus(&tmp[i], &sub, &tm2, &j);
		tm2 = ft_strjoin(tm, (tmp[i] + j), 4);
	}
	fr_dup(&tmp[i], &tm2, &tm, chk);
}

void	q_d(t_shell *mini, char **args, char **tmp, int i)
{
	int		qq;

	qq = 0;
	if (args[i][0] == '\'')
		qq = 1;
	if (args[i][0] == '\"' && args[i][1] == '$')
		tmp[i] = ft_substr(args[i], 1, (ft_strlen(args[i]) - 2));
	else if (args[i][0] == '\'' && args[i][1] == '$')
		tmp[i] = ft_substr(args[i], 1, (ft_strlen(args[i]) - 2));
	else if (args[i][0] == '\'' || args[i][0] == '\"')
		tmp[i] = ft_substr(args[i], 1, (ft_strlen(args[i]) - 2));
	else
		tmp[i] = ft_strdup(args[i]);
	env_change(mini, tmp, i, qq);
}

char	**q_del(t_shell *mini, t_list *list, char **args)
{
	char	**tmp;
	char	*line;
	int		i;

	i = 0;
	while (args[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	line = ((t_ops *)(list->content))->operation;
	i = -1;
	while (args[++i])
	{
		while (ft_strncmp(line, args[i], ft_strlen(args[i])))
			line++;
		q_d(mini, args, tmp, i);
		line += ft_strlen(args[i]);
	}
	tmp[i] = NULL;
	path_free(args);
	return (tmp);
}

void	q_chk_norm(t_shell *mini, t_list *tlist, int *chk1, int *chk2)
{
	int	i;

	while (tlist)
	{
		i = 0;
		((t_ops *)(tlist->content))->args = q_del(mini, tlist, \
		((t_ops *)(tlist->content))->args);
		while (((t_ops *)(tlist->content))->args[i])
		{
			if (!ft_strcmp(((t_ops *)(tlist->content))->args[i++], ""))
				*chk1 = 1;
			else
				*chk2 = 0;
		}
		tlist = tlist->next;
	}
}

int	q_chk(t_shell *mini, t_list *list)
{
	t_list	*tlist;
	int		chk1;
	int		chk2;

	chk1 = 0;
	chk2 = 1;
	if (!list)
		return (-1);
	tlist = list;
	q_chk_norm(mini, tlist, &chk1, &chk2);
	if (chk1 && chk2)
		return (1);
	return (0);
}
