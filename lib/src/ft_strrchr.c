/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:05:59 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:17:11 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((unsigned char)c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
