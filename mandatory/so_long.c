/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:08:02 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/03 11:19:39 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg, t_vars *vars)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	(void) vars;
	if (vars)
	{
		if (vars->map_info->map != NULL)
			ft_free(vars->map_info->map);
		if (vars->map_info->map)
			free(vars->map_info);
	}
	exit(1);
}

void	ft_get_window_size(t_vars *vars)
{
	int	i;

	i = 0;
	vars->window.w = ft_strlen(vars->map_info->map[0]) * 65;
	vars->map_info->x_len = ft_strlen(vars->map_info->map[0]);
	while (vars->map_info->map[i])
		i++;
	vars->window.h = i * 65;
	vars->map_info->y_len = i;
	if (vars->window.w > 2535 || vars->window.h > 1300)
		error("invalid window size", vars);
}

void	vars_init(t_vars *vars)
{
	vars->map_info = malloc(sizeof(t_map));
	vars->map_info->map = NULL;
	vars->map_info->valid_coins = 0;
	vars->map_info->valid_exit = 0;
	vars->direction = 'r';
	vars->count_moves = 0;
}

void	make_game_ready(t_vars *vars, char *arg)
{
	vars_init(vars);
	vars->map_info->map = get_map(arg, vars);
	if (!vars->map_info->map)
		error("map not found", vars);
	get_player_position(&vars->player, vars->map_info->map);
	coins_init(vars, &vars->coins, vars->map_info->map);
	ft_get_window_size(vars);
	is_map_valid(vars);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	check_textures();
	check_filename(ac - 1, av[1]);
	make_game_ready(&vars, av[1]);
	vars.mlx = mlx_init(vars.window.w, vars.window.h, "so_long", false);
	if (!vars.mlx)
		error("failed to create window", &vars);
	put_textures_on_map(&vars, vars.map_info->map);
	vars.player.p = get_png("mandatory/textures/player_idle/player-1.png",
			&vars);
	mlx_key_hook(vars.mlx, ft_player_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_delete_image(vars.mlx, vars.player.p);
	ft_free(vars.map_info->map);
	free(vars.map_info);
	mlx_terminate(vars.mlx);
	return (0);
}
