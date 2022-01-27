#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include "libft/libft.h"

typedef struct s_ef{
	size_t	row;
	size_t	i;
}				t_ef;

// ---

typedef struct s_ops
{
	char			*operation;
	char			**args;
	int				in_quotes;
	int				rv;
	char			type;
	int				fds[2];
	char			q;
	struct s_ops	*next;
	struct s_ops	*prev;
}					t_ops;

typedef struct s_shell
{
	t_list			*ops;
	char			**args;
	char			**heredoc_name;
	char			**asd;
	char			**c_evs;
	char			*q_c;
	int				rv;
	int				fds[2];
	int				prev_pipe;
	int				pipe[2];
	int				count;
	int				in;
	int				out;
	int				minipid;
	int				pipe_chk;
	struct termios	term;
	struct termios	t_sv;
	int				i;
	int				here_ck;
}					t_shell;

//---- main.c ---//
int		cmd_export(t_shell *mini, char **args, t_list *list);
int		cmd_env(char **args, t_shell *mini, t_list *list);
char	**plus_line(char **env, char *new_env);
int		print_export(char *str, char **envp);

char	**ft_split2(char *s, char c);
size_t	ft_strlcpy_new_str1(char *dst, char const *src, size_t size);
size_t	find_column(char const *s, char c);
char	**malloc_free(char **new_str);
int		find_new_column(const char *str);
int		check_row(char *str, char c);

void	plus_i(char *str, t_ef *ef);
void	plus_row(char *str, t_ef *ef, char c);
void	ef_init(t_ef *ef);

void	path_free(char **str);
int		is_quotes(char c);

void	free_all(t_list *list, char **cmd);

// - utils.c
char	*get_env(char **envp, char *option);
void	exit_shell(void);
void	reset_fds(t_shell *mini);
void	mini_c_p(t_shell *mini, t_list *list);
void	list_jmp(t_shell *mini, t_list **list);
void	free_list(t_list **list);
char	*pipe_join(char **s1, char *s2);
void	all_fr(char **env, char **tmp);
void	ft_close(int fd);
void	full_reset(t_shell *mini);

// ------ signal.c -----//

void	sighandler1(int sig);
void	sighandler2(int sig);
void	pipe_sighandler1(int sig);
void	pipe_sighandler2(int sig);

// ----- parse.c ---- //
char	**list_to_arr(t_list *list);
t_list	*parse(t_shell *mini, char *cmd);
t_ops	*set_ops(char *cmd, int i);
char	**parse_args(char *line, t_ops *ops);
char	*qskip_substr(char const *s, unsigned int start, size_t len);
// ----- parse2.c ---- //
int		first_oper(t_list **list, char *cmd);
t_list	*qq1(t_list *list, char *cmd, char *ftmp);
void	qq(t_shell *mini, char **command, char **cmd);
t_list	*parse_option(t_shell *mini, char **command);
void	add_back(t_list **list, t_ops *ops, char **line, int i);
// ----- parse3.c ---- //
char	*cmd_change(t_shell *mini, char **in);
int		repl_env(int i, char **in, t_shell *mini);
int		repl_env_name(char *in, int i, char **env, char **val);
int		max(int a, int b);
char	*repl_change(char *in, int i, int len, char *val);

// ----- parse4.c ---- //
t_ops	*set_ops(char *cmd, int i);
// ----- run_cmd.c --- //
int		run_cmd1(t_shell *mini, t_list *list);
int		exec_cmp(t_shell *mini, char **args, t_list *list);
//------ run_cmd2.c ----//
void	cmd_exec(char *path, t_shell *mini);
void	bin_chk(t_shell *mini);
void	put_err_msg(char *msg, int chk, char **path);
int		run_cmd2(t_shell *mini, char **envp);
int		exec_cmp_norm(t_shell *mini, char **args, t_list *list);

// ----- operator.c ---//
int		redirect_input(t_list *list, t_shell *shell);
int		append_output(t_list *list, t_shell *shell);
int		redirect_output(t_list *list, t_shell *shell);
int		operator_pipe(t_list *list, t_shell *mini);
int		append_input(t_shell *mini, t_list *list);
void	make_heredoc(t_shell *mini, t_list *list);

// ---- term.c ---//
void	init_term_env(t_shell *mini, char **envp);
void	restore_term(t_shell *mini);

// --- cmd_unset.c --//
int		cmd_unset(t_shell *mini);

// --- cmd_cd.c -- //
int		cmd_cd(char **args, t_shell *mini);

// -- cmd_echo.c
int		cmd_echo(t_list *list, char **args);
// -- cmd_pwd.c
int		cmd_pwd(char **args);
// -- parse_utils.c
int		add_list(t_list **list, char *cmd, int i);
int		cmd_chk(char **cmd);
int		quote_skip(char *cmd, int i, char q, t_ops *ops);
int		line_chk(char *line, int i);
int		oper_err_msg(char **cmd, int i);
// -- 2
int		i_jump(char *line);
void	cmd_jump(char **cmd, int *i);
int		quote_skip(char *cmd, int i, char q, t_ops *ops);
int		q_count(char **cmd);

// -- export_utils.c
int		check_equal_len(char *str);
int		swap_envp(char *str1, char *str2);
void	swap_cha(char **desen_envp, int i, int j);
char	*equal_back(char *env);
void	envp_strdup(char **envp, char **env, char *new_env, int j);
void	heredoc_chk(t_list *list, t_shell *mini);
void	oper_norm(t_shell *mini, t_list **tlist, int *i);

// --- multi_oper.c
int		operator_exec1(t_list *list, t_shell *mini);
int		multi_oper(t_list *list, t_shell *mini);
void	operator_exec(t_list *list, t_shell *mini);
// --- multi_oper_utils.c
int		multi_chk1(t_shell *mini, t_list *list);
int		multi_chk2(t_shell *mini, t_list *list);
int		input_num(t_list *list);
void	heredoc_count(t_list *list, int *here);
void	m_chk(t_list *list, t_shell *mini);

// --- q_del.c
int		q_chk(t_shell *mini, t_list *list);
// --- q_del_utils.c
int		env_chk(t_shell *mini, char *tmp);
int		env_len(char *env);
char	*fstr_join(char **s1, char *s2);
void	fr_jplus(char **tmp, char **sub, char **tm2, int *j);
void	fr_dup(char **tmp, char **tm2, char **tm, int chk);
#endif