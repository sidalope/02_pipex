/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:16:33 by abisiani          #+#    #+#             */
/*   Updated: 2025/09/16 12:14:10 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_p(void *p)
{
	int		i;
	int		len;
	int		started;

	i = sizeof(size_t) * 2 - 1;
	len = 2;
	started = 0;
	if ((size_t)p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (i >= 0)
	{
		if (started || "0123456789abcdef"[((size_t)p >> (i * 4)) & 0xF] != '0')
		{
			write(1, &"0123456789abcdef"[((size_t)p >> (i * 4)) & 0xF], 1);
			len++;
			started = 1;
		}
		i--;
	}
	return (len);
}
