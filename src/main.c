/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:54:45 by xlebecq           #+#    #+#             */
/*   Updated: 2024/08/08 12:12:49 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	int		i;
	char	**dir_path;
	char	*join_path;

	i = 0;
	if (!envp || !envp[0])
		ft_perror_msg("Error: envp is NULL", NULL);
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	dir_path = ft_split(envp[i] + 5, ':');
	i = -1;
	while (dir_path[++i])
	{
		join_path = ft_strjoin(dir_path[i], "/");
		path = ft_strjoin(join_path, cmd);
		free(join_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	free_2d_array(dir_path);
	return (NULL);
}

void	ft_pipe(char *arg, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(arg, ' ');
	if (!cmd || !cmd[0])
	{
		free_2d_array(cmd);
		ft_perror_msg("Error: empty command", NULL);
	}
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_2d_array(cmd);
		ft_perror_msg("Error: command not found", NULL);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_2d_array(cmd);
		ft_perror_msg("Error: execve failed", NULL);
	}
}

void	ft_process_child(char **argv, int *fd, char **envp)
{
	int	input_file;

	input_file = open (argv[1], O_RDONLY);
	if (input_file == -1)
	{
		ft_perror_msg("Error opening input_file", fd);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror_msg("Error redirecting stdout", fd);
	if (dup2(input_file, STDIN_FILENO) == -1)
		ft_perror_msg("Error redirecting stdin", fd);
	close(fd[0]);
	close(fd[1]);
	close(input_file);
	ft_pipe(argv[2], envp);
	exit (EXIT_SUCCESS);
}

void	ft_process_parent(char **argv, int *fd, char **envp)
{
	int	output_file;

	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1)
		ft_perror_msg("Error opening output_file", fd);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror_msg("Error redirecting stdin", fd);
	if (dup2(output_file, STDOUT_FILENO) == -1)
		ft_perror_msg("Error redirecting stdout", fd);
	close(fd[0]);
	close(fd[1]);
	close(output_file);
	ft_pipe(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (argc != 5)
		ft_perror_msg("Error: invalid number of arguments.", NULL);
	if (pipe(fd) == -1)
	{
		ft_perror_msg("Error creating pipe", NULL);
	}
	pid = fork();
	if (pid == -1)
		ft_perror_msg("Error forking", NULL);
	if (pid == 0)
		ft_process_child(argv, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror_msg("Error forking", NULL);
	if (pid2 == 0)
		ft_process_parent(argv, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (EXIT_SUCCESS);
}
