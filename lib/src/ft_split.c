/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:32:52 by xlebecq           #+#    #+#             */
/*   Updated: 2024/05/31 11:14:23 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	free_letter_array(char **letter)
{
	size_t	i;

	i = 0;
	if (!letter)
		return ;
	while (letter[i])
	{
		free(letter[i]);
		i++;
	}
	free(letter);
}

size_t	ft_countsletter(const char *s, char c)
{
	size_t	letter;

	letter = 0;
	while (*s)
	{
		if (*s != c)
		{
			++letter;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (letter);
}

static char	*get_next_word(const char **s, char c)
{
	size_t	len;

	len = 0;
	while (**s && **s != c)
	{
		++len;
		++(*s);
	}
	return (ft_substr(*s - len, 0, len));
}

char	**ft_split(const char *s, char c)
{
	char	**letter;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	letter = malloc(sizeof(char *) * (ft_countsletter(s, c) + 1));
	if (!letter)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			letter[i++] = get_next_word(&s, c);
			if (!letter[i - 1])
			{
				free_letter_array(letter);
				return (NULL);
			}
		}
		else
			++s;
	}
	letter[i] = NULL;
	return (letter);
}
