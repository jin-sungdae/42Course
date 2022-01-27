#include "minishell.h"

char	*repl_change(char *in, int i, int len, char *val)
{
	char	*out;

	if (val)
	{
		out = malloc(ft_strlen(in) - len + ft_strlen(val) + 1);
		if (!out)
			return (NULL);
		ft_strlcpy(out, in, i + 1);
		ft_strlcpy(out + i, val, ft_strlen(val) + 1);
		ft_strlcpy(out + i + ft_strlen(val), in + i + len, \
			ft_strlen(in) - len - i + 1);
	}
	else
	{
		out = malloc(ft_strlen(in) - len);
		if (!out)
			return (NULL);
		ft_strlcpy(out, in, i + 1);
		ft_strlcpy(out + i, in + i + len, ft_strlen(in) - i - len + 1);
	}
	free(val);
	return (out);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	repl_env_name(char *in, int i, char **env, char **val)
{
	int		clip;
	int		j;
	int		k;
	char	*tkn;

	clip = 0;
	while (in[i + 1 + clip] && !ft_strchr(" \t$\"\'\\", in[i + 1 + clip]))
		clip++;
	tkn = in + i + 1;
	j = 0;
	while (env[j])
	{
		k = ft_strnstr(env[j], "=", ft_strlen(env[j])) - env[j];
		if (!ft_strncmp(env[j], tkn, max(clip, k)))
		{
			*val = ft_strdup(env[j] + k + 1);
			break ;
		}
		j++;
	}
	return (clip);
}

int	repl_env(int i, char **in, t_shell *mini)
{
	char	*val;
	char	*tmp;
	int		len;

	val = NULL;
	if ((*in)[i + 1] == '?')
	{
		tmp = repl_change(*in, i, 2, ft_itoa(mini->rv));
		free(*in);
		*in = tmp;
		return (1);
	}
	else
	{
		len = repl_env_name(*in, i, mini->c_evs, &val) + 1;
		tmp = repl_change(*in, i, len, val);
		free(*in);
		*in = tmp;
		if (!val)
			return (0);
		return (len);
	}
}

char	*cmd_change(t_shell *mini, char **in)
{
	int		i;
	char	inquotes;

	i = 0;
	inquotes = 0;
	while ((*in) && (*in)[i])
	{
		if ((*in)[i] == '\"' && (i == 0 || (i > 0 && (*in)[i - 1] != '\\')))
			inquotes = (inquotes + 1) % 2;
		if ((*in)[i] == '\'' && (i == 0 || (i > 0 && (*in)[i - 1] != '\\')) \
			&& !inquotes)
		{
			i++;
			while (!((*in)[i] == '\'' && (*in)[i - 1] != '\\'))
				i++;
		}
		if ((*in)[i] == '$' && (*in)[i + 1] && (*in)[i + 1] != '$')
			i += repl_env(i, in, mini) - 1;
		i++;
	}
	return (*in);
}
