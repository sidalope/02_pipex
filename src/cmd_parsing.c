/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:54 by abisani           #+#    #+#             */
/*   Updated: 2025/12/03 13:45:42 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

// Return the entirety of PATH as a string
static char	*get_env_path(char **env)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
		{
			path = env[i];
			break ;
		}
		i++;
	}
	return (path);
}

// Find a supplied command in PATH
static char	*find_command(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*cmd_path;

	i = 0;
	path = ft_split(get_env_path(env) + 5, ':');
	if (!path)
		return (perror("Path error"), NULL);
	cmd_path = NULL;
	cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i++], cmd);
		if (!access(cmd_path, X_OK))
		{
			free(cmd);
			free_array(path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free(cmd);
	free_array(path);
	return (NULL);
}

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
		ft_putstr_fd(cmd_argv[0], 2);
		ft_putstr_fd(": command not found", 2);
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
