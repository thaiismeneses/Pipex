/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:16:02 by thafranco         #+#    #+#             */
/*   Updated: 2024/01/29 21:53:50 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		perror("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\n Error");
		return (1);
	}
	if (pipe(p_fd) == -1)
	{
		perror("Error creating pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error forking process");
		exit(1);
	}
	if (!pid)
	{
		child_process(av, p_fd, envp)
	}
	parent_process(av, p_fd, envp);
}
