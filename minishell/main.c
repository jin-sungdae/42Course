#include "minishell.h"

char	*get_cmd(int ac, char **av)
{
	int		i;
	char	*cmd;

	(void)ac;
	(void)av;
	i = 0;
	cmd = readline("\033[1;32mminishell$ \033[0m");
	if (!cmd)
	{
		printf("\x1b[2A");
		printf("\x1b[11C");
		printf("exit");
		exit_shell();
	}
	return (cmd);
}

int	main_norm(t_shell *mini, t_list *list)
{
	mini_c_p(mini, list);
	restore_term(mini);
	return (run_cmd1(mini, list));
}
// -----

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	int		i;
	t_shell	mini;
	t_list	*list;

	init_term_env(&mini, envp);
	reset_fds(&mini);
	while (1)
	{
		signal(SIGINT, &sighandler1);
		signal(SIGQUIT, SIG_IGN);
		tcsetattr(STDIN_FILENO, TCSANOW, &mini.term);
		cmd = get_cmd(ac, av);
		if (*cmd)
			add_history(rl_line_buffer);
		list = parse_option(&mini, &cmd);
		i = main_norm(&mini, list);
		free_all(list, &cmd);
		full_reset(&mini);
		if (i == -1)
			break ;
	}
}
