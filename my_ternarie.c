/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ternarie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 03:06:51 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/10 03:09:22 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	my_ternarie(char condition, size_t true_value, size_t false_value)
{
	if (condition)
		return (true_value);
	return (false_value);
}
