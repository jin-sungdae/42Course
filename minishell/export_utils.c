/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 02:39:09 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/26 02:39:10 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_equal_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

int	swap_envp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i])
		i++;
	if (str1[i] > str2[i])
		return (1);
	return (0);
}

void	swap_cha(char **desen_envp, int i, int j)
{
	char	*tmp;

	tmp = desen_envp[i];
	desen_envp[i] = desen_envp[j];
	desen_envp[j] = tmp;
}

char	*equal_back(char *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	tmp = ft_substr(env, 0, i);
	return (tmp);
}

void	envp_strdup(char **envp, char **env, char *new_env, int j)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (env[++i])
		if (i != j)
			envp[k++] = ft_strdup(env[i]);
	envp[k] = ft_strdup(new_env);
	envp[++k] = NULL;
}
