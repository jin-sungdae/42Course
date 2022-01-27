/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:31:18 by sjin              #+#    #+#             */
/*   Updated: 2021/08/02 19:49:56 by sjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	part(int *arr, int len)
{
	int	inf;
	int	isup;
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * len);
	inf = 0;
	isup = len - 1;
	i = -1;
	while (++i < len - 1)
	{
		if (arr[i] > arr[len - 1])
			tmp[isup--] = arr[i];
		else
			tmp[inf++] = arr[i];
	}
	tmp[inf] = arr[len - 1];
	i = -1;
	while (++i < len)
		arr[i] = tmp[i];
	free(tmp);
	return (inf);
}

void	reg_quick_sort(int *arr, int len)
{
	int	i;

	if (len < 2)
		return ;
	i = part(arr, len);
	if (i)
		reg_quick_sort(arr, i);
	if (i != len - 1)
		reg_quick_sort(arr + i + 1, len - i - 1);
}

int	get_pivot(int *pivot, int *stack, int len)
{
	int	*rst;
	int	i;

	rst = (int *)malloc(sizeof(int) * len);
	if (!rst)
		return (0);
	i = -1;
	while (++i < len)
		rst[i] = stack[i];
	reg_quick_sort(rst, len);
	*pivot = rst[len / 2];
	free(rst);
	return (1);
}
