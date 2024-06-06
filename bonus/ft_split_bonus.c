/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:20:42 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/26 13:25:01 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_words(const char *s, char del)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == del)
			i++;
		if (s[i] && s[i] != del)
			words++;
		while (s[i] && s[i] != del)
			i++;
	}
	return (words);
}

static int	wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**set_free(char **res, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(res[j]);
		j++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (i < words)
	{
		while (*s != '\0' && *s == c)
			s++;
		res[i] = ft_substr(s, 0, wordlen((char *)s, c));
		s += wordlen((char *)s, c);
		if (!res[i])
			return (set_free(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}
