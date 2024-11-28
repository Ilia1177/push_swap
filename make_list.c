/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:30:01 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 17:42:32 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IMPLEMENT OVERFLOW PROTECT
int	make_list(t_list **stack, int size, char **av, int flag)
{
	int	*tab;
	int	i;
	int	j;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	i = 1;
	j = 0;
	while (i <= size)
	{
		if (flag == i)
			j++;
		tab[i - 1] = ft_atoi(av[i + j]); //here
		i++;
	}
	if (!sort_tab(tab, size))
		return (free_all(tab, NULL, size));
	ft_lstinit(stack, av, size, flag);
	put_position(*stack, tab, size);
	free_all(tab, NULL, size);
	return (size);
}

int	make_list_from_str(t_list **stack, int size, char *str)
{
	int		*tab;
	char	**strings;
	int		num;
	int		i;

	tab = (int *)malloc(size * sizeof (int));
	if (!tab)
		return (0);
	tab = str_to_tab(tab, str);
	strings = (char **)malloc(sizeof (char *) * (size + 1));
	if (!strings)
		return (free_all(tab, strings, size));
	i = -1;
	strings[0] = ft_strdup("");
	while (++i < size)
	{
		num = tab[i];
		strings[i + 1] = ft_itoa(num);
	}
	ft_lstinit(stack, strings, size, 0);
	if (!sort_tab(tab, size))
		return (free_all(tab, strings, size));
	put_position(*stack, tab, size);
	free_all(tab, strings, size);
	return (size);
}
