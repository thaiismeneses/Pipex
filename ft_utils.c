/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:22:02 by thfranco         #+#    #+#             */
/*   Updated: 2024/02/24 20:37:26 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	fork_check(int fork)
{
	if (fork == -1)
		print_error("forking process was not successful.\n");
}

char	*my_env(char *find, char **envp)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strcmp(sub, find) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

void	print_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (errno != 0)
		perror("");
	exit(1);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;
	char	*part_path;
	char	**s_cmd;

	paths = ft_split(my_env("PATH", envp), ':');
	s_cmd = ft_split(cmd, ' ');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, s_cmd[0]);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_tab(paths);
			return (path);
		}
		else
			free(path);
	}
	ft_free_tab(paths);
	ft_free_tab(s_cmd);
	return (cmd);
}
