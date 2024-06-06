/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:18:38 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:15:38 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	delete_textures(void **textures, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (textures[i])
			mlx_delete_texture(textures[i]);
		i++;
	}
	free(textures);
}

void	check_if_loaded(void **textures, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!textures[i])
		{
			delete_textures(textures, size);
			error("failed to load PNG", NULL);
		}
		i++;
	}
	delete_textures(textures, size);
}

void	check_player_at_exit_txt(void)
{
	void	**textures;

	textures = malloc(sizeof(void *) * 9);
	textures[0] = 
		mlx_load_png("bonus/textures/player_at_exit/player-1-left.png");
	textures[1] = 
		mlx_load_png("bonus/textures/player_at_exit/player-1.png");
	textures[2] = 
		mlx_load_png("bonus/textures/player_at_exit/player-2-left.png");
	textures[3] = 
		mlx_load_png("bonus/textures/player_at_exit/player-2.png");
	textures[4] = 
		mlx_load_png("bonus/textures/player_at_exit/player-3-left.png");
	textures[5] = 
		mlx_load_png("bonus/textures/player_at_exit/player-3.png");
	textures[6] = 
		mlx_load_png("bonus/textures/player_at_exit/player-4-left.png");
	textures[7] = 
		mlx_load_png("bonus/textures/player_at_exit/player-4.png");
	textures[8] = NULL;
	check_if_loaded(textures, 8);
}

void	check_player_idle_txt(void)
{
	void	**textures;

	textures = malloc(sizeof(void *) * 9);
	textures[0] = mlx_load_png("bonus/textures/player_idle/player-1-left.png");
	textures[1] = mlx_load_png("bonus/textures/player_idle/player-1.png");
	textures[2] = mlx_load_png("bonus/textures/player_idle/player-2-left.png");
	textures[3] = mlx_load_png("bonus/textures/player_idle/player-2.png");
	textures[4] = mlx_load_png("bonus/textures/player_idle/player-3-left.png");
	textures[5] = mlx_load_png("bonus/textures/player_idle/player-3.png");
	textures[6] = mlx_load_png("bonus/textures/player_idle/player-4-left.png");
	textures[7] = mlx_load_png("bonus/textures/player_idle/player-4.png");
	textures[8] = NULL;
	check_if_loaded(textures, 8);
}

void	check_textures(void)
{
	check_enemy_txt();
	check_player_at_exit_txt();
	check_player_idle_txt();
	check_other_txt();
}
