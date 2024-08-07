/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:29:28 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:14:05 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_treat(char c, va_list args, int *input_count)
{
	if (c == 'c')
		ft_putchar_rtn((char)va_arg(args, int), input_count);
	else if (c == 's')
		ft_putstr_rtn((char *)va_arg(args, char *), input_count);
	else if (c == 'p')
		ft_putnbr_base((unsigned long long)va_arg(args, unsigned long long),
			"0123456789abcdef", input_count, c);
	else if (c == 'i' || c == 'd')
		ft_putnbr((int)va_arg(args, int), input_count);
	else if (c == 'u')
		ft_putnbr_unsigned((unsigned int)va_arg(args, unsigned int),
			input_count);
	else if (c == 'x')
		ft_putnbr_base((unsigned int)va_arg(args, unsigned int),
			"0123456789abcdef", input_count, c);
	else if (c == 'X')
		ft_putnbr_base((unsigned int)va_arg(args, unsigned int),
			"0123456789ABCDEF", input_count, c);
	else if (c == '%')
		ft_putchar_rtn('%', input_count);
}

int	ft_printf(const char *input, ...)
{
	char	*input_cpy;
	int		input_count;
	va_list	args;
	size_t	i;

	if (!input || (input[0] == '%' && input[1] == '\0'))
		return (-1);
	input_cpy = ft_strdup(input);
	input_count = 0;
	va_start(args, input);
	i = 0;
	while (input_cpy[i])
	{
		if (input_cpy[i] == '%')
		{
			ft_treat(input_cpy[i + 1], args, &input_count);
			i++;
		}
		else
			ft_putchar_rtn(input_cpy[i], &input_count);
		i++;
	}
	va_end(args);
	free(input_cpy);
	return (input_count);
}
