/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:11:20 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/10 21:35:26 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (!in_word && s[i] != c)
		{
			in_word = 1;
			count++;
		}
		if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*free_split(char **strings, size_t strings_count)
{
	size_t	i;

	i = 0;
	while (i <= strings_count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	ii;
	char	**strings;

	i = 0;
	ii = 0;
	strings = (char **) malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			strings[ii] = malloc(wordlen(s + i, c) + 1);
			if (!strings[ii])
				return (free_split(strings, ii));
			ft_strlcpy(strings[ii], s + i, wordlen(s + i, c) + 1);
			ii++;
			i += wordlen(s + i, c);
		}
		else
			i++;
	}
	strings[ii] = (void *) 0;
	return (strings);
}
