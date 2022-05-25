/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:29:13 by ccambium          #+#    #+#             */
/*   Updated: 2022/05/25 04:40:46 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_lis(size_t	size)
{
	int		*lis;
	size_t	i;

	lis = malloc(sizeof(int) * size);
	if (lis == NULL)
		return (lis);
	i = -1;
	while (++i < size)
		lis[i] = 1;
	return (lis);
}
