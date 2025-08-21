/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esduman <esduman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:59:57 by esduman           #+#    #+#             */
/*   Updated: 2025/08/21 23:14:55 by esduman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*f_readcache(int fd, char *cache)
{
	char	*buffer;
	int		s;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(cache), NULL);
	s = 1;
	while (!ft_strchr(cache, '\n') && s > 0)
	{
		s = read(fd, buffer, BUFFER_SIZE);
		if (s < 0)
		{
			free(buffer);
			return (free(cache), NULL);
		}
		buffer[s] = '\0';
		temp = ft_strjoin(cache, buffer);
		free(cache);
		if (!temp)
			return (free(buffer), NULL);
		cache = temp;
	}
	free(buffer);
	return (cache);
}

static char	*f_getline(char *cache)
{
	char	*s;
	int		i;

	i = 0;
	if (!cache || !cache[0])
		return (NULL);
	while (cache[i] && cache[i] != '\n')
		i++;
	s = malloc((i + (cache[i] == '\n') + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
	{
		s[i] = cache[i];
		i++;
	}
	if (cache[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

static char	*f_rmcache(char *cache)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (!cache[i])
	{
		free(cache);
		return (NULL);
	}
	i++;
	new = malloc(sizeof(char) * (ft_strlen(cache) - i + 1));
	if (!new)
	{
		free(cache);
		return (NULL);
	}
	j = 0;
	while (cache[i])
		new[j++] = cache[i++];
	new[j] = '\0';
	free(cache);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!cache)
		cache = ft_strdup("");
	if (!cache)
		return (NULL);
	cache = f_readcache(fd, cache);
	if (!cache)
		return (NULL);
	line = f_getline(cache);
	if (!line)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	cache = f_rmcache(cache);
	return (line);
}
