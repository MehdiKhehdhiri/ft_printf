/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:35:12 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/17 12:53:33 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_intlen(long n)
{
	unsigned int	len;
	unsigned int	num;

	len = 0;
	if (n < 0)
	{
		len++;
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		len++;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
