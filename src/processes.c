/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:18:23 by abisani           #+#    #+#             */
/*   Updated: 2025/12/01 21:36:10 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Redirect any two fds to stdin/stdout
// TODO double check resource closing code
void	redirect_fds(int infile, int outfile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		error_out(strerror(errno));
		exit(1);
	}
	close(infile);
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		error_out(strerror(errno));
		exit(1);
	}
	close(outfile);
}

// Check which child is current and execute behaviour
void	execute_child(t_data *data)//, int pipe_fds[2])
{
	if (data->child_n == 0)
		redirect_fds(data->fd_in, data->pipe[1]);
	else if (data->child_n == data->n_cmds - 1)
		redirect_fds(data->pipe[0], data->fd_out);
	close(data->pipe[0]);
	close(data->pipe[1]);
	close(data->fd_in);
	close(data->fd_out);
	execute_cmd(data->argv[data->child_n + 2], data->env);
}

// fork n_cmds number of children
// close pipe ends
// wait for all children
// return last child's exit status
void	parent_process(t_data *data)
{
	int		pid;

	pid = -1;
	while (data->child_n < data->n_cmds)
	{
		pid = fork();
		if (pid == -1)
			error_out(strerror(errno));
		else if (pid == 0)
			execute_child(data);
		else
		{
			close(data->pipe[0]);
			close(data->pipe[1]);
		}
		data->child_n++;
	}
}
