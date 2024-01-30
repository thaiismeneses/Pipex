/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:10:34 by thafranco         #+#    #+#             */
/*   Updated: 2024/01/30 18:26:33 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);	
}


char	*get_path(char *cmd, char **envp)
{
	int	i;
	char	*path;
	char	**find_path;
	char	*part_path;
	char	**part_cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	find_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (find_path[i])
	{
		part_path = ft_strjoin(find_path[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_array(part_cmd);
			return(path);
		}
		free(path);
		i++;
	}
	ft_free_array(find_path);
	return(cmd);
}
