/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:52:29 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/26 16:05:48 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_stack *stackA, t_stack *stackB)
{
	if (stackA->size == 2)
		case2(stackA);
	else if (stackA->size == 3)
		case3(stackA, stackB);
	else
		return ;
	free(stackA->tab);
}

int	main(int ac, char **av)
{
	t_stack	stacka;
	t_stack	stackb;

	stacka.size = 0;
	stackb.size = 0;
	if (ac == 1)
		return (write(1, "\n", 1));
	if (!verification(av, ac))
		return (write(1, "Error\n", 6));
	add_to_list(&stacka, ac, av);
	push_swap(&stacka, &stackb);
}
