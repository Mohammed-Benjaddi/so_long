/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:16:45 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/01 18:20:40 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_moves(t_vars *vars)
{
	char	*nbr;

	nbr = ft_itoa(vars->count_moves);
	ft_putstr_fd(nbr, 1);
	free(nbr);
}

mlx_image_t	*get_png(char *path, t_vars *vars)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error("failed to load PNG", vars);
	vars->player.p = mlx_texture_to_image(vars->mlx, texture);
	if (!vars->player.p)
		error("failed to convert texture to image", vars);
	if (mlx_image_to_window(vars->mlx, vars->player.p, vars->player.x,
			vars->player.y) < 0)
		error("failed to put PNG on window", vars);
	mlx_delete_texture(texture);
	return (vars->player.p);
}

void	get_player_position(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'X')
			{
				player->y = i * 65;
				player->x = j * 65;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	update_player_position(t_player *player, char **map)
{
	int	x;
	int	y;

	x = player->x / 65;
	y = player->y / 65;
	if (map[y - 1][x] && map[y - 1][x] == '1')
		player->up = false;
	else
		player->up = true;
	if (map[y + 1][x] && map[y + 1][x] == '1')
		player->down = false;
	else
		player->down = true;
	if (map[y][x - 1] && map[y][x - 1] == '1')
		player->left = false;
	else
		player->left = true;
	if (map[y][x + 1] && map[y][x + 1] == '1')
		player->right = false;
	else
		player->right = true;
}

void	ft_player_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;
	mlx_t	*mlx;
	int		x;
	int		y;

	vars = param;
	mlx = vars->mlx;
	update_player_position(&vars->player, vars->map_info->map);
	x = vars->player.p->instances->x / 65;
	y = vars->player.p->instances->y / 65;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && vars->player.up)
		move_up(vars, x, y);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && vars->player.right)
		move_right(vars, x, y);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && vars->player.down)
		move_down(vars, x, y);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT) && vars->player.left)
		move_left(vars, x, y);
}
