/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:36:21 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 15:47:36 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(t_list *stack, int lowlim, int hilim)
{
	int		i;
	int		closest_index;
	int		min_move;
	t_list	*curr;

	curr = stack;
	i = 0;
	closest_index = -1;
	min_move = ft_lstsize(stack);
	while (curr && ++i)
	{
		if (*(int *)curr->content >= lowlim && *(int *)curr->content <= hilim)
		{
			if (min_move > move_calc(i, ft_lstsize(stack)))
			{
				min_move = move_calc(i, ft_lstsize(stack));
				closest_index = i;
			}
		}
		if (!curr->next && closest_index != -1)
			return (closest_index);
		curr = curr->next;
	}
	return (0);
}

void	bring_index_up(t_list **stk, int index, t_count *cpt, int print)
{
	int	i;

	if (index > ft_lstsize(*stk) / 2)
		i = index - ft_lstsize(*stk);
	else
		i = index;
	while (i)
	{
		if (i < 0)
		{
			r_rotate(stk, print, cpt);
			i++;
		}
		else if (i > 0)
		{
			i--;
			rotate(stk, print, cpt);
		}
	}
}

void	make_run(t_list **a, t_list **b, int print, t_count *cpt)
{
	int		pivot;
	int		i;
	int		hlim;
	int		llim;
	int		cursor;

	if (ft_lstsize(*a) < 250)
		cursor = 5;
	else
		cursor = 13;
	pivot = ft_lstsize(*a) / cursor;
	i = -1;
	while (++i <= cursor)
	{
		hlim = (1 + i) * pivot;
		llim = i * pivot;
		while (in_range(*a, llim, hlim))
		{
			if (*(int *)(*a)->content >= llim && *(int *)(*a)->content <= hlim)
				place_in_between(b, a, cpt, print);
			else
				bring_index_up(a, in_range(*a, llim, hlim) - 1, cpt, print);
		}
	}
}

void	sort_stack(t_list **a, t_list **b, int print, t_count *cpt)
{
	int	size;

	size = ft_lstsize(*a);
	if (size < 50)
		mixed_sort(a, b, print, cpt);
	else
	{
		make_run(a, b, print, cpt);
		bring_index_up(b, get_index(get_max(*b), *b), cpt, print);
		push_all(a, b, cpt, print);
	}
}
