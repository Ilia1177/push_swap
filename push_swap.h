/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:18:29 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 17:26:16 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/srcs/include/libft.h"

typedef struct s_count
{
	int		counter;
	char	**instr;
}	t_count;

// utils / basics / advenced
void	ft_lstprint(t_list *stack);
int		ft_lstinit(t_list **stack, char **av, int size, int flag);
void	swap(t_list **stack, int print, t_count *cpt);
void	swap_both(t_list **a, t_list **b, t_count *cpt);
void	push(t_list **a, t_list **b, t_count *cpt, int print);
void	rotate(t_list **stack, int print, t_count *cpt);
void	rotate_both(t_list **a, t_list **b, t_count *cpt);
void	r_rotate(t_list **stack, int print, t_count *cpt);
void	push_last(t_list **a, t_list **b, t_count *cpt, int print);
void	push_all(t_list **a, t_list **b, t_count *cpt, int print);
void	push_back(t_list **a, t_list **b, t_count *cpt, int print);
t_list	*get_min(t_list *stack);
t_list	*get_max(t_list *stack);
// sorting new;

int		move_calc(int index, int size);
int		is_sorted(t_list *stack, int size);
int		is_revsorted(t_list *stack, int size);
int		ft_lstcmp(t_list *a, t_list *b);
void	print_debug(t_list *a, t_list *b, t_count *cpt);
void	mixed_sort(t_list **a, t_list **b, int debug, t_count *cpt);
int		get_index(t_list *target, t_list *stack);
int		min_move(t_list *stk, t_list *obj);
void	place_in_between(t_list **stk, t_list **obj, t_count *cpt, int print);
int		in_range(t_list *stack, int index, int pivot);
void	bring_index_up(t_list **stk, int index, t_count *cpt, int print);
void	make_run(t_list **a, t_list **b, int debug, t_count *cpt);
void	sort_stack(t_list **a, t_list **b, int debug, t_count *cpt);

// trim_instructions
int		trim_instr(t_count *cpt);
int		replace_r_rotate(t_count *cpt);
void	replace_instr(t_count *cpt, int to_delete, int i, char *new_instr);
int		replace_rotate(t_count *cpt);
void	check_n_replace_r(t_count *cpt, int	*i, int *to_delete, int *count);
void	check_n_replace_rr(t_count *cpt, int *i, int *to_delete, int *count);
int		is_target(char *target_a, char *target_b, char *current, char *todel);

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
int		make_list_from_str(t_list **stack, int size, char *str);

#endif
