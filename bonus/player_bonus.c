/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:11:09 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 16:51:57 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	set_moves(t_vars *vars)
{
	char			*nbr;
	mlx_image_t		*png;
	mlx_texture_t	*texture;

	(void)png;
	(void)texture;
	nbr = ft_itoa(vars->count_moves);
	texture = mlx_load_png("bonus/textures/wall.png");
	if (!texture)
		error("failed to load PNG", vars);
	png = mlx_texture_to_image(vars->mlx, texture);
	if (!png)
		error("failed to convert texture to image", vars);
	if (mlx_image_to_window(vars->mlx, png, 0, 0) < 0)
		error("failed to put PNG on window", vars);
	mlx_delete_texture(texture);
	mlx_put_string(vars->mlx, nbr, 0, 0);
	free(nbr);
}

void	ft_player_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = param;
	update_player_position(&vars->player, vars->map_info->map);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(vars->mlx);
	else if (is_key_up(keydata, vars->player.up))
		move_up(vars, vars->player.p->instances->x / 65,
			vars->player.p->instances->y / 65);
	else if (is_key_right(keydata, vars->player.right))
		move_right(vars, vars->player.p->instances->x / 65,
			vars->player.p->instances->y / 65);
	else if (is_key_down(keydata, vars->player.down))
		move_down(vars, vars->player.p->instances->x / 65,
			vars->player.p->instances->y / 65);
	else if (is_key_left(keydata, vars->player.left))
		move_left(vars, vars->player.p->instances->x / 65,
			vars->player.p->instances->y / 65);
	set_moves(vars);
}
