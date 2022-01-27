/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:23:59 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 18:58:31 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_sighandler1(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
}

void	pipe_sighandler2(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("^\\Quit: 3\n", 1);
		signal(SIGQUIT, &sighandler2);
	}
}

void	sighandler1(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		signal(SIGINT, &sighandler1);
	}
}

void	sighandler2(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("^C\n", 1);
		signal(SIGINT, &sighandler2);
	}
}
