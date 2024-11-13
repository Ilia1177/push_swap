/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:18:29 by npolack           #+#    #+#             */
/*   Updated: 2024/10/31 14:37:12 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/srcs/include/libft.h"

// utils / basics / advenced
void	ft_lstprint(t_list *stack);
void	ft_lstinit(t_list **stack, char **av, int size, int flag);
void	swap(t_list **stack, int print);
void	swap_both(t_list **a, t_list **b);
void	push(t_list **a, t_list **b);
void	rotate(t_list **stack, int print);
void	rotate_both(t_list **a, t_list **b);
void	r_rotate(t_list **stack, int print);
void	push_last(t_list **a, t_list **b);
void	push_all(t_list **a, t_list **b);
void	push_back(t_list **a, t_list **b);
t_list	*get_min(t_list *stack);
t_list	*get_max(t_list *stack);
// sorting new;

int	is_sorted(t_list *stack, int size);
int	is_revsorted(t_list *stack, int size);
int	ft_lstcmp(t_list *a, t_list *b);
void	print_debug(t_list *a, t_list *b);
void	mixed_sort(t_list **a, t_list **b, int debug);
int		cmp_swap(t_list **a);
int get_index(t_list *target, t_list *stack);
int	min_move(t_list *stk, t_list *obj);
void	place_in_between(t_list **stk, t_list **obj);
int		check_pivot(t_list *stack, int index, int pivot);
void	bring_index_up(t_list **stk, int index);
void	make_run(t_list **a, t_list **b, int cursor,int debug);
void	sort_stack(t_list **a, t_list **b, int debug);
/* sorting save
int		ft_lstcmp(t_list *a, t_list *b);
int		is_sorted(t_list *stack, int size);
void	mixed_sort(t_list **a, t_list **b, int debug);
void	radix_sort(t_list **a, t_list **b);
void	print_debug(t_list *a, t_list *b);
void	sort_stack(t_list **a, t_list **b, int debug);
*/

// input
int		check_input(int ac, char **av, int flag);
int		*str_to_tab(int	*tab, char *str);
int		get_input(t_list **stack, int ac, char **av, int flag);
int		*sort_tab(int *tab, int size);
void	put_position(t_list *current, int *tab, int size);
int		make_list(t_list **stack, int size, char **av, int flag);
int		free_all(int *tab, char **strings, int size);
int		check_str(char *str);
int		check_args(int ac, char **av, int flag);
int		ft_isspace(int c);
#endif
