/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:52 by abisani           #+#    #+#             */
/*   Updated: 2025/12/01 20:54:46 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_out(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
}

// Initialise cmd tracking struct
static void	init(int argc, char *argv[], char *env[], t_data *data)
{
	data->argc = argc;
	data->argv = argv;
	data->env = env;
	data->child_n = 0;
	data->n_cmds = argc - 3;
	if (pipe(data->pipe) == -1)
		error_out(strerror(errno));
	data->fd_in = open_infile(argv[1]);
	data->fd_out = open_outfile(argv[4]);
}

int	main(int argc, char *argv[], char *env[])
{
	char	*cmd;

	if (argc != 5)
		return (ft_printf("Usage: infile \"cmd1\" \"cmd2\" outfile\n"), 1);
	cmd = argv[2];
	cmd = find_command(cmd, env);
	if (!cmd)
		return (1);
	ft_printf(cmd);
	ft_printf("\n");

	ft_printf("infile fd: %i\n", open_infile(argv[1]));
	ft_printf("outfile fd: %i\n", open_outfile(argv[4]));
	return (0);
}
