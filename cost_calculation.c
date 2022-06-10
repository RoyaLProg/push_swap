/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:49:08 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/10 09:12:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(int **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_tab(int **tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 6)
			tab[i][j] = 0;
	}
}

/*
	* ra rb rr rra rrb rrr
	Le tableau suivant est constitué de chaque coup a effectuer dans la stack A 
	pour le deplacer à la bonne position dans la stack B

	! ne pas oubliez de rajouter + 1 (meme si useless)
	* COST CALCULATION

	* @param size : taille de la stack A
*/

static int	**create_cost_tab(size_t size)
{
	int		**v;
	size_t	i;

	i = -1;
	v = (int **)malloc(sizeof(int *) * (size + 1));
	if (v == NULL)
		return (v);
	while (++i < size)
	{
		v[i] = (int *)malloc(sizeof(int) * 6 + 1);
		if (v[i] == NULL)
		{
			free_tab(v);
			return (NULL);
		}
	}
	init_tab(v, size);
	v[size] = NULL;
	return (v);
}

static int	*calculate_cost(t_stack *stackA, t_stack *stackB,
						size_t x, int *cost)
{
	if (x >= stackB->size / 2)
		cost[4] += stackB->size - x;
	else
		cost[1] += x;
	if (stackA->size < 2)
		return (cost);
	get_a_movement(cost, x, stackA, stackB);
	optimize_cost(cost);
	return (cost);
}

int	**get_cost_tab(t_stack *stackA, t_stack *stackB)
{
	int		**cost_tab;
	size_t	i;

	cost_tab = create_cost_tab(stackB->size);
	if (cost_tab == NULL)
		return (NULL);
	i = -1;
	while (++i < stackB->size)
		cost_tab[i] = calculate_cost(stackA, stackB, i, cost_tab[i]);
	return (cost_tab);
}
