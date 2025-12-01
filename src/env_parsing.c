/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:22:54 by abisani           #+#    #+#             */
/*   Updated: 2025/11/28 22:36:18 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char	*find_command(char *cmd, char **env)
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
