/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:11:35 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:38:43 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_filename(int size, char *filename)
{
	char	**res;
	int		i;

	i = 0;
	if (size != 1)
		exit(0);
	res = ft_split(filename, '.');
	while (res[i])
		i++;
	if (ft_strcmp(res[i - 1], "ber") != 0)
	{
		ft_free(res);
		error("invalid filename", NULL);
	}
	ft_free(res);
}

void	check_player_exit(t_vars *vars, char **map, char flag)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == flag)
				counter++;
			j++;
		}
		i++;
	}
	if (counter != 1)
		error("your map must at least have 1 player, 1 coin and 1 exit", vars);
}

void	check_coins(t_vars *vars, char **map, char flag)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == flag)
				counter++;
			j++;
		}
		i++;
	}
	if (counter < 1)
		error("your map must at least have 1 player, 1 coin and 1 exit", vars);
}
