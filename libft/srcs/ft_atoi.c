/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:27:40 by npolack           #+#    #+#             */
/*   Updated: 2024/11/28 17:07:24 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int ft_atoi(const char *nptr)
{
	long int	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*nptr)
	{
		while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
			nptr++;
		if (*nptr == '-')
		{
			sign *= -1;
			nptr++;
		}
		else if (*nptr == '+')
			nptr++;
		while (*nptr >= '0' && *nptr <= '9')
		{
			result = result * 10 + (*nptr) - '0';
			nptr++;
		}
		return (result * sign);
	}
	return (0);
}
