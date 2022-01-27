/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:21:04 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 14:19:00 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quotes(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

void	path_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			if (str[i])
				free(str[i++]);
		free(str);
	}
}

void	free_all(t_list *list, char **cmd)
{
	t_list	*tlist;
	int		i;

	if (*cmd)
		free(*cmd);
	i = 0;
	if (list == NULL)
		return ;
	tlist = list;
	while (tlist)
	{
		if (((t_ops *)(tlist->content))->args != NULL)
		{
			while (((t_ops *)(tlist->content))->args[i])
				free(((t_ops *)(tlist->content))->args[i++]);
			free(((t_ops *)(tlist->content))->args);
		}
		if (((t_ops *)(tlist->content))->operation)
			free(((t_ops *)(tlist->content))->operation);
		if (((t_ops *)(tlist->content)))
			free(((t_ops *)(tlist->content)));
		free(tlist);
		tlist = tlist->next;
		i = 0;
	}
}

char	*get_env(char **envp, char *option)
{
	int		i;
	int		j;
	char	find[30];
	char	*equl;

	i = 0;
	ft_strlcpy(find, option, 30);
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		equl = equal_back(envp[i]);
		if (ft_strcmp(find, equl) == 0)
		{
			free(equl);
			return (envp[i] + j + 1);
		}
		free(equl);
		++i;
	}
	return ("");
}

void	exit_shell(void)
{
	write(1, "\n", 1);
	exit(0);
}
