/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:21 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/06/18 20:25:23 by rkobeliev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_HEADER_H
# define PIPEX_HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

void	*ft_free(char **result, size_t position);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_word(char const *s, size_t *first, size_t *last, char c);
void	clean_matrix(char **matrix);
char	*ft_fill(char const *s, size_t first, size_t last);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_getenv(char *name, char **env);
size_t	ft_countwords(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*take_path(char *cmd, char **env);
int		open_file(char *file, int type);
int		exit_checker(int exit_num);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);

#endif
