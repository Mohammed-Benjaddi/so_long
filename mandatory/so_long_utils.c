/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:55:52 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/01 18:26:11 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_asset(void *param, char *path, int x, int y)
{
	t_vars			*vars;
	mlx_image_t		*png;
	mlx_texture_t	*texture;

	vars = param;
	texture = mlx_load_png(path);
	if (!texture)
		error("failed to load PNG", vars);
	png = mlx_texture_to_image(vars->mlx, texture);
	if (!png)
		error("failed to convert texture to image", vars);
	if (mlx_image_to_window(vars->mlx, png, x, y) < 0)
		error("failed to put PNG on window", vars);
	mlx_delete_texture(texture);
}

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

void	draw_map(t_vars *vars, char c, int x, int y)
{
	if (c != '1')
		ft_put_asset(vars, "mandatory/textures/background.png", x, y);
	if (c == '1')
		ft_put_asset(vars, "mandatory/textures/wall.png", x, y);
	else if (c == 'C')
		ft_put_asset(vars, "mandatory/textures/coin.png", x, y);
	else if (c == 'E')
		ft_put_exit(vars, "mandatory/textures/end.png", x, y);
	else if (c != 'P' && c != '0')
		error("invalid map", vars);
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
