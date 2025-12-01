/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:49 by abisani           #+#    #+#             */
/*   Updated: 2025/12/01 20:41:30 by abisani          ###   ########.fr       */
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
}				t_data;

// Utils
void	free_array(char **array);

// File handling
int		open_infile(char *filename);
int		open_outfile(char *filename);

// Find a command
char	*find_command(char *cmd, char **env);

// Command parsing
void	execute_cmd(char *cmd, char **envp);

#endif