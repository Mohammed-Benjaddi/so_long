/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:34:42 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:27:25 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_asset(void *param, char *path, int x, int y)
{
	mlx_t			*mlx;
	t_vars			*vars;
	mlx_image_t		*png;
	mlx_texture_t	*texture;

	vars = param;
	mlx = vars->mlx;
	texture = mlx_load_png(path);
	if (!texture)
		error("failed to load PNG", vars);
	png = mlx_texture_to_image(mlx, texture);
	if (!png)
		error("failed to convert texture to image", vars);
	if (mlx_image_to_window(mlx, png, x, y) < 0)
		error("failed to put PNG on window", vars);
	mlx_delete_texture(texture);
}
