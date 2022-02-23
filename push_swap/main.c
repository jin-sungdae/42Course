/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:30:54 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 19:54:48 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_stack(t_stack stack)
{
	free(stack.a);
	free(stack.b);
}

int	check_error(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->alen)
	{
		j = i + 1;
		while (j < stack->alen)
		{
			if (stack->a[i] == stack->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc <= 1)
		return (0);
	stack = init_stack(argc, argv);
	if (!check_error(&stack))
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	if (!a_to_b(&stack, stack.alen))
		delete_stack(stack);
	delete_stack(stack);
	return (0);
}
