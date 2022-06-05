/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:07:44 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/05 15:51:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack(t_stack *stackA, t_stack *dup)
{
	size_t	i;

	i = -1;
	dup->size = stackA->size;
	dup->tab = malloc(sizeof(int) * stackA->size);
	if (dup->tab == NULL)
		return ;
	while (++i < stackA->size)
		dup->tab[i] = stackA->tab[i];
}

static long int	next_to_push(t_stack *dupstackA, int *lis, long int biggest,
							int notover)
{
	long int	v;
	long int	i;

	i = 0;
	v = 0;
	while (i < biggest)
	{
		if (lis[i] > lis[v])
		{
			if (lis[i] <= notover)
				v = i;
		}
		else if (lis[i] == lis[v])
			if (dupstackA->tab[i] < dupstackA->tab[v])
				if (lis[i] <= notover)
					v = i;
		i++;
	}
	return (v);
}

static long int	push_to_top(t_stack *stackA, long int index, long int offset)
{
	size_t	i;

	i = -1;
	index = recalculate_index(index, offset, stackA->size);
	if (index == 0)
		return (offset);
	if ((size_t)index <= stackA->size / 2)
	{
		while (++i < (size_t)index)
		{
			push_ra(stackA);
			offset--;
		}
	}
	if ((size_t)index > stackA->size / 2)
	{
		while (++i < stackA->size - index)
		{
			push_rra(stackA);
			offset++;
		}
		offset -= 1;
	}
	return (offset);
}

static void	push_to_b(int *lis, int k, t_stack *stackA, t_stack *stackB)
{
	long int	max;
	long int	offset;
	t_stack		dupstacka;
	long int	ntp;

	offset = 0;
	max = lis[k];
	copy_stack(stackA, &dupstacka);
	ntp = k + 1;
	if (dupstacka.tab == NULL)
		return ;
	while (max > 0)
	{
		ntp = next_to_push (&dupstacka, lis, ntp, max);
		offset = push_to_top(stackA, ntp, offset);
		push_pb(stackA, stackB);
		max--;
	}
	free(dupstacka.tab);
}

void	lis_and_push(t_stack *stackA, t_stack *stackB)
{
	int		*lis;
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	lis = create_lis(stackA->size);
	if (lis == NULL)
		return ;
	while (++i < stackA->size)
	{
		j = -1;
		while (++j < i)
			if (stackA->tab[j] < stackA->tab[i])
				lis[i] = ft_max(lis[i], lis[j] + 1);
	}
	i = -1;
	k = 0;
	while (++i < stackA->size)
		if (lis[i] > k)
			k = i;
	push_to_b(lis, k, stackA, stackB);
	free(lis);
}
