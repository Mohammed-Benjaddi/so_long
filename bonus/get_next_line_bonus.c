/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:55:00 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/26 13:25:41 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1)
	{
		res = ft_strdup(s2);
		if (!res)
			return (NULL);
		return (res);
	}
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy_gnl(res, s1);
	ft_strlcat_gnl(res + s1_len, s2);
	free(s1);
	return (res);
}

static char	*found_new_line(char **res, int index)
{
	char	*line;
	char	*temp_res;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * index + 1);
	if (!line)
		return (NULL);
	temp_res = ft_strdup(*res + (index));
	if (!temp_res)
		return (NULL);
	while (i < index)
	{
		line[i] = *(*res + i);
		i++;
	}
	line[i] = '\0';
	free(*res);
	*res = ft_strdup(temp_res);
	if (!*res)
		return (NULL);
	free(temp_res);
	return (line);
}

static char	*handle_res(char **res, int index)
{
	char	*line;
	char	*temp;

	temp = NULL;
	if (index != -1)
	{
		line = found_new_line(res, index);
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_strdup(*res);
		if (!line)
			return (NULL);
		free(*res);
		*res = NULL;
	}
	if (!ft_strlen(line))
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static char	*current_line(int fd, char **res)
{
	char	*buff;
	int		counter;
	int		newline_in_buff;

	buff = NULL;
	newline_in_buff = -1;
	while (newline_in_buff == -1)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buff == NULL)
			return (NULL);
		counter = read(fd, buff, BUFFER_SIZE);
		buff[counter] = '\0';
		if (counter <= 0)
		{
			free(buff);
			break ;
		}
		newline_in_buff = ft_strchr_gnl(buff, '\n');
		*res = ft_strjoin_gnl(*res, buff);
		if (!res)
			return (NULL);
		free(buff);
	}
	return (handle_res(res, ft_strchr_gnl(*res, '\n')));
}

char	*get_next_line(int fd)
{
	static char	*res;

	if (fd < 0 || read(fd, "", 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	return (current_line(fd, &res));
}
