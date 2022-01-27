/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_del_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:27:00 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/31 14:27:01 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_chk(t_shell *mini, char *tmp)
{
	int		j;

	j = -1;
	(void)mini;
	if (tmp[0] == '$' && !tmp[1])
		return (0);
	while (tmp[++j])
		if (tmp[j] == '$')
			return (1);
	return (0);
}

int	env_len(char *env)
{
	int	i;

	i = 0;
	if (env[i] == '$')
		i++;
	while (env[i] && ft_isalnum(env[i]))
		i++;
	if (env[i])
		i--;
	return (i);
}

char	*fstr_join(char **s1, char *s2)
{
	size_t	i;
	size_t	l;
	char	*a;

	a = (char *)malloc(ft_strlen(*s1) + 2);
	if (!a)
		return (NULL);
	i = -1;
	l = 0;
	while ((*s1)[++i])
		a[i] = (*s1)[i];
	if (s2[l])
		a[i++] = s2[l++];
	a[i] = '\0';
	free(*s1);
	return (a);
}

void	fr_jplus(char **tmp, char **sub, char **tm2, int *j)
{
	if ((*tmp)[*j])
		(*j)++;
	if (*sub)
		free(*sub);
	if (*tm2)
		free(*tm2);
}

void	fr_dup(char **tmp, char **tm2, char **tm, int chk)
{
	if (chk)
	{
		free(*tmp);
		*tmp = ft_strdup(*tm2);
		free(*tm2);
	}
	free(*tm);
}
