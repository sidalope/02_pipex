/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:52 by abisani           #+#    #+#             */
/*   Updated: 2025/11/28 22:38:42 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Initialise cmd tracking struct
// static void	init(int argc, char *argv[], char *env[], t_cmd_data *cmd_data)
// {
// 	cmd_data->argc = argc;
// 	cmd_data->argv = argv;
// 	cmd_data->env = env;
// 	cmd_data->heredoc = 0;
// 	if (ft_strncmp("heredoc", argv[1], 7))
// 		cmd_data->heredoc = 1;
// 	if (!cmd_data->heredoc)
// 		cmd_data->n_cmds = argc - 4;
// 	else
// 		cmd_data->n_cmds = argc - 5;
// }

// infile cmd cmd outfile

// Probably need to check that px_error() doesn't exit leaving memory leaks
// int	main(int argc, char *argv[], char *env[])
// {
// 	pid_t		pid;
// 	t_cmd_data	cmd_data;

// 	if (argc < 5)
// 		return (perror("Insufficient arguments."));
// 	init(argc, argv, env, &cmd_data);
// 	return (0);
// }

// Parent process routine:
// void	parent_routine(pid_t pid)
// {
// 	int	status;

// 	ft_printf("Parent: I'm the parent. PID received from fork = %d\n", pid);
// 	ft_printf("Parent: Waiting for my child with PID [%d].\n", pid);
// 	waitpid(pid, &status, 0); // Wait for child
// 	ft_printf("Parent: My child exited with status %d\n", status);
// 	if (WIFEXITED(status)) // If child exited normally
// 	{
// 		ft_printf("Parent: My child's exit code is %d\n", WEXITSTATUS(status));
// 		if (WEXITSTATUS(status) == EXPECTED_CODE)
// 			ft_printf("Parent: That's the code I expected!\n");
// 		else
// 			ft_printf("Parent: I was not expecting that code...\n");
// 	}
// }


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
