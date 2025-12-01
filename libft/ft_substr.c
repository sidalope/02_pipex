/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:08:42 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/03 19:56:26 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr_substring;

	i = 0;
	s_len = ft_strlen(s);
	if (len == 0 || start >= s_len)
		return (ft_calloc(1, 1));
	if ((s_len - start) > len)
		ptr_substring = ft_calloc(len + 1, 1);
	else
		ptr_substring = ft_calloc((s_len - start) + 1, 1);
	if (!ptr_substring)
		return (NULL);
	while (s[start + i] && len)
	{
		ptr_substring[i] = s[start + i];
		i++;
		len--;
	}
	return (ptr_substring);
}
