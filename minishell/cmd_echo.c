/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:38:16 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/25 03:38:17 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo1(char **str, int i)
{
	int	j;

	j = -1;
	while (str[i][++j])
		ft_putchar_fd(str[i][j], 1);
}

int	cmd_echo(t_list *list, char **args)
{
	int	n_flag;
	int	i;

	i = 1;
	(void)list;
	if (!args[1])
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	n_flag = 0;
	if (args[i][0] == '-' && args[i][1] == 'n' && args[i][2] == '\0')
		n_flag++;
	while (args[i][0] == '-' && args[i][1] == 'n' && args[i][2] == '\0')
		i++;
	while (args[i])
	{
		print_echo1(args, i);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (n_flag == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
