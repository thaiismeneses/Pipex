/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:15:51 by thfranco          #+#    #+#             */
/*   Updated: 2024/01/30 18:22:40 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

int	open_file(char *file, int in_or_out);
void	ft_free_array(char **array);
char	**ft_split(char const *s, char c);
char	*get_path(char *cmd, char **envp);
void	parent_process(char **av, int *p_fd, char **envp);
void	child_process(char **av, int *p_fd, char **envp);
void	ft_putendl_fd(char *s, int fd);
char 	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *find, size_t n);
#endif
