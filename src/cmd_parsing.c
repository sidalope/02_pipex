/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:34:25 by abisani           #+#    #+#             */
/*   Updated: 2025/12/01 21:04:35 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**parse_cmd(char *cmd_str)
{
	char	**cmd_argv;

	cmd_argv = ft_split(cmd_str, ' ');
	if (!cmd_argv || !cmd_argv[0])
	{
		ft_putstr_fd("Failed to parse command\n", 2);
		if (cmd_argv)
			free_array(cmd_argv);
		exit(EXIT_FAILURE);
	}
	return (cmd_argv);
}

void	execute_cmd(char *cmd_str, char **env)
{
	char	**cmd_argv;
	char	*cmd_path;

	cmd_argv = parse_cmd(cmd_str);
	cmd_path = find_command(cmd_argv[0], env);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found\n", 2);
		ft_putstr_fd(cmd_argv[0], 2);
		ft_putstr_fd("\n", 2);
		free_array(cmd_argv);
		exit(127);
	}
	if (execve(cmd_path, cmd_argv, env) == -1)
	{
		perror(cmd_argv[0]);
		free(cmd_path);
		free_array(cmd_argv);
		exit(EXIT_FAILURE);
	}
}
