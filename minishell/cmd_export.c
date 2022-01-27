/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:47:23 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 14:28:07 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**plus_line(char **env, char *new_env)
{
	char	**envp;
	char	*tmp;
	char	*equl;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (new_env[i] && new_env[i] != '=')
		i++;
	tmp = ft_substr(new_env, 0, i);
	i = -1;
	while (env[++i])
	{
		equl = equal_back(env[i]);
		if (!ft_strcmp(tmp, equl))
			j = i;
		free(equl);
	}
	if (j != -1)
		i--;
	envp = (char **)malloc(sizeof(char *) * (i + 2));
	envp_strdup(envp, env, new_env, j);
	all_fr(env, &tmp);
	return (envp);
}

char	**desending_envp(char **envp)
{
	char	**desen_envp;
	int		i;
	int		j;

	i = 0;
	while (envp[i])
		i++;
	desen_envp = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i])
		desen_envp[i] = ft_strdup(envp[i]);
	desen_envp[i] = NULL;
	i = -1;
	while (desen_envp[++i])
	{
		j = i;
		while (desen_envp[++j])
		{
			if (swap_envp(desen_envp[i], desen_envp[j]))
				swap_cha(desen_envp, i, j);
		}
	}
	path_free(envp);
	return (desen_envp);
}

void	print_ex(t_shell *mini)
{
	int	i;
	int	j;
	int	q_flag;

	i = -1;
	while (mini->c_evs[++i])
	{
		j = -1;
		q_flag = 0;
		printf("declare -x ");
		while (mini->c_evs[i][++j])
		{
			printf("%c", mini->c_evs[i][j]);
			if (mini->c_evs[i][j] == '=')
			{
				printf("\"");
				q_flag = 1;
			}
		}
		if (q_flag)
			printf("\"");
		printf("\n");
	}
}

int	dol_chk(char *line)
{
	int	i;

	i = 7;
	while (line[i] && line[i] == '$')
	{
		if (line[i] == '$' && line[i + 1])
			return (2);
		if (line[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	cmd_export(t_shell *mini, char **args, t_list *list)
{
	int		i;
	char	*line;

	i = 0;
	line = ((t_ops *)(list->content))->operation;
	mini->c_evs = desending_envp(mini->c_evs);
	if (!(ft_strcmp(args[0], "export")) && !args[1])
		print_ex(mini);
	else
		while (args[++i])
			mini->c_evs = plus_line(mini->c_evs, args[i]);
	return (0);
}
