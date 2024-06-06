/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:32:10 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/19 13:13:28 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	**get_enemy_textures(void)
{
	void	**textures;
	int		i;

	i = 0;
	textures = malloc(sizeof(void *) * 7);
	textures[0] = mlx_load_png("bonus/textures/enemy_idle/fly-1.png");
	textures[1] = mlx_load_png("bonus/textures/enemy_idle/fly-2.png");
	textures[2] = mlx_load_png("bonus/textures/enemy_idle/fly-3.png");
	textures[3] = mlx_load_png("bonus/textures/enemy_idle/fly-4.png");
	textures[4] = mlx_load_png("bonus/textures/enemy_idle/fly-5.png");
	textures[5] = mlx_load_png("bonus/textures/enemy_idle/fly-6.png");
	textures[6] = NULL;
	return (textures);
}

void	delete_textures(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_delete_texture(vars->enemy_moves[i]);
		i++;
	}
	free(vars->enemy_moves);
	vars->enemy_moves = NULL;
}

void	make_enemies_fly(t_vars *vars, int nbr)
{
	int			i;
	mlx_image_t	*enemy;

	i = 0;
	enemy = mlx_texture_to_image(vars->mlx, vars->enemy_moves[nbr]);
	if (!enemy)
		error("failed to load PNG", vars);
	while (i < vars->enemies_count)
	{
		if (mlx_image_to_window(vars->mlx, enemy, vars->enemies[i].x,
				vars->enemies[i].y) < 0)
			error("failed to put the image on window", vars);
		i++;
	}
}

void	enemy_animation(t_vars *vars)
{
	vars->enemy_moves = get_enemy_textures();
	if (vars->current_enemy_png > 5)
		vars->current_enemy_png = 0;
	make_enemies_fly(vars, vars->current_enemy_png);
	vars->current_enemy_png++;
	delete_textures(vars);
}

void	animations(void *param)
{
	t_vars	*vars;

	vars = param;
	vars->fly_count++;
	vars->player.idle_count++;
	if (vars->fly_count > 7)
		vars->fly_count = 0;
	if (vars->player.idle_count > 15)
		vars->player.idle_count = 0;
	if (vars->fly_count == 7)
		enemy_animation(vars);
	if (vars->player.idle_count == 15)
		player_animation(vars);
}
