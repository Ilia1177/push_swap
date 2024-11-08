#include "push_swap.h"

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

int		check_args(int ac, char **av)
{
	int	i;
	int size;
	char *str;

	i = 0;
	while (i < ac - 1)
	{
		str = av[i + 1];
		size = check_str(str);
		if (size != 1)
			return (0);
		i++;
	}
	return (i);
}

int		check_str(char *str)
{
	int	size;
	int i;
	int len;

	len = ft_strlen(str);
	size = 0;
	i = 0;
	while (i < len)
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		if (ft_isdigit(str[i]))
			size++;
		while (ft_isdigit(str[i]))
			i++;
		while (ft_isspace(str[i]))
			i++;
	}
	return (size);
}

int		check_input(int ac, char **av)
{
	int size;

	if (ac > 2)
	{
		size = check_args(ac, av);
		return (size);
	}
	else if (ac == 2)
	{
		size = check_str(av[1]);
		return (size);
	}
	return (0);
}

