/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:53:17 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/10 21:33:30 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	int		len_n;
	char	*i_str;

	num = n;
	len_n = intlen(n);
	i_str = (char *) ft_calloc(len_n + 1, 1);
	if (!i_str)
		return (NULL);
	if (num == 0)
	{
		i_str[0] = '0';
		return (i_str);
	}
	if (num < 0)
	{
		i_str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		i_str[--len_n] = num % 10 + '0';
		num /= 10;
	}
	return (i_str);
}
