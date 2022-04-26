/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:17:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/26 16:23:41 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_px(t_stack *stack_dst, t_stack *stack_src)
{
	int		*ntab_dst;
	int		*ntab_src;
	size_t	i;

	i = 0;
	if (stack_src->size == 0)
		return ;
	ntab_dst = malloc(sizeof(int) * (stack_dst->size + 2));
	ntab_src = malloc(sizeof(int) * (stack_src->size));
	if (ntab_src == NULL || ntab_src == NULL)
		return ;
	ntab_dst[0] = stack_src->tab[0];
	while (++i < stack_dst->size)
		ntab_dst[i] = stack_dst->tab[i - 1];
	i = 0;
	while (++i < stack_src->size)
		ntab_src[i] = stack_src->tab[i - 1];
	free(stack_dst->tab);
	free(stack_src->tab);
	stack_dst->tab = ntab_dst;
	stack_src->tab = ntab_src;
	stack_dst->size++;
	stack_src->size--;
}

void	push_pa(t_stack *stacka, t_stack *stackb)
{
	write(1, "pa\n", 3);
	push_px(stackb, stacka);
}

void	push_pb(t_stack *stacka, t_stack *stackb)
{
	write(1, "pb\n", 3);
	push_px(stacka, stackb);
}
