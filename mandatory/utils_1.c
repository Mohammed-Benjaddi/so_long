/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:31:24 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/01 16:32:15 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;

	if (!*s1 && !s2)
		return (NULL);
	else if (!*s1 && s2)
		return (ft_strdup(s2));
	else if (*s1 && !s2)
		return (ft_strdup(*s1));
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, *s1, s1_len + 1);
	ft_strlcpy(res + s1_len, s2, s1_len + s2_len + 1);
	free(*s1);
	s1 = NULL;
	return (res);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	src_size;
	int	i;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int				i;
	unsigned int	slen;
	char			*res;

	i = 0;
	slen = (unsigned int)ft_strlen(s);
	if (!s || start > slen)
		return (ft_strdup(""));
	if (len > (int)slen || (len < (int)slen && len + (int)start > (int)slen))
		len = (int)slen - (int)start;
	res = (char *)malloc(sizeof(char) * (len) + 1);
	if (res == NULL)
		return (NULL);
	while (i < (int)len && s[start + i] != '\0')
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
