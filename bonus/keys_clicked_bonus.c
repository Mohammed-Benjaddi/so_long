/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_clicked_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:53:10 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/26 13:25:46 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_key_up(mlx_key_data_t keydata, bool up)
{
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) && up)
		return (1);
	return (0);
}

int	is_key_down(mlx_key_data_t keydata, bool down)
{
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& down)
		return (1);
	return (0);
}

int	is_key_left(mlx_key_data_t keydata, bool left)
{
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& left)
		return (1);
	return (0);
}

int	is_key_right(mlx_key_data_t keydata, bool right)
{
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& right)
		return (1);
	return (0);
}
