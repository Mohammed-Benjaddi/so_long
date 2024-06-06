/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:35 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/22 15:39:01 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_enemies(t_vars *vars)
{
	int	i;
	int	j;
	int	enemies_counter;

	i = 0;
	enemies_counter = 0;
	while (vars->map_info->map[i])
	{
		j = 0;
		while (vars->map_info->map[i][j])
		{
			if (vars->map_info->map[i][j] == 'M')
				enemies_counter++;
			j++;
		}
		i++;
	}
	return (enemies_counter);
}

void	get_all_enemies_positions(t_vars *vars)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (vars->map_info->map[i])
	{
		j = 0;
		while (vars->map_info->map[i][j])
		{
			if (vars->map_info->map[i][j] == 'M')
			{
				vars->enemies[counter].y = i * 65;
				vars->enemies[counter].x = j * 65;
				counter++;
			}
			j++;
		}
		i++;
	}
}
