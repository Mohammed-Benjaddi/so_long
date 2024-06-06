/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:15:33 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/02 19:27:18 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_direction(t_vars *vars, char flag)
{
	if (flag == 'l')
		vars->direction = 'l';
	else if (flag == 'r')
		vars->direction = 'r';
}

void	set_direction(t_vars *vars, char flag)
{
	get_player_position(&vars->player, vars->map_info->map);
	vars->player.p->enabled = false;
	if (flag == 'l')
		vars->player.p = 
			get_png("mandatory/textures/player_idle/player-1-left.png",
				vars);
	else if (flag == 'r')
		vars->player.p = 
			get_png("mandatory/textures/player_idle/player-1.png",
				vars);
}
