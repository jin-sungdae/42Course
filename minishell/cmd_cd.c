/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:35:34 by sangcpar          #+#    #+#             */
/*   Updated: 2021/12/01 14:00:59 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(char *opt)
{
	char	buf[1000];
	char	*path;
	char	*temp;

	getcwd(buf, 1000);
	path = ft_strdup(buf);
	temp = ft_strjoin(opt, path, 5);
	free(path);
	return (temp);
}

char	*get_path(char **strs)
{
	if (!strs[1][1])
		return ("");
	else
		return (strs[1] + 1);
}

void	change_pwd(t_shell *mini, char **oldpwd)
{
	int		i;

	i = 0;
	while (ft_strncmp(mini->c_evs[i], "OLDPWD=", 7))
		i++;
	free(mini->c_evs[i]);
	mini->c_evs[i] = *oldpwd;
	i = 0;
	while (ft_strncmp(mini->c_evs[i], "PWD=", 4))
		i++;
	free(mini->c_evs[i]);
	mini->c_evs[i] = get_pwd("PWD=");
}

int	cd_norm(char **tilde_path, char **oldpwd)
{
	ft_putstr_fd(*tilde_path, 2);
	ft_putstr_fd(" :No such file or directory\n", 2);
	free(*oldpwd);
	free(*tilde_path);
	return (0);
}

int	cmd_cd(char **args, t_shell *mini)
{
	char	*oldpwd;
	char	*tilde_path;

	oldpwd = get_pwd("OLDPWD=");
	if (args[1][0] == '~')
	{
		tilde_path = ft_strjoin(get_env(mini->c_evs, "HOME"), \
		get_path(args), 4);
		if (chdir(tilde_path) == -1)
			return (cd_norm(&tilde_path, &oldpwd));
		free(tilde_path);
		change_pwd(mini, &oldpwd);
		return (0);
	}
	if ((chdir(args[1])) == -1)
	{
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(" :No such file or directory\n", 2);
		free(oldpwd);
		return (0);
	}
	change_pwd(mini, &oldpwd);
	return (0);
}
