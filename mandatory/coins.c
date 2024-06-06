/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:33:34 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/01 18:20:30 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(char **map)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	coins_init(t_vars *vars, t_coins *coins, char **map)
{
	coins->total = count_coins(map);
	coins->eaten = 0;
	coins->rest = coins->total - coins->eaten;
	if (coins->total < 1)
		error("you should have at least 1 coin", vars);
}
