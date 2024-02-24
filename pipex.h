/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:15:51 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/24 20:38:51 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

void	ft_free_tab(char **tab);
char	**ft_split(char const *s, char c);
char	*get_path(char *av, char **envp);
void	second_process(char **av, int *fd, char **envp);
void	first_process(char **av, int *fd, char **envp);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *find, size_t n);
char	*my_env(char *find, char **envp);
char	*ft_strtrim(char const *s1, char const *set);
void	print_error(char *msg);
void	fork_check(int fork);
int		ft_strcmp(char *s1, char *s2);

#endif
