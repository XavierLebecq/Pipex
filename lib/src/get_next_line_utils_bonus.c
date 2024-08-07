/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:13:04 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/24 22:46:33 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_find_nl(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] != '\0' && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return (1);
			i += 1;
		}
		lst = lst->next;
	}
	return (0);
}

t_list	*ft_listlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize_nl(t_list *lst)
{
	int	i;
	int	j;

	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i] != '\0')
		{
			if (lst->content[i] == '\n')
			{
				j += 1;
				return (j);
			}
			i += 1;
			j += 1;
		}
		lst = lst->next;
	}
	return (j);
}

void	ft_rest(t_list **lst)
{
	int		i;
	int		j;
	char	*rest;
	t_list	*lst_rest;
	t_list	*last_lst;

	i = 0;
	j = 0;
	if (!*lst)
		return ;
	rest = malloc(BUFFER_SIZE + 1);
	lst_rest = malloc(sizeof(t_list));
	if (!lst_rest || !rest)
		return ;
	last_lst = ft_listlast(*lst);
	while (last_lst->content[i] != '\0' && last_lst->content[i] != '\n')
		i += 1;
	while (last_lst->content[i] != '\0' && last_lst->content[++i])
		rest[j++] = last_lst->content[i];
	rest[j] = '\0';
	lst_rest->content = rest;
	lst_rest->next = NULL;
	ft_clear_lst(lst, lst_rest, rest);
}

void	ft_clear_lst(t_list **lst, t_list *lst_rest, char *rest)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
	if (lst_rest->content[0])
	{
		*lst = lst_rest;
	}	
	else
	{
		free(rest);
		free(lst_rest);
	}	
}
