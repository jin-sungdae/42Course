/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 08:21:17 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/17 13:48:56 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
char	**rm_env(char **evs, char *arg)
{
	int		i;
	int		j;
	int		k;
	char	**ret;
	char	**tmp;
	char	*equl;

	tmp = evs;
	i = 0;
	k = -1;
	while (evs[i])
		i++;
	ret = malloc((sizeof(char *)) * i);
	i = 0;
	while (evs[++k])
	{
		equl = NULL;
		j = 0;
		while (evs[k][j] && evs[k][j] != '=')
			j++;
		equl = equal_back(evs[k]);
		if (ft_strcmp(equl, arg))
			ret[i++] = ft_strdup(evs[k]);
		free(equl);
	}
	ret[i] = NULL;
	path_free(tmp);
	return (ret);
}*/
int	env_count(char **evs, char *arg)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = -1;
	while (evs[++k])
	{
		j = 0;
		while (evs[k][j] && evs[k][j] != '=')
			j++;
		if (ft_strncmp(evs[k], arg, j + 1) != '=' && \
		!(!ft_strncmp(evs[k], arg, j) && !arg[j] && !evs[k][j]))
			i++;
	}
	return (i);
}

char	**rm_env(char **evs, char *arg)
{
	int		i;
	int		j;
	int		k;
	char	**ret;
	char	**tmp;

	tmp = evs;
	i = 0;
	k = -1;
	i = env_count(evs, arg);
	ret = malloc((sizeof(char *)) * (i + 1));
	i = 0;
	while (evs[++k])
	{
		j = 0;
		while (evs[k][j] && evs[k][j] != '=')
			j++;
		if (ft_strncmp(evs[k], arg, j + 1) != '=' && \
		!(!ft_strncmp(evs[k], arg, j) && !arg[j] && !evs[k][j]))
			ret[i++] = ft_strdup(evs[k]);
	}
	ret[i] = NULL;
	path_free(tmp);
	return (ret);
}

int	cmd_unset(t_shell *mini)
{
	int	i;

	i = 1;
	if (mini->args[1] == NULL)
		return (0);
	while (mini->args[i] != NULL)
		mini->c_evs = rm_env(mini->c_evs, mini->args[i++]);
	return (0);
}
