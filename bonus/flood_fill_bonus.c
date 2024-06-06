/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:56 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/26 16:46:46 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_vars *vars, int x, int y, char **map_copy)
{
	if (map_copy[y][x] == 'C')
		vars->map_info->valid_coins += 1;
	if (map_copy[y][x] == 'E')
		vars->map_info->valid_exit += 1;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'M' || x < 0
		|| x >= vars->map_info->x_len || y < 0 || y >= vars->map_info->y_len)
		return ;
	if (map_copy[y][x] != '1')
		map_copy[y][x] = '1';
	flood_fill(vars, x + 1, y, map_copy);
	flood_fill(vars, x - 1, y, map_copy);
	flood_fill(vars, x, y + 1, map_copy);
	flood_fill(vars, x, y - 1, map_copy);
}
