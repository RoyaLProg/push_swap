/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:13:40 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/12 14:10:51 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef	t_stack;
struct	s_stack;

t_stack	push_sa(t_stack stack);
t_stack	push_sb(t_stack stack);
void	push_ss(t_stack stackA, t_stack stackB);
t_stack	push_ra(t_stack stack);
t_stack	push_rb(t_stack stack);
void	push_rr(t_stack stackA, t_stack stackB);
t_stack	push_rra(t_stack stack);
t_stack	push_rrb(t_stack stack);
void	push_rrr(t_stack stackA, t_stack stackB);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
