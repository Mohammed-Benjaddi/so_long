/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:40:23 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 16:57:03 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_up_down_borders(char **map, int i, int j, t_vars *vars)
{
	while (map[i][j])
	{
		if (map[i][j] != '1')
			error("invalid map", vars);
		j++;
	}
}

void	check_left_right_borders(int i, int j, int len, t_vars *vars)
{
	while (vars->map_info->map[i][j])
	{
		if ((j == 0 || j == len - 1) && vars->map_info->map[i][j] != '1')
			error("invalid map", vars);
		j++;
	}
}

void	check_walls(char **map, t_vars *vars)
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
			check_up_down_borders(map, i, j, vars);
		else
			check_left_right_borders(i, j, len, vars);
		i++;
	}
}
