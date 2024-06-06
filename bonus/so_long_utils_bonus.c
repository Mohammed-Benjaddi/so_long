/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:55:52 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 17:00:59 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_exit(t_vars *vars, char *path, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error("failed to load PNG", vars);
	vars->exit = mlx_texture_to_image(vars->mlx, texture);
	if (!vars->exit)
		error("failed to convert texture to image", vars);
	if (mlx_image_to_window(vars->mlx, vars->exit, x, y) < 0)
		error("failed to put PNG on window", vars);
	mlx_delete_texture(texture);
}

void	put_textures_on_map(t_vars *vars, char **map)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			draw_map(vars, map[i][j], x, y);
			x += 65;
			j++;
		}
		y += 65;
		i++;
	}
}

int	count_coins(char **map)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	coins_init(t_coins *coins, char **map)
{
	coins->total = count_coins(map);
	coins->eaten = 0;
	coins->rest = coins->total - coins->eaten;
}

void	draw_map(t_vars *vars, char c, int x, int y)
{
	if (c != '1')
		ft_put_asset(vars, "bonus/textures/background.png", x, y);
	if (c == '1')
		ft_put_asset(vars, "bonus/textures/wall.png", x, y);
	else if (c == 'C')
		ft_put_asset(vars, "bonus/textures/coin.png", x, y);
	else if (c == 'E')
		ft_put_exit(vars, "bonus/textures/end.png", x, y);
	else if (c != 'M' && c != 'P' && c != '0')
		error("invalid map", vars);
}
