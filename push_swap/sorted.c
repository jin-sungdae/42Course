/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:33:53 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 19:58:46 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(int *stack, int len, int check)
{
	int	i;

	i = -1;
	while (++i < len - 1)
		if ((check == 1 && stack[i] > stack[i + 1])
			|| (check == 0 && stack[i] < stack[i + 1]))
			return (0);
	return (1);
}

int	check_three_1(t_stack *stack, int i)
{
	if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1]
		> stack->a[i + 2] && stack->a[i] > stack->a[i + 2])
	{
		sa(stack);
		rra(stack);
		return (1);
	}
	else if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1]
		< stack->a[i + 2] && stack->a[i] > stack->a[i + 2])
	{
		ra(stack);
		return (1);
	}
	else if (stack->a[i] < stack->a[i + 1] && stack->a[i + 1]
		> stack->a[i + 2] && stack->a[i] > stack->a[i + 2])
	{
		rra(stack);
		return (1);
	}
	return (0);
}

int	check_three_2(t_stack *stack, int i)
{
	if (stack->a[i] > stack->a[i + 1] && stack->a[i + 1]
		< stack->a[i + 2] && stack->a[i] < stack->a[i + 2])
	{
		sa(stack);
		return (1);
	}
	else if (stack->a[i] < stack->a[i + 1] && stack->a[i + 1]
		> stack->a[i + 2] && stack->a[i] < stack->a[i + 2])
	{
		sa(stack);
		ra(stack);
		return (1);
	}
	return (0);
}

void	sorted3(t_stack *stack, int len)
{
	if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	if (len == 3)
	{
		if (check_three_1(stack, 0))
			return ;
		else if (check_three_2(stack, 0))
			return ;
	}
}
