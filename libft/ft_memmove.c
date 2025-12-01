/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:34:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/03 13:56:06 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (src < dest)
		while (n--)
			d[n] = s[n];
	return (dest);
}
