/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:07:44 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/10 08:39:27 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_to_save(t_stack *stackA, int *lis, size_t biggest,
							int notover)
{
	size_t			i;
	size_t			v;

	while (--notover > 0)
	{
		i = -1;
		v = 0;
		while (++i < biggest)
		{
			if (lis[i] > lis[v])
			{
				if (lis[i] <= notover)
					v = i;
			}
			else if (lis[i] == lis[v])
				if (stackA->tab[i] < stackA->tab[v])
					if (lis[i] <= notover)
						v = i;
		}
		lis[v] = -1;
		biggest = v;
	}
}

static void	push_to_b(int *lis, int k, t_stack *stackA, t_stack *stackB)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	lis_to_save(stackA, lis, k + 1, lis[k]);
	tmp = stackA->size;
	lis[k] = -1;
	while (i < tmp)
	{
		if (lis[i] == -1)
			push_ra(stackA);
		else
			push_pb(stackA, stackB);
		i++;
	}
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
