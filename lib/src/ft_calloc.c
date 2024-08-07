/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:40:28 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:12:46 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*ret;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total = nmemb * size;
	if (total / nmemb != size && total / size != nmemb)
		return (NULL);
	ret = (char *)malloc(total);
	if (ret == NULL)
		ret = NULL;
	else
		ft_bzero(ret, total);
	return (ret);
}
