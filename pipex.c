/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:10:46 by thafranco         #+#    #+#             */
/*   Updated: 2024/01/29 22:10:48 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	open_file(char *file, int in_or_out)
{
	int fd_in;
	int fd_out;
	
	if (in_or_out == 0)
	{
		fd_in = open(av[1], O_RDONLY);
		if (fd_in == -1)
		{
			perror("Error opening file 1")
			exit(0);
		}
		return(fd_in);
	}
	if (in_or_out == 1)
	{
		fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd_out == -1)
		{
			ft_error("Error opening file 2");
			exit(0);
		}
		return (fd_out);
	}
}



