/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:45:17 by abisani           #+#    #+#             */
/*   Updated: 2025/12/15 12:55:32 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Open infile, return fd, or -1 on error */
int	open_infile(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		error_out(strerror(errno), data);
	}
	return (fd);
}

/* Open outfile for writing, return fd or -1 on error */
int	open_outfile(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		error_out(strerror(errno), data);
	}
	return (fd);
}
