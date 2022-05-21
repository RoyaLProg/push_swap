/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:07:44 by ccambium          #+#    #+#             */
/*   Updated: 2022/05/21 04:46:05 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_and_push(t_stack *stackA, t_stack *stackB)
{
	int		*lis;
	size_t	i;
	size_t	j;
	size_t	k;

	lis = malloc(sizeof(int) * stackA->size);
	if (lis == NULL)
		return ;
	i = -1;
	while (++i < stackA->size)
		lis[i] = 1;
	i = 0;
	while (++i < stackA->size)
	{
		j = -1;
		while (++j < i)
			if (stackA->tab[j] < stackB->tab[i])
				lis[i] = ft_max(lis[i], lis[j] + 1);
	}
	i = -1;
	while (++i < stackA->size)
		if (lis[i] > k)
			k = i;
}

void	pushToTop(int k, int *lis)
{
	
}

void	push_to_b(int *lis, size_t k, t_stack *stackA, t_stack *stackB)
{
	size_t	i;
	size_t	j;
	int		max;
	int		offset;

	offset = 0;
	i = -1;
	max = stackA->tab[k];
	pushToTop();
}
