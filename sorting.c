#include "push_swap.h"

void	sort_5first(t_list **stack, int debug)
{
	t_list *current;
	int		count;

	count = 3;
	while (count > 0)
	{
		current = *stack;
		if (ft_lstcmp(current, current->next) > 0)
			swap(stack, 1);
		else
		{
			count--;
			rotate(stack, 1);
			if (ft_lstcmp(*stack, (*stack)->next) > 0)
				swap(stack, 1);
		}
		if (debug)
		{
			ft_printf("| STACK A : ");
			ft_lstprint(*stack);
			ft_printf("\n");
		}
	}
	while (count < 3)
	{
		current = *stack;
		if (ft_lstcmp(*stack, current->next) > 0)
			swap(stack, 1);
		else
		{
			count++;
			r_rotate(stack, 1);
			if (ft_lstcmp(*stack, (*stack)->next) > 0)
				swap(stack, 1);
		}
		if (debug)
		{
			ft_printf("| STACK A : ");
			ft_lstprint(*stack);
			ft_printf("\n");
		}
	}
}
void	print_debug(t_list *a, t_list *b, int count)
{
		ft_printf("| STACK A : ");
		ft_lstprint(a);
		ft_printf("\n");
		ft_printf("| STACK B : ");
		ft_lstprint(b);
		ft_printf("\n");
		ft_printf("| nb of operation : %d\n", count);
}


void	mixed_sort2(t_list **a, t_list **b, int debug)
{
	t_list *current;
	t_list *max;
	t_list *min;
	static int	count;
	int size;

	size = ft_lstsize(*a);
	while (!is_sorted(*a, size))
	{
		count++;
		current = *a;
		max = get_max(*a);
		min = get_min(*a);
		if ((is_sorted(*a, ft_lstsize(*a)) && *b))
			push_all(a, b);
		else if (ft_lstcmp(current, max) == 0 && !is_sorted(min, ft_lstsize(min)))
			push_back(b, a);
		else if (ft_lstcmp(current, min) == 0 && !is_sorted(min, ft_lstsize(min)))
			push(b, a);
		else if (ft_lstcmp(current, current->next) > 0 && ft_lstcmp(current, max))
			swap(a, 1);
		else if (!is_sorted(*a, ft_lstsize(*a)))
			rotate(a, 1);
		if (debug)
			print_debug(*a, *b, count);
	}
}
void	radix_sort(t_list **a, t_list **b)
{
	int size;
	t_list	*max;
	int max_num;
	int max_bits;
	int	i;
	int j;
	int num;

	max_bits = 0;
	max = get_max(*a);
	max_num = *(int *)max->content;
	size = ft_lstsize(*a);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	ft_printf("max bits = %d\n", max_bits);
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
// WORKS for 5 elements
void	mixed_sort(t_list **a, t_list **b, int debug)
{
	t_list *current;
	t_list *max;
	t_list *min;
	static int	count;

	count++;
	current = *a;
	max = get_max(*a);
	min = get_min(*a);
	if ((is_sorted(*a, ft_lstsize(*a)) && *b ) || !*a)
		push_all(a, b);
	else if (ft_lstcmp(current, max) == 0)
		rotate(a, 1);
	else if (ft_lstcmp(current, min) == 0)
		push(b, a);
	else if (ft_lstcmp(current, current->next) > 0)
		swap(a, 1);
	else if (!is_sorted(*a, ft_lstsize(*a)))
		rotate(a, 1);
	if (debug)
	{
		ft_printf("| STACK A : ");
		ft_lstprint(*a);
		ft_printf("\n");
		ft_printf("| STACK B : ");
		ft_lstprint(*b);
		ft_printf("\n");
		ft_printf("| count : %d\n", count);

	}	

}

void	bubble_sort(t_list **stack)
{
	t_list *current;
	t_list *max;
	t_list *min;

	current = *stack;
	max = get_max(*stack);
	min = get_min(*stack);
	if (ft_lstcmp(current, max) == 0)
		if (ft_lstcmp(current->next, min) == 0)
			rotate(stack, 1);
		else
			swap(stack, 1);
	else if (ft_lstcmp(current, current->next) > 0)
		swap(stack, 1);
	else
		rotate(stack, 1);
	current = *stack;
}



// A --> B ( reverse )
void	pre_sort(t_list **a, t_list **b, int debug)
{
	int rotation;

	while (ft_lstsize(*a))
	{
	//	if ((*a)->next && ft_lstcmp(*a, (*a)->next) > 0)
	//		swap(a, 1);
		// If head A is lower than head B --> push_back
		if (ft_lstcmp(*a, *b) < 0)
		{
			if (ft_lstcmp(*a, ft_lstlast(*b)) > 0)
			{
				rotation  = 0;
				while (ft_lstcmp(*a, ft_lstlast(*b)) > 0)
				{
					r_rotate(b, 1);
					rotation++;
				}
			  	push_back(b, a);
				while (rotation > 0)
				{
					rotate(b, 1);
					rotation--;
				}
			}
			else if (ft_lstcmp(*a, ft_lstlast(*b)) < 0)
			{
				push_back(b, a);
			//	rotate(b, 1);
			}
		}
		else if (ft_lstcmp(*a, *b) > 0)
		{
			push(b, a);
		}
		else if (!ft_lstcmp(*a, *b))
			push(b, a);
		if (debug)
		{
			ft_printf(" | STACK A : ");
			ft_lstprint(*a);
			ft_printf(" | STACK B : ");
			ft_lstprint(*b);
			ft_printf("\n");
		}
	}
}

void	exchange(t_list **a, t_list **b)
{
	push(b, a);
	swap(b, 1);
	push(a, b);
}

void	pre_sort2(t_list **a, t_list **b, int debug)
{
	int	diff_first;
	int	diff_last;

	while (ft_lstsize(*a))
	{
		diff_first = ft_lstcmp(*a, *b);
		diff_last = ft_lstcmp(*a, ft_lstlast(*b));
		if (ft_lstcmp(*a, *b) < 0)
		{
			if (diff_last < 0)
				diff_last *= -1;
			if (diff_first < 0)
				diff_first *= -1;

			if (ft_lstcmp(*a, ft_lstlast(*b)) < 0)
			{
				push_back(b, a);
			}
			else if (ft_lstcmp(*a, ft_lstlast(*b)) > 0)
				exchange(a, b);
		}
		else if (ft_lstcmp(*a, *b) > 0)
			push(b, a);
		else if (!ft_lstcmp(*a, *b))
			push(b, a);

		if (debug)
		{
		ft_printf("  STACK A : ");
		ft_lstprint(*a);
		ft_printf("\n  STACK B : ");
		ft_lstprint(*b);
		ft_printf("\n");
		}
	}
}

void	pre_sort3(t_list **a, t_list **b, int debug)
{
	int size = ft_lstsize(*a);

	while (1)
	{		
	
		if (!*a)
			push_all(a, b);
		if (is_sorted(*a, size))
			break ;
		if (!*b)
			push(b, a);
		else if (ft_lstcmp(*a, *b) < 0)
		{
			push(a, b);
			swap(a, 1);
		}
		else if (ft_lstcmp(*a, *b) > 0)
			push(b, a);
		if (debug)
		{
			ft_printf("  STACK A : ");
			ft_lstprint(*a);
			ft_printf("\n  STACK B : ");
			ft_lstprint(*b);
			ft_printf("\n");
		}
	}
}
void	pre_sort4(t_list **a, t_list **b, int debug)
{
	int size;

	size = ft_lstsize(*a);
	ft_printf("size = %d\n", size);
	
	while (1)
	{	
		if (!*a)
			push_all(a, b);
		if (is_sorted(*a, size))
			break ;

		if (ft_lstcmp(*a, (*a)->next) < 0)
			swap(a, 1);
		if (!*b)
			push(b, a);
		else if (ft_lstcmp(*a, *b) < 0)
		{
			if (ft_lstcmp(*a, ft_lstlast(*b)) < 0)
				push_back(b, a);
			else
				push_back(a, b);
		}
		else if (ft_lstcmp(*a, *b) > 0)
			push(b, a);
		if (debug)
		{
			ft_printf("  STACK A : ");
			ft_lstprint(*a);
			ft_printf("\n  STACK B : ");
			ft_lstprint(*b);
			ft_printf("\n");
		}
	}
}
//			cible / from

// sort A --> B --> A
void	pre_sort5(t_list **a, t_list **b, int debug)
{
	int size;

	size = ft_lstsize(*a);
	while (!is_sorted(*a, size))
	{	
		if (!*a)
			push_all(a, b);
		// sort 2 first
		else if (ft_lstcmp(*a, (*a)->next) > 0)
		{
			swap(a, 1);	
			if(ft_lstcmp(*a, ft_lstlast(*a)) > 0)
				r_rotate(a, 1);
		}
		// sort the last one
		else if (ft_lstcmp(ft_lstlast(*a), (*a)->next) < 0 )
		{
			if (ft_lstcmp(ft_lstlast(*a), *a) > 0)
			{
				r_rotate(a, 1);
				swap(a, 1);
			}
			else 
				r_rotate(a, 1);
			
		}
		// PUSH FROM THE BACK OF THE STACK
		else if (!*b)
			push_last(b, a);
		// si A < B
		else if (ft_lstcmp(*a, *b) < 0)
		{
			if (ft_lstcmp(*a, ft_lstlast(*b)) < 0)
				push_back(b, a);
			else
				push_back(a, b);
		}
		else if (ft_lstcmp(*a, *b) > 0)
			push(b, a);
		if (debug)
		{
			ft_printf("  STACK A : ");
			ft_lstprint(*a);
			ft_printf("\n  STACK B : ");
			ft_lstprint(*b);
			ft_printf("\n");
		}
	}
}

void	pre_sort6(t_list **a, t_list **b, int debug)
{
	int size;

	size = ft_lstsize(*a);
	while (!is_sorted(*a, size))
	{	
		if (!*a)
			push_all(a, b);
		// sort 2 first
		else if (ft_lstcmp(*a, (*a)->next) > 0)
		{
			swap(a, 1);	
			if(ft_lstcmp(*a, ft_lstlast(*a)) > 0)
				r_rotate(a, 1);
		}
		// sort the last one
		else if (ft_lstcmp(ft_lstlast(*a), (*a)->next) < 0 )
		{
			if (ft_lstcmp(ft_lstlast(*a), *a) > 0)
			{
				r_rotate(a, 1);
				swap(a, 1);
			}
			else 
				r_rotate(a, 1);	
			r_rotate(a, 1);
			r_rotate(a, 1);
			r_rotate(a, 1);
		}
		// PUSH FROM THE BACK OF THE STACK
		else if (!*b)
			push_last(b, a);
//		else if (ft_lstcmp(*b, ft_lstlast(*a)) > 0)
//			push_back(a, b);
		else if (ft_lstcmp(*a, *b) < 0)
		{
			if (ft_lstcmp(*a, ft_lstlast(*b)) < 0)
			{
				if (ft_lstcmp(ft_lstlast(*b), (*a)->next) < 0 && ft_lstsize(*b) > 1)
				{
					push_last(a, b);
					swap(a, 1);
				}
				else 
					push_back(b, a);
			}
			else if (ft_lstcmp(*a, ft_lstlast(*b)) > 0)
				push_back(a, b);
		}
		else if (ft_lstcmp(*a, *b) > 0)
			push(b, a);
		if (debug)
		{
			ft_printf("  STACK A : ");
			ft_lstprint(*a);
			ft_printf("\n  STACK B : ");
			ft_lstprint(*b);
			ft_printf("\n");
		}
	}
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






