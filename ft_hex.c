/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:48:12 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/16 18:55:54 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_neg_hex(unsigned int n, char *hex)
{
	int			length;
	char		*result;
	long long	nbr;
	int			l;

	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!result)
		return (0);
	l = ft_intlen(n);
	length = 0;
	nbr = 4294967295 + n + 1;
	if (n == 0)
		write(1, "0", 1);
	while (nbr != 0)
	{
		result[length] = hex[(nbr % 16)];
		nbr /= 16;
		length++;
	}
	while (--length >= 0 && n != 0)
		write(1, &result[length], 1);
	free (result);
	return (l);
}

void	ft_checkx(char x, char **hex)
{
	if (x == 'x')
		*hex = "0123456789abcdef";
	else if (x == 'X')
		*hex = "0123456789ABCDEF";
}

void	ft_hex(unsigned int n, char x, int *l)
{
	int			length;
	char		*result;
	char		*hex;

	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	ft_checkx(x, &hex);
	if (!result || !hex)
		return ;
	length = 0;
	if (n <= 0)
	{
		free(result);
		*l = ft_neg_hex(n, hex);
		return ;
	}
	while (n != 0)
	{
		result[length] = hex[(n % 16)];
		n /= 16;
		length++;
	}
	*l = length;
	while (--length >= 0)
		write(1, &result[length], 1);
	free(result);
}
