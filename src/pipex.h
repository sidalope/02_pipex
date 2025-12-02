/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:49 by abisani           #+#    #+#             */
/*   Updated: 2025/12/02 22:51:50 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**env;
	int		child_n;
	int		n_cmds;
	int		pipe[2];
	int		fd_in;
	int		fd_out;
	int		pids[2];
}				t_data;

// Error handling
void	error_out(char *error_msg, t_data *data);

// Utils
void	free_array(char **array);

// File handling
int	open_infile(char *filename, t_data *data);
int	open_outfile(char *filename, t_data *data);

// Cmd parsing and execution
void	execute_cmd(char *cmd, char **envp);

// Process execution
int		parent_process(t_data *data);

#endif