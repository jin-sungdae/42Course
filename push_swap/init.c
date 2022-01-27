/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:31:10 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 20:56:03 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int argc, char **argv)
{
	t_stack	stack;
	int		num_check;

	num_check = 0;
	stack.a = get_stack(argv, &argc, &num_check);
	if (!(stack.a))
	{
		ft_putstr_fd("error\n", 1);
		exit(1);
	}
	stack.b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!(stack.b))
	{
		free(stack.a);
		ft_putstr_fd("error\n", 1);
		exit(1);
	}
	stack.alen = num_check;
	stack.blen = 0;
	return (stack);
}

int	test_function(char *test, int *i)
{
	int			sign;
	long long	number;

	number = 0;
	sign = 1;
	while (test[*i] != '\0' && (test[*i] == ' ' || test[*i] == '\n'
			|| test[*i] == '\t' || test[*i] == '\r' || test[*i] == '\v'
			|| test[*i] == '\f'))
		*i += 1;
	if (test[*i] == '-' || test[*i] == '+')
	{
		if (test[*i] == '-')
			sign = -1;
		*i += 1;
	}
	while (test[*i] != '\0' && test[*i] >= '0' && test[*i] <= '9')
	{
		number *= 10;
		number += test[*i] - '0';
		*i += 1;
	}
	if (*i > 19 || !(number <= 2147483657 && number >= -2147483658))
		return (0);
	return (number * sign);
}

int	check_over_num(char **num, int *len, int *num_check)
{
	int	i;
	int	j;
	int	check;

	j = 0;
	i = 1;
	check = 0;
	while (i < *len)
	{
		j = 0;
		while (num[i][j])
		{
			check = 0;
			if (!test_function(&num[i][j], &check) && num[i][j] != '0')
				return (0);
			*num_check += 1;
			j += check;
			while (num[i][j] != '\0' && (num[i][j] == ' ' || num[i][j] == '\n'
				|| num[i][j] == '\t' || num[i][j] == '\r' || num[i][j] == '\v'
				|| num[i][j] == '\f'))
				j++;
		}
		i++;
	}
	return (1);
}

void	init_tt(t_vt *t)
{
	t->i = 1;
	t->j = 0;
	t->check = 0;

}

int	*get_stack(char **num, int *len, int *num_check)
{
	int		*res;
	t_vt	t;

	init_tt(&t);
	if (!check_over_num(num, len, num_check))
		return (0);
	res = res_make(num_check);
	while (t.i < *len)
    {
		while (num[t.i][t.j])
		{
			t.check = 0;
			res[*num_check] = test_function(&num[t.i][t.j], &t.check);
			*num_check += 1;
			t.j += t.check;
			while (num[t.i][t.j] != '\0' && (num[t.i][t.j] == ' ' || num[t.i][t.j] == '\n'
				|| num[t.i][t.j] == '\t' || num[t.i][t.j] == '\r' || num[t.i][t.j] == '\v'
				|| num[t.i][t.j] == '\f'))
				t.j++;
		}
		t.j = 0;
		t.i++;
    }
	return (res);
}
