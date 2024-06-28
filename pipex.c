/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:59:11 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/06/18 17:55:27 by rkobeliev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

void	execvee(char *cmd, char **env)
{
	char	**str_cmd;
	char	*path;

	if (cmd == NULL || ft_strlen(cmd) == 0)
		exit_checker(1);
	str_cmd = ft_split(cmd, ' ');
	if (str_cmd == NULL || str_cmd == NULL)
	{
		perror("pipex: command parsing error");
		exit(EXIT_FAILURE);
	}
	path = take_path(str_cmd[0], env);
	if (path == NULL)
	{
		perror("pipex: command not found");
		clean_matrix(str_cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, str_cmd, env) == -1)
	{
		perror("pipex: execve error");
		clean_matrix(str_cmd);
		exit(EXIT_FAILURE);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 1);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execvee(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 2);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execvee(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
		exit_checker(1);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(av, p_fd, env);
	waitpid(pid, NULL, 0);
	parent(av, p_fd, env);
}
