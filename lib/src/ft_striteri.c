/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:57:01 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:14:32 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, s + i);
			i++;
		}
	}
}
