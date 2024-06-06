/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:25:12 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/01 18:25:03 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y - 1][x] == 'C')
	{
		ft_put_asset(vars, "mandatory/textures/background.png",
			vars->player.p->instances->x, vars->player.p->instances->y - 65);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y - 1][x] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	if (vars->map_info->map[y - 1][x] == 'E')
		vars->map_info->map[y - 1][x] = 'X';
	else
		vars->map_info->map[y - 1][x] = 'P';
	if (vars->map_info->map[y][x] == 'X')
		vars->map_info->map[y][x] = 'E';
	else
		vars->map_info->map[y][x] = '0';
	vars->player.p->instances->y -= 65;
	change_direction(vars, vars->direction);
	set_direction(vars, vars->direction);
	vars->count_moves++;
	set_moves(vars);
}

void	move_down(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y + 1][x] == 'C')
	{
		ft_put_asset(vars, "mandatory/textures/background.png",
			vars->player.p->instances->x, vars->player.p->instances->y + 65);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y + 1][x] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	if (vars->map_info->map[y + 1][x] == 'E')
		vars->map_info->map[y + 1][x] = 'X';
	else
		vars->map_info->map[y + 1][x] = 'P';
	if (vars->map_info->map[y][x] == 'X')
		vars->map_info->map[y][x] = 'E';
	else
		vars->map_info->map[y][x] = '0';
	vars->player.p->instances->y += 65;
	change_direction(vars, vars->direction);
	set_direction(vars, vars->direction);
	vars->count_moves++;
	set_moves(vars);
}

void	move_right(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y][x + 1] == 'C')
	{
		ft_put_asset(vars, "mandatory/textures/background.png",
			vars->player.p->instances->x + 65, vars->player.p->instances->y);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y][x + 1] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	if (vars->map_info->map[y][x + 1] == 'E')
		vars->map_info->map[y][x + 1] = 'X';
	else
		vars->map_info->map[y][x + 1] = 'P';
	if (vars->map_info->map[y][x] == 'X')
		vars->map_info->map[y][x] = 'E';
	else
		vars->map_info->map[y][x] = '0';
	vars->player.p->instances->x += 65;
	change_direction(vars, 'r');
	set_direction(vars, vars->direction);
	vars->count_moves++;
	set_moves(vars);
}

void	move_left(t_vars *vars, int x, int y)
{
	if (vars->map_info->map[y][x - 1] == 'C')
	{
		ft_put_asset(vars, "mandatory/textures/background.png",
			vars->player.p->instances->x - 65, vars->player.p->instances->y);
		vars->coins.eaten++;
		vars->coins.rest = vars->coins.total - vars->coins.eaten;
	}
	else if (vars->map_info->map[y][x - 1] == 'E')
	{
		if (vars->coins.eaten == vars->coins.total)
			mlx_close_window(vars->mlx);
	}
	if (vars->map_info->map[y][x - 1] == 'E')
		vars->map_info->map[y][x - 1] = 'X';
	else
		vars->map_info->map[y][x - 1] = 'P';
	if (vars->map_info->map[y][x] == 'X')
		vars->map_info->map[y][x] = 'E';
	else
		vars->map_info->map[y][x] = '0';
	vars->player.p->instances->x -= 65;
	change_direction(vars, 'l');
	set_direction(vars, vars->direction);
	vars->count_moves++;
	set_moves(vars);
}
