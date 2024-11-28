/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:33:18 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 15:03:17 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *target, t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (ft_lstcmp(target, stack) == 0)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

int	find_closest_inferior_index(t_list *curr, t_list *obj)
{
	int	i;
	int	target_i;
	int	diff;

	i = 0;
	diff = 0;
	while (curr)
	{
		if (ft_lstcmp(obj, curr) > 0)
		{
			if (diff > ft_lstcmp(obj, curr) || !diff)
			{
				diff = ft_lstcmp(obj, curr);
				target_i = i;
			}
		}
		i++;
		curr = curr->next;
	}
	if (!diff)
		return (0);
	return (target_i);
}

int	closest_inferior(t_list *stk, t_list *obj)
{
	int		move;

	if (!stk)
		return (0);
	move = 0;
	if (ft_lstcmp(obj, get_min(stk)) < 0)
		move = get_index(get_max(stk), stk);
	else
		move = find_closest_inferior_index(stk, obj);
	if (move > ft_lstsize(stk) / 2)
		move = (move - ft_lstsize(stk));
	return (move);
}

void	place_in_between(t_list **stk, t_list **obj, t_count *cpt, int print)
{
	int		move;

	if (print == 2)
		ft_printf("----- place in between\n");
	if (!*stk || !(*stk)->next)
		push(stk, obj, cpt, print);
	else
	{
		move = closest_inferior(*stk, *obj);
		while (move)
		{
			if (move < 0)
			{
				r_rotate(stk, print, cpt);
				move++;
			}
			else if (move > 0)
			{
				rotate(stk, print, cpt);
				move--;
			}
		}
		push(stk, obj, cpt, print);
	}
}

int	move_calc(int index, int size)
{
	int	move;

	move = 0;
	if (index <= size / 2)
		move = index;
	else if (index > size / 2)
		move = (index - size);
	if (move < 0)
		move *= -1;
	return (move);
}
