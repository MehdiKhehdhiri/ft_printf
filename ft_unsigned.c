/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:45:02 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/16 18:04:24 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	int				length;
	char			*result;
	unsigned long	nbr;
	int				l;

	result = malloc(sizeof(char) * ft_intlen(n));
	length = 0;
	nbr = n;
	if (nbr == 0)
	{
		write(1, "0", 1);
		length = 1;
	}
	while (nbr != 0)
	{
		result[length] = nbr % 10 + '0';
		nbr /= 10;
		length++;
	}
	l = length;
	while (--length >= 0 && n != 0)
		write(1, &result[length], 1);
	free(result);
	return (l);
}
