/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:16:06 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:13:41 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_libft	*ft_lstnew(void *content)
{
	t_libft	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (0);
	ret->content = content;
	ret->next = 0;
	return (ret);
}
