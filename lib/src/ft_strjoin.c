/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:53:56 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:16:43 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		str[j + i] = s2[i];
		i++;
	}
	str[i + j] = '\0';
	return (str);
}
