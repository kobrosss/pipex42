/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:59:14 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/06/18 17:58:44 by rkobeliev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

int	open_file(char *file, int type)
{
	int	fd;

	if (type == 1)
		fd = open(file, O_RDONLY, 0777);
	if (type == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(0);
	return (fd);
}

int	exit_checker(int exit_num)
{
	if (exit_num == 1)
		write(2, "./pipex infile cmd cmd outfile\n", 31);
	exit(0);
}

void	clean_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		path = ft_substr(env[i], 0, j);
		if (ft_strcmp(path, name) == 0)
		{
			free(path);
			return ((env[i] + j + 1));
		}
		free(path);
		i++;
	}
	return (NULL);
}

char	*take_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**all_p;
	char	*path_p;
	char	**str_cmd;

	i = -1;
	all_p = ft_split(ft_getenv("PATH", env), ':');
	str_cmd = ft_split(cmd, ' ');
	while (all_p[++i])
	{
		path_p = ft_strjoin(all_p[i], "/");
		exec = ft_strjoin(path_p, str_cmd[0]);
		free(path_p);
		if (access(exec, F_OK | X_OK) == 0)
		{
			clean_matrix(str_cmd);
			return (exec);
		}
		free(exec);
	}
	clean_matrix(all_p);
	clean_matrix(str_cmd);
	return (cmd);
}
