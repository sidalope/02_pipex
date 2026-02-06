/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:52 by abisani           #+#    #+#             */
/*   Updated: 2026/02/06 11:28:25 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	print_usage(void)
{
	ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 ... cmdn outfile\n",
		STDERR_FILENO);
	ft_putstr_fd("       ./pipex here_doc LIMITER cmd1 cmd2 outfile\n",
		STDERR_FILENO);
}

static void	clean_up(t_data *data)
{
	if (data->pipes)
		free(data->pipes);
	if (data->pids)
		free(data->pids);
}

void	error_out(char *error_msg, t_data *data)
{
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	close_all_pipes(data);
	clean_up(data);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *env[])
{
	t_data	data;
	int		exit_status;
	
	exit_status = 0;
	if (argc < 5)
	{
		ft_printf("less the 5\n");
		return (print_usage(), 1);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
			return (print_usage(), 1);
	}
	init(argc, argv, env, &data);
	exit_status = parent_process(&data);
	clean_up(&data);
	return (exit_status);
}
