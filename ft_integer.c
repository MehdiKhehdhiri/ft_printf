/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:40:22 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/17 16:05:53 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_integer(int n, int *l)
{
	int		length;
	char	*result;
	long	nbr;

	result = malloc(sizeof(char) * ft_intlen(n));
	length = 0;
	nbr = n;
	*l = ft_intlen(n);
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	while (nbr != 0)
	{
		result[length] = nbr % 10 + '0';
		nbr /= 10;
		length++;
	}
	while (--length >= 0)
		write(1, &result[length], 1);
	free(result);
}
