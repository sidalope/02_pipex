/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:05:40 by abisiani          #+#    #+#             */
/*   Updated: 2025/09/16 12:48:24 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_unsnbr_fd(unsigned int n, int fd)
{
	unsigned int	num;

	num = 0;
	if (n > 9)
		put_unsnbr_fd(n / 10, fd);
	num = n % 10 + '0';
	write(fd, &num, 1);
}
