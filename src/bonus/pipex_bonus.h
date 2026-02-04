/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:49 by abisani           #+#    #+#             */
/*   Updated: 2026/02/04 02:18:26 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../../libft/libft.h"

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**env;
	int		child_n;
	int		n_cmds;
	int		n_pipes;
	int		(*pipes)[2];
	int		fd_in;
	int		fd_out;
	int		*pids;
	int		here_doc;
	int		cmd_offset;
}				t_data;

// Init
void	init(int argc, char *argv[], char *env[], t_data *data);

// Error handling
void	error_out(char *error_msg, t_data *data);

// Utils
void	free_array(char **array);

// File handling
int		open_infile(char *filename);
int		open_outfile(char *filename, t_data *data);
void	handle_here_doc(t_data *data);

// Cmd parsing and execution
void	execute_cmd(char *cmd, char **envp);

// Process execution
void	close_all_pipes(t_data *data);
int		parent_process(t_data *data);

#endif