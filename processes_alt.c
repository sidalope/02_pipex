/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_alt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:18:23 by abisani           #+#    #+#             */
/*   Updated: 2025/12/03 13:16:21 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

// Redirect any two fds to stdin/stdout
// TODO double check resource closing code
static void	redirect_fds(int infile, int outfile, t_data *data)
{
	if (dup2(infile, STDIN_FILENO) == -1)
		error_out(strerror(errno), data);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_out(strerror(errno), data);
	close(data->pipe[0]);
	close(data->pipe[1]);
	close(data->fd_in);
	close(data->fd_out);
}

// Check which child is current and execute behaviour
static void	execute_child(t_data *data)
{
	if (data->child_n == 0)
		redirect_fds(data->fd_in, data->pipe[1], data);
	else if (data->child_n == data->n_cmds - 1)
		redirect_fds(data->pipe[0], data->fd_out, data);
	execute_cmd(data->argv[data->child_n + 2], data->env);
}

// fork n_cmds number of children
// as parent: for every cmd, fork, add pid to data, wait for it to 
//		complete. keep forking.
// If waiting sequentially, doesn't the pipe get closed before
//		the next process starts and claims it? No. Could be similar
//		errors, however.
int	fork_children(t_data *data)
{
	int		pid;
	int		wstatus;
	int		exit_status;

	pid = -1;
	wstatus = -1;
	exit_status = EXIT_FAILURE;
	close(data->pipe[0]);
	close(data->pipe[1]);
	close(data->fd_in);
	close(data->fd_out);
	while (data->child_n < data->n_cmds)
	{
		pid = fork();
		if (pid == -1)
			error_out(strerror(errno), data);
		else if (pid == 0)
			execute_child(data);
		else
		{
			data->pids[data->child_n] = pid;
			if (waitpid(pid, &wstatus, 0) == -1)
				break ;
			if (data->child_n == data->n_cmds -1)
			{
				if (WIFEXITED(wstatus))
					exit_status = WEXITSTATUS(wstatus);
			}
		}
		data->child_n++;
	}
	data->child_n--;
	return (exit_status);
}

void	clean_and_exit(int failed_child, t_data *data, int wstatus)
{
	int		i;

	i = failed_child;
	while(i < data->child_n)
	{
		// fir every child
		// close fds (pipe)
		// close pids
		i++;
	}
	exit(wstatus);
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
	while (i <= data->child_n)
	{
		waitpid(data->pids[i], &wstatus, 0);
		// if (!WIFEXITED(wstatus))
		// 	clean_and_exit(i, data, wstatus);
		if (i == data->child_n)
		{
			if (WIFEXITED(wstatus))
				exit_status = WEXITSTATUS(wstatus);
		}
		i++;
	}
	return (exit_status);
}
