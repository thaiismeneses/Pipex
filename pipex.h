

#ifndef	PIPEX_H
#	define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

int	open_file(char *file, int in_or_out);
void	ft_free_array(char **array);
char	**ft_split(char const *s, char c);
void	ft_exec(char **cmd, char **envp);
void	parent_process(char **av, int *p_fd, char **envp);
void	child_process(char *av, int *p_fd, char **envp);

#endif
