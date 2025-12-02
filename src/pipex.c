/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:52 by abisani           #+#    #+#             */
/*   Updated: 2025/12/02 22:02:10 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_out(char *error_msg, t_data *data)
{
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	close(data->fd_in);
	close(data->fd_out);
	close(data->pipe[0]);
	close(data->pipe[1]);
	exit(EXIT_FAILURE);
}

// Initialise cmd tracking struct
static void	init(int argc, char *argv[], char *env[], t_data *data)
{
	data->argc = argc;
	data->argv = argv;
	data->env = env;
	data->child_n = 0;
	data->n_cmds = argc - 3;
	data->pipe[0] = -1;
	data->pipe[1] = -1;
	if (pipe(data->pipe) == -1)
		error_out(strerror(errno), data);
	data->fd_in = open_infile(argv[1]);
	data->fd_out = open_outfile(argv[4]);
	data->pids[0] = -1;
	data->pids[1] = -1;
}

int	main(int argc, char *argv[], char *env[])
{
	t_data	data;

	if (argc != 5)
		return (ft_printf("Usage: infile \"cmd1\" \"cmd2\" outfile\n"), 1);
	init(argc, argv, env, &data);
	return (parent_process(&data));
}
