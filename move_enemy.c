/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:43:35 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/27 00:09:41 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	switch_position(char *c1, char *c2, char c)
{
	*c1 = '0';
	*c2 = c;
}

void	check_enemy_position(t_game game, int y, int *x)
{
	if (game.map[y][*x] == 'M')
	{
		if (game.map[y][*x + 1] == '0' || game.map[y][*x + 1] == 'P')
			switch_position(&(game.map[y][*x]), &(game.map[y][*x + 1]), 'M');
		else
			game.map[y][*x] = 'm';
		++*x;
	}
	else if (game.map[y][*x] == 'm')
	{
		if (game.map[y][*x - 1] == '0' || game.map[y][*x - 1] == 'P')
			switch_position(&(game.map[y][*x]), &(game.map[y][*x - 1]), 'm');
		else
			game.map[y][*x] = 'M';
		++*x;
	}
}

void	move_enemy(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			check_enemy_position(*game, y, &x);
	}
}
