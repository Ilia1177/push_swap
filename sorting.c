#include "push_swap.h"

int	is_sorted(t_list *stack, int size)
{
	if (!stack)
		return (0);
	while (stack->next && size != 0)
	{
		if (ft_lstcmp(stack, stack->next) > 0)
			return (0);
		stack = stack->next;
		size--;
	}
	if (size != 1)
		return (0);
	return (1);
}

int	is_revsorted(t_list *stack, int size)
{
	if (!stack)
		return (-1);
	while (stack->next && size != 0)
	{
		if (ft_lstcmp(stack, stack->next) < 0)
			return (0);
		stack = stack->next;
		size--;
	}
	if (size != 1)
		return (0);
	return (1);
}

int	ft_lstcmp(t_list *a, t_list *b)
{
	if (!a || !b)
		return (0);
	return (*(int *)a->content - *(int *)b->content);
}

void	print_debug(t_list *a, t_list *b)
{
	static int count = -1;

	count++;
	if (a)
	{
		ft_printf("   ┏┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉\n");
		ft_printf("   ┃ STACK %s : ", a->name);
		ft_lstprint(a);
		ft_printf("\n");
	}
	if (b)
	{
		ft_printf("   ┃ STACK %s : ", b->name);
		ft_lstprint(b);
		ft_printf("\n");
	}
	ft_printf("   ┃ nb of operation : %d\n", count);
	ft_printf("   ┗┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉\n");
}
// main test -- OK
void	mixed_sort(t_list **a, t_list **b, int debug)
{
	int			size;
	t_list		*current;
	t_list		*max;
	t_list		*min;

	size = ft_lstsize(*a);
	while (!is_sorted(*a, size))
	{
		current = *a;
		max = get_max(*a);
		min = get_min(*a);
		if ((is_sorted(*a, ft_lstsize(*a)) && *b))
			push_all(a, b);
		else if (ft_lstcmp(current, max) == 0 && !is_sorted(min, ft_lstsize(min)))
		//	push_back(b, a);
			place_in_between(b, a);
		else if (ft_lstcmp(current, min) == 0 && !is_sorted(min, ft_lstsize(min)))
		//	push(b, a);
			place_in_between(b, a);
		else if (ft_lstcmp(current, current->next) > 0 && ft_lstcmp(current, max))
			swap(a, 1);
		else if (!is_sorted(*a, ft_lstsize(*a)))
			rotate(a, 1);
		if (debug)
			print_debug(*a, *b);
	}
}

int		cmp_swap(t_list **a)
{
	if (!*a || !(*a)->next)
		return (0);
	if (ft_lstcmp(*a, (*a)->next) > 0)
			swap(a, 1);
	return (ft_lstcmp(*a, (*a)->next));
}

int get_index(t_list *target, t_list *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		if (ft_lstcmp(target, stack) == 0)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

int	min_move(t_list *stk, t_list *obj)
{
	int		i;
	int		index;
	int		diff;
	t_list	*curr;

	if (!stk)
		return (0);
	curr = stk;
	diff = -1;
	index = -1;
	if (ft_lstcmp(obj, get_min(curr)) < 0)
		index = get_index(get_max(curr), curr);
	else
	{
		i = 0;
		if (ft_lstcmp(obj, curr) > 0)
		{
			index = i;
			diff = ft_lstcmp(obj, curr);
		}
		while (curr)
		{
			if (ft_lstcmp(obj, curr) > 0)
			{
				if (diff > ft_lstcmp(obj, curr) || diff == -1)
				{
					diff = ft_lstcmp(obj, curr);
					index = i;
				}
			}
			i++;
			curr = curr->next;
		}
	}
	if (index > ft_lstsize(stk) / 2)
		index = (index - ft_lstsize(stk));
	else
		index = index;
	return (index);
}

void	place_in_between(t_list **stk, t_list **obj)
{
	int		index;

	if (!*stk || !(*stk)->next)
		push(stk, obj);
	else
	{
		index = min_move(*stk, *obj);
		while (index)
		{
			if (index < 0)
			{
				r_rotate(stk, 1);
				index++;
			}
			else if (index > 0)
			{
				rotate(stk, 1);
				index--;
			}
		}
		push(stk, obj);
	}
}

int		check_pivot(t_list *stack, int index, int pivot)
{
	int	value;
	int	i;
	int	closest_index;
	int min_move;
	int move;
	t_list *curr;

	curr = stack;
	i = 1;
	closest_index = -1;
	min_move = ft_lstsize(stack);
	while (curr)
	{
		value = *(int *)curr->content;
		if (value >= index * pivot && value <= (index + 1) * pivot)
		{
			if (i <= ft_lstsize(stack) / 2)
				move = i;
			else if (i > ft_lstsize(stack) / 2)
				move = (i - ft_lstsize(stack)) * -1;
			if (min_move > move)
			{
				min_move = move;
				closest_index = i;
			}
		}
		if (!curr->next && closest_index != -1)
			return (closest_index);
		curr = curr->next;
		i++;
	}
	return (0);
}

void	bring_index_up(t_list **stk, int index)
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
			r_rotate(stk, 1);
			i++;
		}
		else if (i > 0)
		{
			i--;
			rotate(stk, 1);
		}
	}
}

void	make_run(t_list **a, t_list **b, int cursor,int debug)
{
	int pivot;
	int i;
	t_list	*curr;
	int a_value;

	pivot = ft_lstsize(*a) / cursor;	
	i = 0;
	curr = *a;
	while (i <= cursor)
	{
		while (check_pivot(*a, i, pivot))
		{
			curr = *a;
			a_value = *(int*)curr->content;
			if (a_value >= i * pivot && a_value <= (i + 1) * pivot)
				place_in_between(b, a);
			else
				bring_index_up(a, check_pivot(*a, i, pivot) - 1);
			if (debug)
				print_debug(*a, *b);
		}
		i++;
	}		
}

void	sort_stack(t_list **a, t_list **b, int debug)
{
		int size;

		size = ft_lstsize(*a);
		if (debug)
			ft_printf(" --------- sorting array ------\n");
		if (size < 50)
			mixed_sort(a, b, debug);
		if (size < 300)
			make_run(a, b, 5, debug);
		else
			make_run(a, b, 11, debug);
		if (debug && size > 50)	
			ft_printf("-----------bring index up -----\n");
		if (size > 50)
			bring_index_up(b, get_index(get_max(*b), *b));
		push_all(a, b);
		if (debug)
			ft_printf("-----------the end ------------\n");
}
