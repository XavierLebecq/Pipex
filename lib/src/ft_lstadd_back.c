/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:24:39 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:13:12 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_lstadd_back(t_libft **lst, t_libft *new)
{
	t_libft	*t;

	if (*lst)
	{
		t = ft_lstlast(*lst);
		t->next = &*new;
	}
	else
		*lst = new;
}
