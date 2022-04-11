/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:28:06 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/09 00:45:35 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*push_rrx(t_stack *stack)
{
	int		temp;
	int		*tab;
	size_t	i;	
	size_t	size;

	size = stack->size;
	tab = stack->tab;
	if (size < 2)
		return (stack);
	temp = tab[size - 1];
	i = size;
	while (--i > 0)
		tab[i] = tab[i - 1];
	tab[0] = temp;
	return (stack);
}

t_stack	*push_rra(t_stack *stack)
{
	write(1, "rra\n", 4);
	return (push_rrx(stack));
}

t_stack	*push_rrb(t_stack *stack)
{
	write(1, "rrb\n", 4);
	return (push_rrx(stack));
}

void	push_rrr(t_stack *stackA, t_stack *stackB)
{
	write(1, "rrr\n", 4);
	push_rrx(stackA);
	push_rrx(stackB);
	return ;
}
