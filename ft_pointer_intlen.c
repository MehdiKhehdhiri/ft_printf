/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_int_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:42:14 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/17 16:07:38 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_pointer_intlen(unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
