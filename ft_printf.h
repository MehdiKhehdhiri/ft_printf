/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhedhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:31:04 by mkhedhir          #+#    #+#             */
/*   Updated: 2021/12/17 13:13:16 by mkhedhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(char const *s, ...);
unsigned int	ft_intlen(long n);
unsigned int	ft_pointer_intlen(unsigned long long n);
int				ft_putstr(char *s);
int				ft_putchar(int c);
void			ft_integer(int n, int *l);
int				ft_unsigned(unsigned int n);
int				ft_abs(int n);
int				ft_neg_hex(unsigned int n, char *hex);
void			ft_hex(unsigned int n, char x, int *l);
int				ft_pointer_neg_hex(unsigned long long n, char *hex);
void			ft_pointer_hex(unsigned long long n, int *l);
int				ft_pointer(unsigned long long ptr);

#endif
