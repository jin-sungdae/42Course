/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:40:42 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:43 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_equal(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	put_oneenv(char *evs, char *line, int *chk)
{
	int	j;

	j = 0;
	if (!ft_strncmp(line, evs, ft_strlen(line)))
	{
		*chk = 1;
		while (evs[j] != '=')
			j++;
		printf("%s\n", &evs[++j]);
	}
}

int	cmd_env(char **args, t_shell *mini, t_list *list)
{
	int		i;
	int		chk;

	i = 0;
	chk = 0;
	(void)list;
	if (!(ft_strcmp(args[0], "env")))
		while (mini->c_evs[i])
			printf("%s\n", mini->c_evs[i++]);
	return (1);
}
