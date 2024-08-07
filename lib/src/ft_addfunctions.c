/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 19:51:53 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:12:25 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putchar_rtn(char c, int *input_count)
{
	write(1, &c, 1);
	(*input_count)++;
}

void	ft_putstr_rtn(char *s, int *input_count)
{
	if (!s)
		*input_count += write(1, "(null)", 6);
	else
		*input_count += write(1, s, ft_strlen(s));
}

void	ft_putnbr_base(unsigned long long n, char *base,
		int *input_count, char c)
{
	if (c == 'p')
	{
		if (n != 0)
			ft_putstr_rtn("0x", input_count);
		else if (n == 0)
		{
			ft_putstr_rtn("(nil)", input_count);
			return ;
		}
		c++;
	}
	if (c != 'p')
	{
		if (n >= 16)
			ft_putnbr_base(n / 16, base, input_count, c);
		ft_putchar_rtn(base[n % 16], input_count);
	}
}

void	ft_putnbr(int n, int *input_count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			*input_count += 11;
			return ;
		}
		n = -n;
		ft_putchar_rtn('-', input_count);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, input_count);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_rtn(n + '0', input_count);
}

void	ft_putnbr_unsigned(unsigned int n, int *input_count)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, input_count);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_rtn(n + '0', input_count);
}
