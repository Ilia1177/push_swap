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
			push_all(a, b, debug);
		else if (ft_lstcmp(current, max) == 0 && !is_sorted(min, ft_lstsize(min)))
			push_back(b, a);
		else if (ft_lstcmp(current, min) == 0 && !is_sorted(min, ft_lstsize(min)))
			push(b, a);
		else if (ft_lstcmp(current, current->next) > 0 && ft_lstcmp(current, max))
			swap(a, 1);
		else if (!is_sorted(*a, ft_lstsize(*a)))
			rotate(a, 1);
		if (debug)
			print_debug(*a, *b);
	}
}
void	bubble_sort(t_list **stack, int print)
{
	t_list *current;
	t_list *max;
	t_list *min;
	int size;
	int i;

	if (!*stack)
		return ;
	size = ft_lstsize(*stack);
	i= 0;

	while (i < size)
	{
	current = *stack;
	max = get_max(*stack);
	min = get_min(*stack);
	if (ft_lstcmp(current, max) == 0)
		if (ft_lstcmp(current->next, min) == 0)
			rotate(stack, 1);
		else
		{
			swap(stack, 1);
			i--;
		}
	else if (ft_lstcmp(current, current->next) > 0)
	{
		swap(stack, 1);
		i--;
	}
	else
		rotate(stack, 1);
	current = *stack;
	i++;
	if (print)
		print_debug(*stack, NULL);
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

// not working
/*void	median_sort(t_list **a, t_list **b, int debug)
{
	int	mid;
	int		median;
	int size;
	t_list *min;
//	t_list *current;
	if (!*a)
		return ;

	min = get_min(*a);
	size = ft_lstsize(*a);
	median = (size / 2) - 1;
	mid = median / 2;
	while (*(int *)min->content <= median)
	{
		if (*b && (*b)->next && ft_lstcmp(*b, (*b)->next) < 0)
			swap(b, 1);	
		if (*(int *)(*a)->content < median)
		{
			if (*(int *)(*a)->content < mid)
				push_back(b, a);
			else if (*(int *)(*a)->content > mid) 
				push(b, a);
			else
				push(b, a);
		}
		else if (ft_lstcmp(*a, (*a)->next) > 0)
		{
			if (*(int *)(*a)->content > median + mid)
				rotate(a, 1);
			else if (*(int *)(*a)->content < median + mid)
				swap(a, 1);
		}
		else if (closest_min(*a, median) < size / 2)
			rotate(a, 1);
		else
			r_rotate(a, 1);
		if (debug)
			print_debug(*a, *b);
		min = get_min(*a);
	}
	ft_printf("bubble_sort--------------------------------\n");

}	*/

// Sort with move direction , left or right
// PAIR IMPAIR ?
int	is_even(t_list *stack)
{
	return (*(int *)stack->content % 2 == 0);
}

int	check_even(t_list *stack)
{
	while (stack)
	{
		if (is_even(stack))
			return (*(int *)stack->content + 1);
		stack = stack->next;
	}
		return (0);
}
int closest_even(t_list *stack)
{	
	int top_move;
	int	last_move;
	t_list *current;
	top_move= 0;
	last_move = 0;
	int size;
	int i;

	size = ft_lstsize(stack);
	current = stack;
	i = 0;
	while (current)
	{
		if (is_even(current))
		{
			top_move = i;
			break ;
		}
		current = current->next;
		i++;
	}
	current = stack;
	i = 0;
	while (current)
	{
		if (is_even(current))
			last_move = i;
		current = current->next;
		i++;
	}
	if ((size - last_move > top_move))
			return (top_move);
	return (last_move);
}

int	find_next_in(t_list *stack, t_list *target)
{
	int i;
	t_list *current;
	int move;

	move = 1;
	current = stack;
	i = 0;
	if (ft_lstcmp(target, target->next) == -1)
		return (0);
	while (current)
	{
		if (ft_lstcmp(current, target) == -1)
			move = (i);
		if (ft_lstcmp(current, target) == 1)
			move = i + 1;
		if (i > ft_lstsize(stack) / 2 )
			i *= -1;
		else
			i++;
		current = current->next;
	}
	return (move);	
}

t_list *find_next(t_list *stack, t_list *target)
{
	while(stack)
	{
		if (ft_lstcmp(stack, target) == 1)
			return (stack);
		stack = stack->next;
	}
	return (0);
}

int get_index(t_list *target, t_list *stack)
{
	int	i;

	i = 1;
	while(stack)
	{
		if (ft_lstcmp(target, stack) == 0)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

// put A in the right spot
int	get_next(t_list *target, t_list **a, t_list **b)
{
	t_list	*next;
	t_list	**curr_stack;
	int	i;
	int j;

	i = 1;
	if (target->name[0] == 'a')
		curr_stack = a;
	else
		curr_stack = b;

	next = find_next(*a, target);
	j = find_next_in(*a, next);
	if (!next)
	{
		next = find_next(*b, target);
		j = find_next_in(*b, next);
	}

	if (target->name[0] == next->name[0])
	{
		swap(curr_stack, 1);
		while (i < j)
		{
			rotate(curr_stack, 1);
			i++;
		}
		return (1);
	}
	else if (target->name[0] == 'a')
	{	
		while (i < j)
		{
			rotate(b, 1);
			i++;
		}		
		push(a, b);
		swap(a, 1);
	}
	else
	{
		while (i < j)
		{
			rotate(a, 1);
			i++;
		}		
		push(b, b);

	}
	print_debug(*a, *b);
	return (0);
}

void	even_sort(t_list **a, t_list **b, int debug)
{
	int i;
	int size;
	int median;

	size = ft_lstsize(*a);
	median = (size / 2) - 1;

	i = 0;
	while (check_even(*a))
	{	
		if (*a && ft_lstcmp(*a, (*a)->next) > 0 && !is_even(*a))
			if (ft_lstcmp((*a)->next, get_min(*a)) == 0)
				rotate(a, 1);
			else
				swap(a, 1);
		else if (*b && ft_lstcmp(*b, (*b)->next) < 0)
			if (ft_lstcmp((*b)->next, get_max(*b)) == 0)
				rotate(b, 1);
			else
				swap(b, 1);
		else if (*(int *)(*a)->content % 2 == 0)
		{
			if (*(int *)(*a)->content < median)
				push_back(b, a);
			else if (*(int *)(*a)->content > median) 
				push(b, a);
			else
				push(b, a);
		}
		else if (closest_even(*a) > (ft_lstsize(*a) / 2))
			r_rotate(a, 1);
//		else if (*(int *)(*a)->content > median)
//			rotate(a, 1);
		else
			rotate(a, 1);
		if (debug)
			print_debug(*a, *b);
		i++;
	}
}

int		check_pivot(t_list *stack, int index, int pivot)
{
	int	value;

	while (stack)
	{
		value = *(int *)stack->content;
		if (value > index * pivot && value < (index + 1) * pivot)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	find_minmove(t_list *stack, t_list *target)
{
	int i;
	t_list *current;
	int bot_move;
	int top_move;
	

	top_move = 0;
	current = stack;
	i = 0;
	while (current)
	{
		
		if (ft_lstcmp(current, target) < 0)
		{
			while (ft_lstcmp(current, target) < 0)
			{
				top_move = i;
				i++;
			}
			else if (ft_lstcmp(ft_lstlast(stack), current) > 0)
				move = (i);
			else 
				current = current->next;
		}
		if (ft_lstcmp(current, target) == 1)
			move = i + 1;
		if (i > ft_lstsize(stack) / 2 )
			i *= -1;
		else
			i++;
		current = current->next;
	}
	return (move);	
}

void	put_in(t_list **stack, t_list **target)
{
	t_list *curr;
	int i;
	ft_printf("start PUT_IN PLACE\n");
	curr = *stack;
	if (!*stack || !(*stack)->next)
		push(stack, target);
	else
	{
		while (curr)
		{
			curr = *stack;
			i = find_minmove(current, *target);

			{
				i = find_minmove(curr, *target)

				while (ft_lstcmp(curr, get_max(*stack)))
				{
					rotate(stack, 1);
					curr = *stack;
				}
				push(stack, target);
				return ;
			}
			else if (ft_lstcmp(curr, *target) > 0)
			{
				while(ft_lstcmp(curr, *target) > 0)
				{
					rotate(stack, 1);
					curr = *stack;
				}
				push(stack, target);
				return ;
			}			
		}

	}
}

void	rev_mixed_sort(t_list **stack, t_list **tmp, int debug)
{
	int			size;
	t_list		*curr;
	t_list		*max;
	t_list		*min;

	size = ft_lstsize(*stack);
	ft_printf("start reveSorting ! size = %d\n", size);
	while (!is_revsorted(*stack, size))
	{
		curr = *stack;
		max = get_max(*stack);
		min = get_min(*stack);
		if (curr && curr->next && !ft_lstcmp(curr, min) && !ft_lstcmp(curr->next, max))
			rotate(stack, 1);
		else if (curr && curr->next && ft_lstcmp(curr, curr->next) < 0)
				swap(stack, 1);
		else if (!is_revsorted(*stack, size)) 
			rotate(stack, 1);
		if (debug)
			print_debug(*stack, *tmp);
	}
	ft_printf("Done revsorting... \n");
}

void	make_run(t_list **a, t_list **b, int debug)
{
	int pivot;
	int cursor;
	int i;
	t_list	*curr;
	int a_value;

	curr = *a;
	cursor = 3;
	pivot = ft_lstsize(*a) / cursor;
	
	i = 0;
		curr = *a;
		while (i <= cursor)
		{
				curr = *a;
			while (check_pivot(*a, i, pivot))
			{
				curr = *a;
				a_value = *(int*)curr->content;
				if (a_value >= i * pivot && a_value <= (i + 1) * pivot)
				{
					put_in(b, a);
					ft_printf("END OF PUT IN\n");
				}
				else
					rotate(a, 1);
				if (debug)
					print_debug(*a, *b);
			}	
			rev_mixed_sort(b, a, debug);
			i++;
		}
	/*	curr = *b;
		while (curr)
		{
			curr = *b;
			if (*a && (*a)->next && ft_lstcmp(*a, (*a)->next) > 0 && ft_lstcmp(*a, get_max(*a)) && ft_lstcmp((*a)->next, get_min(*a)))
				swap(a, 1);
			else if (curr && curr->next && ft_lstcmp(curr, (curr)->next) < 0 && ft_lstcmp(curr, get_max(curr)) && ft_lstcmp((curr)->next, curr))
				swap(b, 1);
			else if (*b)
				push(a, b);
			else
				rotate(b, 1);
			if (debug)
				print_debug(*a, *b);
		}
		*/
		

		
}



void	sort_stack(t_list **a, t_list **b, int debug)
{
//	int			size;
//	t_list		*current;
//	t_list		*max;
//	t_list		*min;
//	int i;

//	i = 0;
//	size = ft_lstsize(*a);
//	while (++i < 10)
//	while (!is_sorted(*a, size))
//	{
//		current = *a;
//		max = get_max(*a);
//		min = get_min(*a);

	//	bubble_sort(b, debug);
	//	bubble_sort(a, debug);
		
	//	median_sort(a, b, debug);
		if (debug)
			ft_printf(" RUN-----------------\n");
		make_run(a, b, debug);

		if (debug)	
			ft_printf("------------find next--------------------\n");
		if (debug)
			ft_printf("--------------END -----------------\n");
//	}
}

void	radix_sort(t_list **a, t_list **b)
{
	int		size;
	int		max_num;
	int		max_bits;
	int		i;
	int		j;
	int		num;
	t_list	*max;

	max_bits = 0;
	max = get_max(*a);
	max_num = *(int *)max->content;
	size = ft_lstsize(*a);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = *(int *)(*a)->content;
			if (((num >> i) & 1) == 1)
				rotate(a, 1);
			else
				push(b, a);
			j++;
		}
		while (ft_lstsize(*b))
			push(a, b);
		i++;
	}
}
