/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:49:22 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 17:49:55 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_other_txt(void)
{
	void	**textures;

	textures = malloc(sizeof(void *) * 5);
	textures[0] = mlx_load_png("bonus/textures/background.png");
	textures[1] = mlx_load_png("bonus/textures/coin.png");
	textures[2] = mlx_load_png("bonus/textures/end.png");
	textures[3] = mlx_load_png("bonus/textures/wall.png");
	textures[4] = NULL;
	check_if_loaded(textures, 4);
}

void	check_enemy_txt(void)
{
	void	**textures;

	textures = malloc(sizeof(void *) * 7);
	textures[0] = mlx_load_png("bonus/textures/enemy_idle/fly-1.png");
	textures[1] = mlx_load_png("bonus/textures/enemy_idle/fly-2.png");
	textures[2] = mlx_load_png("bonus/textures/enemy_idle/fly-3.png");
	textures[3] = mlx_load_png("bonus/textures/enemy_idle/fly-4.png");
	textures[4] = mlx_load_png("bonus/textures/enemy_idle/fly-5.png");
	textures[5] = mlx_load_png("bonus/textures/enemy_idle/fly-6.png");
	textures[6] = NULL;
	check_if_loaded(textures, 6);
}
