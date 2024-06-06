/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:53 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 17:00:59 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_background(t_vars *vars, int y, int x)
{
	mlx_image_t		*png;
	mlx_texture_t	*texture;

	if (vars->map_info->map[y][x] == 'X')
	{
		vars->map_info->map[y][x] = 'E';
		texture = mlx_load_png("bonus/textures/end.png");
	}
	else
	{
		vars->map_info->map[y][x] = '0';
		texture = mlx_load_png("bonus/textures/background.png");
	}
	if (!texture)
		error("failed to load PNG", vars);
	png = mlx_texture_to_image(vars->mlx, texture);
	if (!png)
		error("failed to convert texture to image", vars);
	if (mlx_image_to_window(vars->mlx, png, x * 65, y * 65) < 0)
		error("failed to put PNG on window", vars);
	mlx_delete_texture(texture);
}

void	move_up(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y - 1][x] == 'C')
	{
		ft_put_asset(vars, "bonus/textures/background.png",
			vars->player.p->instances->x, vars->player.p->instances->y - 65);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y - 1][x] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	else if (vars->map_info->map[y - 1][x] == 'M')
		mlx_close_window(vars->mlx);
	if (vars->map_info->map[y - 1][x] == 'E')
		vars->map_info->map[y - 1][x] = 'X';
	else
		vars->map_info->map[y - 1][x] = 'P';
	set_background(vars, y, x);
	change_direction(vars, vars->direction);
	set_direction(vars, vars->direction);
	vars->count_moves++;
}

void	move_down(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y + 1][x] == 'C')
	{
		ft_put_asset(vars, "bonus/textures/background.png",
			vars->player.p->instances->x, vars->player.p->instances->y + 65);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y + 1][x] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	else if (vars->map_info->map[y + 1][x] == 'M')
		mlx_close_window(vars->mlx);
	if (vars->map_info->map[y + 1][x] == 'E')
		vars->map_info->map[y + 1][x] = 'X';
	else
		vars->map_info->map[y + 1][x] = 'P';
	set_background(vars, y, x);
	vars->player.p->instances->y += 65;
	change_direction(vars, vars->direction);
	set_direction(vars, vars->direction);
	vars->count_moves++;
}

void	move_right(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y][x + 1] == 'C')
	{
		ft_put_asset(vars, "bonus/textures/background.png",
			vars->player.p->instances->x + 65, vars->player.p->instances->y);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y][x + 1] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	else if (vars->map_info->map[y][x + 1] == 'M')
		mlx_close_window(vars->mlx);
	if (vars->map_info->map[y][x + 1] == 'E')
		vars->map_info->map[y][x + 1] = 'X';
	else
		vars->map_info->map[y][x + 1] = 'P';
	set_background(vars, y, x);
	vars->player.p->instances->x += 65;
	change_direction(vars, 'r');
	set_direction(vars, vars->direction);
	vars->count_moves++;
}

void	move_left(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y][x - 1] == 'C')
	{
		ft_put_asset(vars, "bonus/textures/background.png",
			vars->player.p->instances->x - 65, vars->player.p->instances->y);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y][x - 1] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	else if (vars->map_info->map[y][x - 1] == 'M')
		mlx_close_window(vars->mlx);
	if (vars->map_info->map[y][x - 1] == 'E')
		vars->map_info->map[y][x - 1] = 'X';
	else
		vars->map_info->map[y][x - 1] = 'P';
	set_background(vars, y, x);
	vars->player.p->instances->x -= 65;
	change_direction(vars, 'l');
	set_direction(vars, vars->direction);
	vars->count_moves++;
}
