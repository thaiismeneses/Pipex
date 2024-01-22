#include <unistd.h>
#include <sys/types.h> //fork
#include <stdlib.h> // exit
#include <fcntl.h> // open
#include <stdio.h> // perror

int	main(int ac, char **av, char **envp)
{
	int fd_in;
	int	fd_out;

	if (ac != 5)
	{
		perror("Usage: ./pipex file1 cmd1 cmd2 file2");
		return (1);
	}
	fd_in = open(av[1], O_RDONLY);
	if (fd_in < 0)
		perror("Error opening input file");
	
	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd_out < 0)
		perror("Error opening output file");
	
	int fd[2];

	pipe(fd);
	if (pipe(fd) < 0)
		perror("Error creating a pipe");
	
	pid_t pid;
	pid = fork();

	if (pid < 0)
		perror("Error forking process");
	if (pid == 0) //processo filho
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execve(av[2], &av[2], NULL);
	}
	else
		exit(EXIT_FAILURE);

	close(fd_in);
	close(fd_out);
}
