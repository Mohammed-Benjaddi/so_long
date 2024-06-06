/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:23:44 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/22 21:23:52 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_vars *vars, int x, int y, char **map_copy)
{
	if (map_copy[y][x] == 'C')
		vars->map_info->valid_coins += 1;
	if (map_copy[y][x] == 'E')
		vars->map_info->valid_exit += 1;
	if (map_copy[y][x] == '1' || x < 0 || x >= vars->map_info->x_len || y < 0
		|| y >= vars->map_info->y_len)
		return ;
	if (map_copy[y][x] != '1')
		map_copy[y][x] = '1';
	flood_fill(vars, x + 1, y, map_copy);
	flood_fill(vars, x - 1, y, map_copy);
	flood_fill(vars, x, y + 1, map_copy);
	flood_fill(vars, x, y - 1, map_copy);
}
