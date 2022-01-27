/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:33:05 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 19:48:26 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	tmp;

	ft_putstr_fd("ra\n", 1);
	if (stack->alen > 1)
	{
		tmp = stack->a[0];
		i = -1;
		while (++i < stack->alen - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[stack->alen - 1] = tmp;
	}
}

void	rb(t_stack *stack)
{
	int	i;
	int	tmp;

	ft_putstr_fd("rb\n", 1);
	if (stack->blen > 1)
	{
		tmp = stack->b[0];
		i = -1;
		while (++i < stack->blen - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[stack->blen - 1] = tmp;
	}
}

void	rr(t_stack *stack)
{
	ft_putstr_fd("rr\n", 1);
	ra(stack);
	rb(stack);
}

void	rra(t_stack *stack)
{
	int	i;
	int	tmp;

	ft_putstr_fd("rra\n", 1);
	if (stack->alen > 1)
	{
		tmp = stack->a[stack->alen - 1];
		i = stack->alen;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = tmp;
	}
}

void	rrb(t_stack *stack)
{
	int	i;
	int	tmp;

	ft_putstr_fd("rrb\n", 1);
	if (stack->blen > 1)
	{
		tmp = stack->b[stack->blen - 1];
		i = stack->blen;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = tmp;
	}
}
