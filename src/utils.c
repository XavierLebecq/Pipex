/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:30:24 by xlebecq           #+#    #+#             */
/*   Updated: 2024/08/07 21:05:58 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_msg(char *msg, int *fd)
{
	if (fd != NULL)
	{
		if (fd[0] != -1)
			close (fd[0]);
		if (fd[1] != -1)
			close (fd[1]);
	}
	ft_printf ("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_perror_msg(char *msg, int *fd)
{
	if (fd != NULL)
	{
		close(fd[0]);
		close(fd[1]);
	}
	perror(msg);
	exit(EXIT_FAILURE);
}

void	*free_secure(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	free_2d_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
