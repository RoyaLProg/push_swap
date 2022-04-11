/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:52:29 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/09 13:40:30 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_stack *stackA, t_stack *stackB)
{
	size_t	i;

	i = 0;
	case_less100(stackA, stackB);
	while (i < stackA->size)
	{
		printf("%d, ", stackA->tab[i]);
		i++;
	}
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
