/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:12:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/10 21:36:25 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len && (i + ii) < len)
	{
		if (big[i + ii] == little[ii])
		{
			ii++;
			if (little[ii] == '\0')
				return ((char *) big + i);
		}
		else
		{
			ii = 0;
			i++;
		}
	}
	return (NULL);
}
