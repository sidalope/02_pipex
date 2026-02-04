/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:45:17 by abisani           #+#    #+#             */
/*   Updated: 2026/02/04 02:22:52 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* Open infile, return fd, or EOF on error */
int	open_infile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (open("/dev/null", O_RDONLY));
	}
	return (fd);
}

/* Open outfile for writing, return fd or error out on error */
int	open_outfile(char *filename, t_data *data)
{
	int	fd;

	if (data->here_doc)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		error_out(strerror(errno), data);
	}
	return (fd);
}

/* Check whether line matches the heredoc limiter string */
static int	is_limiter(char *line, char *limiter)
{
	int		eof;
	int		limiter_len;

	eof = 0;
	limiter_len = ft_strlen(limiter);
	if (!ft_strncmp(line, limiter, limiter_len))
	{
		if (line[limiter_len] == '\n' || line[limiter_len] == '\0')
		eof = 1;
	}	
	return (eof);
}

/* Reads stdin until limiter, writes into a pipe, sets data->fd_in */
void	handle_here_doc(t_data *data)
{
	char	*line;
	int		heredoc_pipe[2];

	line = NULL;
	if (pipe(heredoc_pipe) == -1)
		error_out("Error: Could not initialize here doc", data);
	while (1)
	{
		ft_printf("\n> ");
		line = get_next_line(STDIN_FILENO);
		if (!line || is_limiter(line, data->argv[2]))
		{
			if (line)
				free(line);
			break ;
		}
		else
		{
			write(heredoc_pipe[1], line, ft_strlen(line));
			free(line);	
		}
	}
	close(heredoc_pipe[1]);
	data->fd_in = heredoc_pipe[0];
}
