
#include "push_swap.h"
int		ft_isspace(int c)
{
	if ((c > 9 && c < 13) || c == ' ')
		return (1);
	return (0);
}

int		check_arg(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (i < len)
	{
		if (ft_isdigit(str[i]) || ft_isspace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}


int		check_input(int ac, char **av)
{
	int i;
	int size;

	if (ac > 2)
	{
		size = ac - 1;
		i = 0;
		while (i < size)
		{
			if(!check_arg(av[i + 1]))
				return (0);
			i++;
		}
		return (size);
	}
	else if (ac == 2)
	{
		size = 0;
		i = 0;
		while (i < (int)ft_strlen(av[1]))
		{
			while (ft_isspace(av[1][i]))
				i++;
			if (av[1][i] == '+' || av[1][i] == '-')
				i++;
			if (!ft_isdigit(av[1][i]))
				return (0);
			if (ft_isdigit(av[1][i]))
				size++;
			while (ft_isdigit(av[1][i]))
				i++;
			while (ft_isspace(av[1][i]))
				i++;
		}
		return (size);
	}
	return (0);
}

int		*sort_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int		*str_to_tab(int	*tab, char *str)
{
	int len;
	int num;
	int	j;
	int i;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
		{
			num = ft_atoi(str + i);
			if (str[i] == '+')
				i++;
			i += get_intlen(num, 10);
			tab[j] = num;
			j++;
		}
		while (ft_isspace(str[i]))
			i++;
	}
	return (tab);
}

void	put_position(t_list *current, int *tab, int size)
{
	int	i;

	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)current->content == tab[i])
			{
				*(int *)current->content = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

int	make_list(t_list **stack, int size, char **av)
{
	int *tab;
	int	i;

	tab = (int *)malloc(sizeof (int) * size);
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	if (!sort_tab(tab, size))
		return (free_all(tab, NULL, size));	
	ft_lstinit(stack, av, size);
	put_position(*stack, tab, size);
	free_all(tab, NULL, size);
	return (size);
}
int	free_all(int *tab, char **strings, int size)
{
	int i;

	i = 0;
	if (strings)
	{
		while (i < size)
		{
			free(strings[i]);
			i++;
		}
		free(strings[i]);
	}
	free(strings);
	free(tab);
	return (0);
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
	i = 0;
	strings[0] = ft_strdup("");
	while (i < size)
	{
		num = tab[i];
		strings[i + 1] = ft_itoa(num);
		i++;	
	}
	ft_lstinit(stack, strings, size);
	if (!sort_tab(tab, size))
		return (free_all(tab, strings, size));
	put_position(*stack, tab, size);
	free_all(tab, strings, size);
	return (size);
}

int		get_input(t_list **stack, int ac, char **av)
{
	int		size;

	if (ac > 2)
	{
		size = check_input(ac, av);
		if (size)
			size = make_list(stack, size, av);
		return (size);
	}
	else if (ac == 2)
	{
		size = check_input(ac, av);
		if (size)
			size = make_list_from_str(stack, size, av[1]);
		return (size);
	}
	return (0);
}


