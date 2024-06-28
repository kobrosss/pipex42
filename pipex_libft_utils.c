/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_libft_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:37:01 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/06/17 16:39:38 by rkobeliev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	substr_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		if (start + len > s_len)
			substr_len = s_len - start;
		else
			substr_len = len;
	}
	else
		substr_len = 0;
	ptr = malloc(substr_len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, substr_len);
	ptr[substr_len] = '\0';
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s1 || !s2)
	{
		return (NULL);
	}
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
	{
		return (NULL);
	}
	while (*s1)
	{
		result[i++] = *s1++;
	}
	while (*s2)
	{
		result[i++] = *s2++;
	}
	result[i] = '\0';
	return (result);
}
