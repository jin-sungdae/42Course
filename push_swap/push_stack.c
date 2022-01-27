/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:33:37 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 20:55:56 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*res_make(int *num_check)
{
	int	*res;

	res = (int *)malloc(sizeof(int) * (*num_check));
	if (!res)
		return (0);
	*num_check = 0;
	return (res);
}

void	init_v(t_v *v)
{
	v->pivot = 0;
	v->ra_num = 0;
	v->rb_num = 0;
	v->nb_len = 0;
}

int	a_to_b(t_stack *stack, int len)
{
	t_v	v;

	init_v(&v);
	if (sorted(stack->a, len, 1))
		return (1);
	v.nb_len = len;
	if (v.nb_len && stack->alen <= 3)
	{
		sorted3(stack, stack->alen);
		return (1);
	}
	if (!(v.ra_num) && !get_pivot(&v.pivot, stack->a, len))
		return (0);
	while (len != v.nb_len / 2 + v.nb_len % 2)
	{
		if (stack->a[0] < v.pivot && (len--))
			pb(stack);
		else if (++v.ra_num)
			ra(stack);
	}
	while (v.nb_len / 2 + v.nb_len % 2 != stack->alen && v.ra_num--)
		rra(stack);
	a_to_b(stack, v.nb_len / 2 + v.nb_len % 2);
	b_to_a(stack, v.nb_len / 2);
	return (1);
}

int	b_to_a(t_stack *stack, int len)
{
	t_v	v;

	init_v(&v);
	if (!(v.rb_num) && sorted(stack->b, len, 0))
		while (len--)
			pa(stack);
	v.nb_len = len;
	if (v.nb_len && !get_pivot(&v.pivot, stack->b, len))
		return (0);
	while (len != v.nb_len / 2)
	{	
		if (stack->b[0] >= v.pivot && len--)
			pa(stack);
		else if (++v.rb_num)
			rb(stack);
	}
	while (v.nb_len / 2 != stack->blen && v.rb_num--)
		rrb(stack);
	a_to_b(stack, v.nb_len / 2 + v.nb_len % 2);
	b_to_a(stack, v.nb_len / 2);
	return (1);
}
