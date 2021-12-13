/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:24:57 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/13 22:13:17 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

unsigned int	ft_intlen(int n)
{
	unsigned int	len;
	unsigned int	un;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	un = n;
	if (un == 0)
		len++;
	while (un > 0)
	{
		len++;
		un /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	un;
	char			*res;

	i = ft_intlen(n);
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	un = n;
	res[i--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (un > 0)
	{
		res[i--] = '0' + un % 10;
		un /= 10;
	}
	return (res);
}


int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	if (c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	check_sign(const char *str, int i, int *neg)
{
	int	f;

	f = 0;
	if ((str[i] == '-' || str[i] == '+') && !f)
	{
		if (str[i] == '-')
			*neg = -1;
		i++;
		f++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (is_space(nptr[i]))
		i++;
	i = check_sign(nptr, i, &neg);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += (nptr[i] - '0');
		i++;
		if (nb > 2147483647 && neg == 1)
			return (-1);
	}
	if (nb < -2147483648 - 1)
		return (0);
	return ((int)nb * neg);
}

char    *ft_dup(const char *s)
{
	char    *dest;
	int        l;
	int        i;

	l = strlen((char *)s);
	dest = malloc (sizeof(char) * (l + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < l)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
static size_t	digit_count(long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int value, int base)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;
	int		sign;

	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	sign = 0;
	if (base == 10 && value < 0)
		sign = 1;
	if (value < 0)
		value = -value;
	if (value == 0)
		return ("0");
	tab_base = (char *)malloc(sizeof(char) * 17);
	tab_base = "0123456789ABCDEF";
	taille = digit_count(value, base);
	taille += (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}


int ft_isinset(char c)
{
	if (c == 'c' || c == 's' || c == 'i')
		return(1);
	return(0);
}

char	*ft_convert(char *s, char c)
{
	if ( c == 's' || c == 'c')
		return (s);
	if (c == 'd')
		return (ft_itoa(ft_atoi(s)));
	if (c == 'p')
		return (ft_itoa_base(ft_atoi(s), 16));
	if (c == 'i')
		return (ft_itoa(ft_atoi(s)));
	if (c == 'u')
		return (ft_itoa(atoi(s)));
	if (c == 'x')
		return (ft_itoa_base(ft_atoi(s), 16));
	return (0);
}

int ft_printf(const char *format, ...)
{
	int     i;
	int     j;
	char	*str;
	char    **print;
	va_list arg;

	print = malloc (strlen(format) * sizeof(char *));
	va_start(arg, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if(ft_isinset(format[i]))
			{
				str = ft_convert(va_arg(arg, char *),format[i]);
				print[j] = ft_dup(str);
				if (!print[j])
				{
					free(print);
					return (-1);
				}
			}
		}
		else
		{
			print[j] = malloc(1);
			if (!print[j])
			{
				free(print);
				return (-1);
			}
			*print[j] = format[i];
		}
		j++;
		i++;
	}
	va_end(arg);
	i = -1;
	while (print[++i])
	{
		j = -1;
		while (print[i][++j])
			write(1, &print[i][j], 1);
	}
	return (i);
}
int main()
{
	printf("test %i", 8);
	printf("\n");
	ft_printf("test %c", 8);
}
