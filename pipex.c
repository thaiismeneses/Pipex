/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:10:46 by thafranco         #+#    #+#             */
/*   Updated: 2024/01/30 19:06:35 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	open_file(char *file, int in_or_out)
{
	int fd_in;
	int fd_out;
	
	if (in_or_out == 0)
	{
		fd_in = open(file, O_RDONLY);
		if (fd_in == -1)
		{
			perror("Error opening file 1");
			exit(0);
		}
		return(fd_in);
	}
	if (in_or_out == 1)
	{
		fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd_out == -1)
		{
			perror("Error opening file 2");
			exit(0);
		}
		return (fd_out);
	}
}

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
		child_process(av, p_fd, envp);
	}
	parent_process(av, p_fd, envp);
}

