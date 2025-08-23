/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esduman <esduman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:17:20 by esduman           #+#    #+#             */
/*   Updated: 2025/08/23 15:08:05 by esduman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

static void	f_add(char const *s, char *new_arr, size_t *i)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		new_arr[*i] = s[j];
		(*i)++;
		j++;
	}
}

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*cpy;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s) + 1;
	cpy = (char *)malloc(length);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_arr;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	new_arr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_arr)
		return (NULL);
	i = 0;
	f_add(s1, new_arr, &i);
	f_add(s2, new_arr, &i);
	new_arr[i] = '\0';
	return (new_arr);
}
