/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:07:56 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/17 16:10:27 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_neg_hex(unsigned long long n, char *hex)
{
	int		length;
	char	*result;
	int		l;

	length = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	result = malloc(sizeof(char) * ft_pointer_intlen(n) + 1);
	if (!result)
		return (0);
	n = 4294967295 + n + 1;
	while (n != 0)
	{
		result[length] = hex[(n % 16)];
		n /= 16;
		length++;
	}
	l = length;
	while (--length >= 0)
		write(1, &result[length], 1);
	free (result);
	return (l);
}

void	ft_pointer_hex(unsigned long long n, int *l)
{
	int			length;
	char		*result;
	char		*hex;

	result = malloc(sizeof(char) * ft_pointer_intlen(n) + 1);
	hex = "0123456789abcdef";
	if (!result)
		return ;
	length = 0;
	if (n <= 0)
	{
		free(result);
		*l = ft_pointer_neg_hex(n, hex);
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
