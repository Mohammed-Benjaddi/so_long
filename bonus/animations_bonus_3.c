/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:32:51 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:17:23 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*load_the_png(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	return (texture);
}

void	get_right_direction(void **textures, bool at_exit)
{
	if (at_exit)
	{
		textures[0] = 
			load_the_png("bonus/textures/player_at_exit/player-1.png");
		textures[1] = 
			load_the_png("bonus/textures/player_at_exit/player-2.png");
		textures[2] = 
			load_the_png("bonus/textures/player_at_exit/player-3.png");
		textures[3] = 
			load_the_png("bonus/textures/player_at_exit/player-4.png");
	}
	else
	{
		textures[0] = 
			load_the_png("bonus/textures/player_idle/player-1.png");
		textures[1] = 
			load_the_png("bonus/textures/player_idle/player-2.png");
		textures[2] = 
			load_the_png("bonus/textures/player_idle/player-3.png");
		textures[3] = 
			load_the_png("bonus/textures/player_idle/player-4.png");
	}
}

void	get_left_direction(void **textures, bool at_exit)
{
	if (at_exit)
	{
		textures[0] = 
			mlx_load_png("bonus/textures/player_at_exit/player-1-left.png");
		textures[1] = 
			mlx_load_png("bonus/textures/player_at_exit/player-2-left.png");
		textures[2] = 
			mlx_load_png("bonus/textures/player_at_exit/player-3-left.png");
		textures[3] = 
			mlx_load_png("bonus/textures/player_at_exit/player-4-left.png");
	}
	else
	{
		textures[0] = 
			mlx_load_png("bonus/textures/player_idle/player-1-left.png");
		textures[1] = 
			mlx_load_png("bonus/textures/player_idle/player-2-left.png");
		textures[2] = 
			mlx_load_png("bonus/textures/player_idle/player-3-left.png");
		textures[3] = 
			mlx_load_png("bonus/textures/player_idle/player-4-left.png");
	}
}

void	player_animation(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player.p->instances->x / 65;
	y = vars->player.p->instances->y / 65;
	if (vars->map_info->map[y][x] == 'X')
		vars->player_moves = get_player_exit_textures(vars->direction, vars);
	else
		vars->player_moves = get_player_textures(vars->direction, vars);
	if (vars->player.current_player_png > 3)
		vars->player.current_player_png = 0;
	vars->player.p = make_player_breath(vars, vars->player.current_player_png);
	vars->player.current_player_png++;
	delete_player_textures(vars);
}
