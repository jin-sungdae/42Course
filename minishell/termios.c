/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 06:43:25 by sangcpar          #+#    #+#             */
/*   Updated: 2021/10/14 06:43:26 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**put_evs(t_shell *mini, char **envp)
{
	int		i;
	char	**ret;

	(void)mini;
	i = 0;
	while (envp[i])
		i++;
	ret = malloc((i + 1) * (sizeof(char *)));
	if (!ret)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		ret[i] = ft_strdup(envp[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	init_term_env(t_shell *mini, char **envp)
{
	mini->rv = 0;
	mini->c_evs = put_evs(mini, envp);
	mini->in = dup(STDIN_FILENO);
	mini->out = dup(STDOUT_FILENO);
	tcgetattr(STDIN_FILENO, &mini->t_sv);
	tcgetattr(STDIN_FILENO, &mini->term);
	mini->term.c_lflag &= ~ICANON;
	mini->term.c_lflag &= ~ECHOCTL;
	mini->term.c_cc[VMIN] = 1;
	mini->term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &mini->term);
}

//tgetent(NULL, "xterm");

void	restore_term(t_shell *mini)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &mini->t_sv);
}
