/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:33:27 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 19:46:10 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	ft_putstr_fd("sa\n", 1);
	if (!(stack->a))
		return ;
	if (stack->alen > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
}

void	sb(t_stack *stack)
{
	int	tmp;

	ft_putstr_fd("sb\n", 1);
	if (!(stack->b))
		return ;
	if (stack->blen > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
}

void	ss(t_stack *stack)
{
	ft_putstr_fd("ss\n", 1);
	sa(stack);
	sb(stack);
}

void	pa(t_stack *stack)
{
	int	i;

	ft_putstr_fd("pa\n", 1);
	if (stack->blen)
	{
		stack->alen++;
		i = stack->alen;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->blen--;
		while (++i < stack->blen)
			stack->b[i] = stack->b[i + 1];
	}
}

void	pb(t_stack *stack)
{
	int	i;

	ft_putstr_fd("pb\n", 1);
	if (stack->alen)
	{
		stack->blen++;
		i = stack->blen;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->alen--;
		while (++i < stack->alen)
			stack->a[i] = stack->a[i + 1];
	}
}
