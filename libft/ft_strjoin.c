/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:51:24 by abisiani          #+#    #+#             */
/*   Updated: 2025/09/02 09:45:26 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	ii;
	char	*new_str;

	i = 0;
	ii = 0;
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = (char) s1[i];
		i++;
	}
	while (s2[ii])
	{
		new_str[i] = (char) s2[ii];
		i++;
		ii++;
	}
	new_str[i] = '\0';
	return (new_str);
}
