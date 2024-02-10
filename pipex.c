/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:10:46 by thafranco         #+#    #+#             */
/*   Updated: 2024/02/10 20:37:18 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], envp);
	if (path == NULL)
	{
		ft_free_array(cmd);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free_array(cmd);
		free(path);
		ft_putstr_fd("pipex: command not found.: ", 2);
		exit(1);
	}
}

void	parent_process(char **av, int *fd, char **envp)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_putstr_fd("Error opening outfile, permission denied error\n", 2);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(av[3], envp);
}

void	child_process(char **av, int *fd, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
	{
		ft_putstr_fd("Error opening infile\n", 2);
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	ft_execute(av[2], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Error using pipe");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error forking process");
			exit(1);
		}
		if (pid == 0)
			child_process(av, fd, envp);
		parent_process(av, fd, envp);
		close(fd[0]);
		close(fd[1]);
	}
	else
		ft_putstr_fd("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\n ", 2);
	exit(1);
}
