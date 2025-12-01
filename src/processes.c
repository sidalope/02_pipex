/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:18:23 by abisani           #+#    #+#             */
/*   Updated: 2025/12/01 16:04:29 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Redirect any two fds to stdin/stdout
// TODO double check resource closing code
void	redirect_fds(int infile, int outfile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	close(infile);
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	close(outfile);
}

// Check which child is current and execute behaviour
void	execute_child(t_data *data, int pipe_fds[2])
{
	(void)pipe_fds;
	if (data->child_n == 0)
		//read from infile
	else if (data->child_n == data->n_cmds)
		// write to outfile
	else
		// bonus
}

// create pipe (pre bonus)
// fork n_cmds number of children
// TODO: properly init t_data struct
// close pipe ends
// wait for all children
// return last child's exit status
void	execute_pipeline(t_data *data)
{
	
}
