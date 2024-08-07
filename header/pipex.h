/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:16:52 by xlebecq           #+#    #+#             */
/*   Updated: 2024/08/06 21:51:29 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "lib.h"
# include <errno.h>


void	ft_error_msg(char *msg, int *fd);
void	ft_perror_msg(char *msg);
char	*find_path(char *cmd, char **envp);
void	*free_secure(void *ptr);
void	ft_pipe(char *arg, char **envp);
void	ft_process_child(char **argv, int *fd, char **envp);
void	ft_process_parent(char **argv, int *fd, char **envp);
void	free_2d_array(char **array);

#endif
