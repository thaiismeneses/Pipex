/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:10:46 by thafranco         #+#    #+#             */
/*   Updated: 2024/01/31 19:50:03 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (!cmd)
		error();
	path = get_path(cmd[0], envp);
	if (!path)
	{
		ft_free_array(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free_array(cmd);
		free(path);
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		error();
	}
}

void	parent_process(char **av, int *fd, char **envp)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_putstr_fd("Error opening outfile", 2);
		error();
	}
	dup2(fd[0], STDOUT_FILENO);
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
		ft_putstr_fd("Error opening infile", 2);
		error();
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

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\n ", 1);
	}
	else
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
		{
			ft_putstr_fd("Error forking process", 2);
			error();
		}
		if (!pid)
		{
			child_process(av, fd, envp);
		}
		waitpid(pid, NULL, 0);
		parent_process(av, fd, envp);
	}
}
