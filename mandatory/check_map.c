/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:16:19 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:53:44 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_mapdup(char **map, int len)
{
	int		i;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * len + 1);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	is_map_valid(t_vars *vars)
{
	int		x;
	int		y;
	char	**map_copy;

	x = vars->player.x / 65;
	y = vars->player.y / 65;
	check_walls(vars, vars->map_info->map);
	check_player_exit(vars, vars->map_info->map, 'P');
	check_player_exit(vars, vars->map_info->map, 'E');
	map_copy = ft_mapdup(vars->map_info->map, vars->map_info->y_len);
	flood_fill(vars, x, y, map_copy);
	ft_free(map_copy);
	if (vars->map_info->valid_coins != vars->coins.total
		|| vars->map_info->valid_exit != 1)
		error("invalid path", vars);
}

static void	free_and_exit(char **res, char **line, t_vars *vars)
{
	free(*res);
	free(*line);
	error("invalid map", vars);
}

char	**get_map(char *file_name, t_vars *vars)
{
	int		i;
	int		fd;
	char	*res;
	char	*line;
	char	**map;

	i = 0;
	res = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error("file not found", vars);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		res = ft_strjoin(&res, line);
		if (is_empty_line(line))
			free_and_exit(&res, &line, vars);
		free(line);
	}
	map = ft_split(res, '\n');
	return (free(res), map);
}
