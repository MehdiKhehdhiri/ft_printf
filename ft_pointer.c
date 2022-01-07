/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:29:59 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/17 16:06:26 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_pointer(unsigned long long ptr)
{
	int	l;

	l = 0;
	ft_putstr("0x");
	ft_pointer_hex(ptr, &l);
	return (l + 2);
}
