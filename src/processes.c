/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:18:23 by abisani           #+#    #+#             */
/*   Updated: 2025/12/02 22:06:52 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Redirect any two fds to stdin/stdout
// TODO double check resource closing code
static void	redirect_fds(int infile, int outfile, t_data *data)
{
	if (dup2(infile, STDIN_FILENO) == -1)
		error_out(strerror(errno), data);
	close(infile);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_out(strerror(errno), data);
	close(outfile);
}

// Check which child is current and execute behaviour
static void	execute_child(t_data *data)
{
	if (data->child_n == 0)
		redirect_fds(data->fd_in, data->pipe[1], data);
	else if (data->child_n == data->n_cmds - 1)
		redirect_fds(data->pipe[0], data->fd_out, data);
	close(data->pipe[0]);
	close(data->pipe[1]);
	close(data->fd_in);
	close(data->fd_out);
	execute_cmd(data->argv[data->child_n + 2], data->env);
}

// fork n_cmds number of children
static void	fork_children(t_data *data)
{
	int		pid;

	pid = -1;
	while (data->child_n < data->n_cmds)
	{
		pid = fork();
		if (pid == -1)
			error_out(strerror(errno), data);
		else if (pid == 0)
			execute_child(data);
		else
			data->pids[data->child_n] = pid;
		data->child_n++;
	}
	data->child_n--;
}

// close pipe ends
// wait for all children
// return last child's exit status
int	parent_process(t_data *data)
{
	int		i;
	int		wstatus;
	int		exit_status;

	i = 0;
	wstatus = -1;
	exit_status = EXIT_FAILURE;
	fork_children(data);
	close(data->pipe[0]);
	close(data->pipe[1]);
	while (i <= data->child_n)
	{
		waitpid(data->pids[i], &wstatus, 0);
		if (i == data->child_n)
		{
			if (WIFEXITED(wstatus))
				exit_status = WEXITSTATUS(wstatus);
		}
		i++;
	}
	return (exit_status);
}
