#include "minishell.h"

int	first_oper(t_list **list, char *cmd)
{
	t_ops	*ops;
	int		r;

	ops = (t_ops *)malloc(sizeof(t_ops));
	r = 0;
	if (ft_strchr("<>", cmd[1]))
	{
		r = 1;
		if (cmd[1] == '<')
			ops->type = '{';
		else
			ops->type = '}';
	}
	else
		ops->type = cmd[0];
	ops->operation = NULL;
	ops->args = NULL;
	ft_lstadd_back(list, ft_lstnew(ops));
	return (r);
}

t_list	*qq1(t_list *list, char *cmd, char *ftmp)
{
	int		i;
	t_ops	ops;

	i = -1;
	while (1)
	{
		if (cmd[++i] == '\'' || cmd[i] == '\"')
			i = quote_skip(cmd, i, cmd[i], &ops);
		else if (!cmd[i] || ft_strchr("|<>", cmd[i]))
		{
			if (add_list(&list, cmd, i))
				return (NULL);
			if (!cmd[i])
			{
				free(ftmp);
				return (list);
			}
			cmd_jump(&cmd, &i);
		}
	}
}

void	qq(t_shell *mini, char **command, char **cmd)
{
	*cmd = ft_strdup(*command);
	*cmd = cmd_change(mini, cmd);
}

t_list	*parse_option(t_shell *mini, char **command)
{
	t_list	*list;
	char	*cmd;
	char	*ftmp;

	list = NULL;
	if (cmd_chk(command))
		return (NULL);
	qq(mini, command, &cmd);
	if (!ft_strcmp(cmd, ""))
	{
		free(cmd);
		return (NULL);
	}
	ftmp = cmd;
	if (ft_strchr("|<>", cmd[0]))
	{
		if (first_oper(&list, cmd))
			cmd += 2;
		else
			cmd++;
	}
	list = qq1(list, cmd, ftmp);
	return (list);
}

void	add_back(t_list **list, t_ops *ops, char **line, int i)
{
	char	q;

	(void)ops;
	i = 0;
	while ((*line)[i] == ' ')
		i++;
	while ((*line)[i])
	{
		if ((*line)[i] == '\'' || (*line)[i] == '\"')
		{
			q = (*line)[i++];
			while ((*line)[i] != q)
				i++;
			i++;
		}
		else
			i++;
		if (!(*line)[i] || (*line)[i] == ' ')
			break ;
	}
	ft_lstadd_back(list, ft_lstnew(qskip_substr(*line, 0, i)));
	(*line) += i;
}
