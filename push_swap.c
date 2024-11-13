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

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-d"))
			return (i);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;
	int		debug_flag;

	size = 0;
	if (ac <= 1)
		return (0);
	debug_flag = check_for_flags(ac, av);
	a = 0;
	b = 0;
	size = get_input(&a, ac, av, debug_flag);
	if (!size)
		write(2, "Error\n", 6);
	else
	{
		if (debug_flag)
			print_debug(a, b);
		sort_stack(&a, &b, debug_flag);
	}
//	else if (size >= 50)
//		radix_sort(&a, &b);
	if (debug_flag)
	{
		if (is_sorted(a, size))
			ft_printf("   ┉┉┉┉┉┉┉ SORTED ┉┉┉┉┉┉\n");
		print_debug(a, b);
	}
	ft_lstclear(&a, free);
}
