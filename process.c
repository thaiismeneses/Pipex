/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:10:26 by thafranco         #+#    #+#             */
/*   Updated: 2024/01/29 22:10:29 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_exec(char *cmd, char **envp)
{
	char	**new_cmd;
	char	*path;

	new_cmd = ft_split(cmd, ' ');
	path = get_path(new_cmd[0], envp);
	if (execve(path, new_cmd, envp) == -1)
	{
		perror("pipex: command not found: ");
		ft_putendl_fd(new_cmd[0], 2);
		exit(0);
	}
}



void	parent_process(char **av, int *p_fd, char **envp)
{
	int fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	ft_exec(av[3], envp);
}

void	child_process(char **av, int *p_fd, char **envp)
{
	int fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	ft_exec(av[2], envp);
}
