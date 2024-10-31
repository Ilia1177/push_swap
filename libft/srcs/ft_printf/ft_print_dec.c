/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:06:31 by npolack           #+#    #+#             */
/*   Updated: 2024/10/30 12:40:30 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_dec(int n)
{
	int	len;

	len = get_intlen(n, 10);
	ft_putnb_base(n, "0123456789");
	return (len);
}
