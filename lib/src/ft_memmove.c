/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:43:33 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:13:58 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dst_char;
	const char	*src_char = (const char *)src;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_char = (char *)dst;
	if (src_char < dst_char)
	{
		while (n--)
			*(dst_char + n) = *(src_char + n);
	}
	else
	{
		while (n--)
			*dst_char++ = *src_char++;
	}
	return (dst);
}
