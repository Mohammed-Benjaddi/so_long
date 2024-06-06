/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:08:12 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 16:47:18 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	**get_player_exit_textures(char direction, t_vars *vars)
{
	void	**textures;
	int		i;

	textures = malloc(sizeof(void *) * 5);
	i = 0;
	if (direction == 'r')
		get_right_direction(textures, true);
	else
		get_left_direction(textures, true);
	textures[4] = NULL;
	if (!textures)
		error("Failed to load textures", vars);
	return (textures);
}

void	**get_player_textures(char direction, t_vars *vars)
{
	void	**textures;
	int		i;

	textures = malloc(sizeof(void *) * 5);
	i = 0;
	if (direction == 'r')
		get_right_direction(textures, false);
	else
		get_left_direction(textures, false);
	textures[4] = NULL;
	if (!textures)
		error("Failed to load textures", vars);
	return (textures);
}

void	delete_player_textures(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_delete_texture(vars->player_moves[i]);
		i++;
	}
	free(vars->player_moves);
	vars->player_moves = NULL;
}

mlx_image_t	*make_player_breath(t_vars *vars, int nbr)
{
	mlx_image_t	*player;

	player = mlx_texture_to_image(vars->mlx, vars->player_moves[nbr]);
	if (!player)
		error("Failed to get player PNG", vars);
	if (mlx_image_to_window(vars->mlx, player, vars->player.x,
			vars->player.y) < 0)
		error("failed to put the image on window", vars);
	return (player);
}

mlx_image_t	*texture_to_png(t_vars *vars, int nbr)
{
	mlx_image_t	*enemy;

	enemy = mlx_texture_to_image(vars->mlx, vars->enemy_moves[nbr - 1]);
	if (!enemy)
		error("Failed to get player PNG", vars);
	if (mlx_image_to_window(vars->mlx, enemy, vars->enemies[vars->enemy_fly].x,
			vars->enemies[vars->enemy_fly].y) < 0)
		error("failed to put the image on window", vars);
	return (enemy);
}
