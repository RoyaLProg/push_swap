/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:13:40 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/06 12:05:19 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack{
	size_t	size;
	int		*tab;
}	t_stack;

t_stack			*push_sa(t_stack *stack);
t_stack			*push_sb(t_stack *stack);
void			push_ss(t_stack *stackA, t_stack *stackB);
void			push_pa(t_stack *stackA, t_stack *stackB);
void			push_pb(t_stack *stackA, t_stack *stackB);
t_stack			*push_ra(t_stack *stack);
t_stack			*push_rb(t_stack *stack);
void			push_rr(t_stack *stackA, t_stack *stackB);
t_stack			*push_rra(t_stack *stack);
t_stack			*push_rrb(t_stack *stack);
void			push_rrr(t_stack *stackA, t_stack *stackB);
void			*ft_calloc(size_t nmemb, size_t size);
long int		ft_atol(const char *nptr);
long long int	ft_atoll(const char *nptr);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
void			add_to_list(t_stack *a, int ac, char **av);
int				verification(char **argv, int argc);
void			ft_bzero(void *s, size_t n);
int				is_sorted(t_stack *stackA, t_stack *stackB);
void			case2(t_stack *stackA);
void			case3(t_stack *stackA, t_stack *stackB);
size_t			ft_strlen(const char *s);
void			case4to45(t_stack *stackA, t_stack *stackB);
int				ft_max(int x, int y);
int				ft_min(int x, int y);
void			caseover45(t_stack *stackA, t_stack *stackB);
void			lis_and_push(t_stack *stackA, t_stack *stackB);
int				*create_lis(size_t	size);
void			optimize_cost(int *cost);
long int		recalculate_index(long int index, long int offset,
					size_t size);
size_t			get_lower_cost_index(int **cost_tab, size_t size);
int				**get_cost_tab(t_stack *stackA, t_stack *stackB);
void			free_tab(int **tab);

#endif
