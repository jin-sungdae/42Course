#include "minishell.h"

int	exec_cmp(t_shell *mini, char **args, t_list *list)
{
	mini->args = args;
	if (mini->args == NULL)
		return (0);
	if (ft_strcmp(args[0], "exit") == 0)
	{
		if (mini->pipe_chk == 1)
			return (0);
		ft_putstr_fd("exit\n", 2);
		return (-1);
	}
	if (exec_cmp_norm(mini, args, list) != 100)
		return (0);
	run_cmd2(mini, mini->c_evs);
	ft_close(((t_ops *)(list->content))->fds[0]);
	ft_close(mini->pipe[1]);
	ft_close(mini->pipe[0]);
	ft_close(mini->prev_pipe);
	mini->pipe[0] = -1;
	mini->pipe[1] = -1;
	mini->prev_pipe = -1;
	return (0);
}

int	run_cmd1(t_shell *mini, t_list *list)
{
	int		i;

	i = 0;
	while (mini->count > 1)
	{
		mini->here_ck = 0;
		mini->args = ((t_ops *)(list->content))->args;
		dup2(mini->prev_pipe, STDIN_FILENO);
		if (ft_strchr("|<>{}", ((t_ops *)(list->content))->type))
		{
			operator_exec(list, mini);
			if (((t_ops *)(list->content))->type != '|')
				list = list->next;
		}
		list_jmp(mini, &list);
		mini->count = ft_lstsize(list);
	}
	if (list && mini->count)
	{
		dup2(mini->prev_pipe, STDIN_FILENO);
		i = exec_cmp(mini, ((t_ops *)(list->content))->args, list);
		if (i == -1)
			return (-1);
	}
	return (0);
}
