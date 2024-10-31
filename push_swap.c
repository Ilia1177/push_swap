/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:24:50 by npolack           #+#    #+#             */
/*   Updated: 2024/10/31 19:13:58 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac <= 1)
		return (0);
	a = 0;
	b = 0;
	
	ft_lstinit(&a, av, ac - 1);
	sort_stack(&a, &b);

	ft_printf("STACK A :\n");
	ft_lstprint(a);
	ft_printf("STACK B :\n");
	ft_lstprint(b);
}
int	find_index_max(t_list *stack)
{
	int		index_min;
	int		i;
	t_list	*move;
	int		value;

	if (!stack)
		return (0);
	i = 0;
	index_min = 0;
	move = stack;
	value = *(int *)move->content;
	while (move)
	{
		if (*(int *)move->content > value)
		{
			value = *(int *)move->content;	
			index_min = i;
		}
		if (move->next)
			move = move->next;
		else
			break ;
		i++;
	}
	return (index_min);
}

int	find_index_min(t_list *stack)
{
	int		index_min;
	int		i;
	t_list	*move;
	int		value;

	if (!stack)
		return (0);
	i = 0;
	index_min = 0;
	move = stack;
	value = *(int *)move->content;
	while (move)
	{
		if (*(int *)move->content < value)
		{
			value = *(int *)move->content;	
			index_min = i;
		}
		if (move->next)
			move = move->next;
		else
			break ;
		i++;
	}
	return (index_min);
}

int	minus_first(t_list *stack, int check)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !stack->next)
		return (0);
	first = stack;
	if (check == 1)
	{
		second = stack->next;
		if (*(int *)first->content < *(int *)second->content)
			return (1);
	}
	else if (check == 2)
	{	
		second = ft_lstlast(stack);
		if (*(int *)first->content < *(int *)second->content)
			return (1);
	}
	return (0);
}

int	ft_lstcmp(t_list *a, t_list *b)
{
	if (!a || !b)
		return (0);
	if(*(int *)a->content < *(int *)a->content)
		return (1);
	return (0);
}

int	is_sorted(t_list *stack)
{
	t_list	*move;
	int		value;

	value = *(int *)stack->content;
	move = stack;
	while (move->next)
	{
		if (*(int *)move->content > *(int *)move->next->content)
		   return (0);	
		move = move->next;
	}
	return (1);
}

/*void	sort_stack(t_list **a, t_list **b)
{
	int size;
	//t_list	*temp;

	size = ft_lstsize(*a);

	while (!is_sorted(*a) && ft_lstsize(*b) != 0)
	{
		if (ft_lstcmp(*a, *b))
			push(a, b);
		if (!minus_first(*a, 1))
			push(b, a);
	}
	ft_printf("SORTED STACK DONE!\n");
}*/

void	sort_stack(t_list **a, t_list **b)
{
	int		index_min;
	int		i;
	t_list	*move;
	int size;

	i = 0;
	move = *a;
	size = ft_lstsize(*a);
	while (size > 0)
	{	
		index_min = find_index_min(*a);
		i = 0;
		while (i < index_min)
		{
			rotate(a, 1);
			i++;
		}
		push(b, a);
		size = ft_lstsize(*a);
	}

	i = 0;
	size = ft_lstsize(*b);
	move = *b;
	while (i < size)
	{
		push(a, b);
		i++;
		}
}
