/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:33:48 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 20:55:26 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	alen;
	int	blen;
}			t_stack;

typedef struct s_command
{
	void	(*command)(t_stack *);
	char	*commandstr;
}			t_command;

typedef struct s_v
{
	int	pivot;
	int	ra_num;
	int	rb_num;
	int	nb_len;
}			t_v;

typedef struct s_vt
{
	int	i;
	int	j;
	int check;
}			t_vt;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	reg_quick_sort(int *arr, int len);
void	sorted3(t_stack *stack, int len);
int		*res_make(int *num_check);
int		part(int *arr, int len);
int		get_pivot(int *pivot, int *stack, int len);
int		*get_stack(char **num, int *len, int *num_check);
int		a_to_b(t_stack *stack, int len);
int		b_to_a(t_stack *stack, int len);
int		sorted(int *stack, int len, int check);
int		check_three_1(t_stack *stack, int i);
int		check_three_2(t_stack *stack, int i);
t_stack	init_stack(int argc, char **argv);

#endif
