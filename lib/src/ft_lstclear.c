/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:08:44 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:13:18 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_lstclear(t_libft **lst, void (*del)(void *))
{
	if (lst && *lst)
	{
		ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
		*lst = 0;
	}
}
