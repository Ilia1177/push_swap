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

int	check_for_flags(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (!ft_strcmp(av[i], "-d"))
			return (i);
	return (0);
}

t_count	*count_instructions(t_list **a, t_list **b, int flag)
{
	int	instr_nb;
	t_count *counter;

	counter = malloc(sizeof(t_count));
	counter->counter = 0;
	if (flag)
		print_debug(*a, *b, counter);
	sort_stack(a, b, 0, counter);
	instr_nb = counter->counter;
	if (flag)
		ft_printf("\n----- count instructions = %d\n", instr_nb);
	counter->instr = (char **)ft_calloc(sizeof (char *), instr_nb);
	counter->counter = 0;
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	a = 0;
	b = 0;
	return (counter);
}

int	print_instructions(t_count *counter, int print)
{
	int	i;
   	int	deleted_instr;

	i = 0;
	deleted_instr = trim_instr(counter);
	if (print)
		ft_printf("----- finals instructions\n");
	while (i < counter->counter)
	{
		if (print && !counter->instr[i][0])
			ft_printf("----- INSTRUCTION REPLACED\n");
		else if (counter->instr[i][0])
			ft_printf("%s", counter->instr[i]);
		free(counter->instr[i]);
		i++;
	}
	free(counter->instr);
	if (print)
		ft_printf("----- %d deleted on %d\n", deleted_instr, counter->counter);
	return (counter->counter - deleted_instr);
}

void	process(t_list **a, t_list **b, int ac, char **av, int debug_flag)
{
	t_count *counter;
	int		size;

	counter = count_instructions(a, b, 0);
	get_input(a, ac, av, debug_flag);
	size = ft_lstsize(*a);
	if (debug_flag)
		sort_stack(a, b, 2, counter);
	else
		sort_stack(a, b, 1, counter);
	if (debug_flag && is_sorted(*a, size))
		ft_printf("----- stack sorted !\n");
	counter->counter = print_instructions(counter, debug_flag);
	if (debug_flag)
		print_debug(*a, *b, counter);
	free(counter);
}

//throw error
int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;
	int		debug_flag;

	if (ac <= 1)
		return (0);
	debug_flag = check_for_flags(ac, av);
	a = 0;
	b = 0;
	size = get_input(&a, ac, av, debug_flag);
	if (!size)
		write(2, "Error\n", 6);
	else
		process(&a, &b, ac, av, debug_flag);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
