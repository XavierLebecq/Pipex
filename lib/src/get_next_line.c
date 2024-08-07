/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:59:00 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 14:27:52 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_read(t_list **lst, int fd)
{
	int		read_bytes;
	char	*buffer;

	while (!ft_find_nl(*lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			return (1);
		}
		if (!read_bytes)
		{
			free(buffer);
			return (0);
		}
		buffer[read_bytes] = '\0';
		ft_create_lst(lst, buffer);
	}
	return (0);
}

void	ft_create_lst(t_list **lst, char *buffer)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(buffer);
		return ;
	}
	new->content = buffer;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_listlast(*lst);
		last->next = new;
	}
}

char	*concatenate_lst(t_list *lst)
{
	int		len;
	char	*line;

	if (!lst)
		return (NULL);
	len = ft_lstsize_nl(lst);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_create_line(lst, line);
	return (line);
}

void	ft_create_line(t_list *lst, char *line)
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
				line[j] = '\n';
				line[j + 1] = '\0';
				return ;
			}
			line[j] = lst->content[i];
			j += 1;
			i += 1;
		}
		lst = lst->next;
	}
	line[j] = '\0';
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (ft_read(&lst, fd) == 1)
		return (NULL);
	if (!lst)
		return (NULL);
	line = concatenate_lst(lst);
	ft_rest(&lst);
	return (line);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("usage: %s <file\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf ("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
*/
