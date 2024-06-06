/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:35:06 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:19:28 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delete_textures(void **textures)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (textures[i])
			mlx_delete_texture(textures[i]);
		i++;
	}
	free(textures);
}

static void	check_if_loaded(void **textures)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!textures[i])
		{
			delete_textures(textures);
			error("failed to load PNG", NULL);
		}
		i++;
	}
	delete_textures(textures);
}

void	check_textures(void)
{
	void	**textures;

	textures = malloc(sizeof(void *) * 7);
	textures[0] = 
		mlx_load_png("mandatory/textures/player_idle/player-1-left.png");
	textures[1] = mlx_load_png("mandatory/textures/player_idle/player-1.png");
	textures[2] = mlx_load_png("mandatory/textures/background.png");
	textures[3] = mlx_load_png("mandatory/textures/coin.png");
	textures[4] = mlx_load_png("mandatory/textures/end.png");
	textures[5] = mlx_load_png("mandatory/textures/wall.png");
	textures[6] = NULL;
	check_if_loaded(textures);
}
