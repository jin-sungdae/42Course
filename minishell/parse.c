/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 03:15:45 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 13:54:54 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_arr(t_list *list)
{
	int		size;
	int		i;
	t_list	*lst;
	char	**arr;

	if (!list)
		return (NULL);
	lst = list;
	size = ft_lstsize(list);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		arr[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	arr[size] = NULL;
	ft_lstclear(&list, &free);
	return (arr);
}

char	*q_nomsg(char const *s)
{
	char	*new;
	char	q;

	if (s[0] == '\'' || s[0] == '\"')
	{
		q = s[0];
		if (s[1] == q && !s[2])
		{
			new = (char *)malloc(sizeof(char) * 1);
			new[0] = '\0';
			return (new);
		}
	}
	return (NULL);
}

char	*qskip_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	new = q_nomsg(s);
	if (s == 0)
		return (NULL);
	while (s[++j])
		if (s[j] != '\'' && s[j] != '\"')
			i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	j = start;
	while (s[j] && j < start + len)
	{
		if (s[j] != '\'' && s[j] != '\"')
			new[i++] = s[j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	**parse_args(char *line, t_ops *ops)
{
	t_list	*list;
	int		i;

	i = -1;
	list = NULL;
	while (line[++i])
	{
		ops->in_quotes = 0;
		while (line[i] == ' ')
			i++;
		while (*line == ' ')
			line++;
		if (!line[0])
			break ;
		if (1)
		{
			add_back(&list, ops, &line, i);
			i = -1;
		}
	}
	return (list_to_arr(list));
}
