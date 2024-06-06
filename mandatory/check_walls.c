/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:13:46 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:20:00 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_up_down_borders(t_vars *vars, char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] != '1')
			error("invalid map", vars);
		j++;
	}
}

void	check_left_right_borders(t_vars *vars, int i, int j, int len)
{
	while (vars->map_info->map[i][j])
	{
		if ((j == 0 || j == len - 1) && vars->map_info->map[i][j] != '1')
			error("invalid map", vars);
		j++;
	}
}

void	check_walls(t_vars *vars, char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		if (ft_strlen(map[i]) != len)
			error("invalid map", vars);
		if (i == 0 || !map[i + 1])
			check_up_down_borders(vars, map, i, j);
		else
			check_left_right_borders(vars, i, j, len);
		i++;
	}
}
