/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalculate_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:35:11 by ccambium          #+#    #+#             */
/*   Updated: 2022/05/25 04:41:01 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	recalculate_index(long int index, long int offset, size_t size)
{
	index += offset;
	if (index < 0)
		index = size - 1 + index;
	else if ((size_t)index >= size)
		index -= size;
	return (index);
}
