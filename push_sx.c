/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:09:04 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/09 00:47:24 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*push_sx(t_stack *stack)
{
	int		temp;
	int		*tab;
	size_t	size;

	size = stack->size;
	tab = stack->tab;
	if (size < 2)
		return (stack);
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
	return (stack);
}

t_stack	*push_sa(t_stack *stack)
{
	write(1, "sa\n", 3);
	return (push_sx(stack));
}

t_stack	*push_sb(t_stack *stack)
{
	write(1, "sb\n", 3);
	return (push_sx(stack));
}

void	push_ss(t_stack *stackA, t_stack *stackB)
{
	write(1, "ss\n", 3);
	push_sx(stackA);
	push_sx(stackB);
	return ;
}
