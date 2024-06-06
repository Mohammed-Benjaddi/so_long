/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:38 by mben-jad          #+#    #+#             */
/*   Updated: 2024/05/26 13:33:56 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_direction(t_vars *vars, char flag)
{
	if (flag == 'l')
		vars->direction = 'l';
	else if (flag == 'r')
		vars->direction = 'r';
}

void	set_direction(t_vars *vars, char flag)
{
	char	*t_playero_right;
	char	*t_playero_left;

	get_player_position(&vars->player, vars->map_info->map);
	t_playero_right = "bonus/textures/player_idle/player-1.png";
	t_playero_left = "bonus/textures/player_idle/player-1-left.png";
	if (flag == 'l')
		vars->player.p = get_png(t_playero_left, vars);
	if (flag == 'r')
		vars->player.p = get_png(t_playero_right, vars);
}
