/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:53:28 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:13:37 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_libft	*ft_lstmap(t_libft *lst, void *(*f)(void *), void (*del)(void *))
{
	t_libft	*i;
	t_libft	*tmp;

	i = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&i, del);
			return (0);
		}
		ft_lstadd_back(&i, tmp);
		lst = lst->next;
	}
	return (i);
}
