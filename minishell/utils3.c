/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:17:06 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 13:35:24 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	all_fr(char **env, char **tmp)
{
	path_free(env);
	free(*tmp);
}

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}
