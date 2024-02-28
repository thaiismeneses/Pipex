/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:10:46 by thfranco         #+#    #+#             */
/*   Updated: 2024/02/28 10:58:46 by thfranco         ###   ########.fr       */
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
		ft_putstr_fd(cmd[0], 2);
		print_error("command does not exits.\n");
		ft_free_tab(cmd);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd(cmd[0], 2);
		print_error("command not found.\n");
		ft_free_tab(cmd);
		free(path);
	}
}

void	second_process(char **av, int *fd, char **envp)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		print_error("opening outfile\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(av[3], envp);
}

void	first_process(char **av, int *fd, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		print_error("opening infile\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	ft_execute(av[2], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			print_error("Error using pipe");
		pid = fork();
		fork_check(pid);
		if (pid == 0)
			first_process(av, fd, envp);
		pid2 = fork();
		fork_check(pid2);
		if (pid2 == 0)
			second_process(av, fd, envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		print_error("How to use: ./pipex file1 \"cmd1\" \"cmd2\" file2\n ");
}
