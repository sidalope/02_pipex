/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:52:10 by abisani           #+#    #+#             */
/*   Updated: 2026/02/03 16:52:12 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// TODO: clean up partial lists of pipes
static void	create_pipes(t_data *data)
{
	int		i;

	i = 0;
	data->pipes = malloc(sizeof(int[2]) * data->n_pipes);
	if (!data->pipes)
		error_out("Error: Malloc failure", data);
	while (i < data->n_pipes)
	{
		if (pipe(data->pipes[i]) == -1)
			error_out("Error: pipe utility failure", data);
		i++;
	}
}
// error_out(strerror(errno), data); ?
static void	init_normal(t_data *data)
{
	data->cmd_offset = 2;
	data->n_cmds = data->argc - 3;
	data->n_pipes = data->n_cmds - 1;
	create_pipes(data);
	data->pids = malloc(data->n_cmds * sizeof(int));
	if (!data->pids)
		error_out("Error: Malloc failure", data);
	data->fd_in = open_infile(data->argv[1]);
	data->fd_out = open_outfile(data->argv[data->argc - 1], data);
}

static void	init_here_doc(t_data *data)
{
	data->here_doc = 1;
	data->cmd_offset = 3;
	data->n_cmds = data->argc - 4;
	data->n_pipes = data->n_cmds - 1;
	create_pipes(data);
	data->pids = malloc(sizeof(int) * data->n_cmds);
	if (!data->pids)
		error_out("Error: Malloc failure", data);
	handle_here_doc(data);
	data->fd_out = open_outfile(data->argv[data->argc - 1], data);
}

// Initialise cmd tracking struct
void	init(int argc, char *argv[], char *env[], t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->argc = argc;
	data->argv = argv;
	data->env = env;
	data->fd_in = -1;
	data->fd_out = -1;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		init_here_doc(data);
	else
		init_normal(data);
}

