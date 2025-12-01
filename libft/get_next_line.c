/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:45:39 by abisani           #+#    #+#             */
/*   Updated: 2025/09/22 15:29:53 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reset_buffer(char *buf)
{
	size_t	i;
	size_t	line_size;
	char	*tmp_buf;

	i = 0;
	line_size = 0;
	while (buf[line_size] != '\n' && buf[line_size] != '\0')
		line_size++;
	if (buf[line_size] == '\0')
	{
		free(buf);
		return (NULL);
	}
	line_size++;
	tmp_buf = ft_calloc(ft_strlen(buf + line_size) + 1, 1);
	if (!tmp_buf)
	{
		free(buf);
		return (NULL);
	}
	while (buf[line_size])
		tmp_buf[i++] = buf[line_size++];
	free(buf);
	return (tmp_buf);
}

static char	*parse_buffer(char	*buf)
{
	char	*next_line;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	i = 0;
	while (buf[line_len] != '\n' && buf[line_len] != '\0')
		line_len++;
	if (buf[line_len] == '\n')
		line_len++;
	next_line = ft_calloc(line_len + 1, 1);
	if (!next_line)
		return (NULL);
	while (i < line_len)
	{
		next_line[i] = buf[i];
		i++;
	}
	return (next_line);
}

static ssize_t	read_into_buffer(int fd, char **static_buffer)
{
	char	*temp_buf;
	ssize_t	bytes_read;

	temp_buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp_buf)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (ft_strchr(*static_buffer, '\n'))
			return (free(temp_buf), bytes_read);
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == -1)
			break ;
		temp_buf[bytes_read] = 0;
		if (!ft_gnl_strjoin(static_buffer, temp_buf))
			bytes_read = -1;
	}
	free(temp_buf);
	return (bytes_read);
}

void	*free_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*next_line;
	ssize_t			bytes_read;

	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free_buffer(&buffer));
	bytes_read = read_into_buffer(fd, &buffer);
	if (bytes_read == -1 || (!bytes_read && buffer[0] == 0))
		return (free_buffer(&buffer));
	next_line = parse_buffer(buffer);
	if (next_line == NULL)
		return (free_buffer(&buffer));
	buffer = reset_buffer(buffer);
	return (next_line);
}
