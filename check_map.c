/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:41 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/27 00:09:25 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_walls(char **map)
{
	int	y;
	int	x;
	int	end;

	y = 0;
	x = 0;
	end = 0;
	while (map[y][end] && map[y][end] != '\n')
	{
		if (map[y][end] != '1')
			return (0);
		end++;
	}
	y = -1;
	while (map[++y])
		if (map[y][x] != '1' || map[y][end - 1] != '1')
			return (0);
	x = -1;
	while (map[y - 1][++x] && map[y - 1][x] != '\n')
	{
		if (map[y - 1][x] != '1')
			return (0);
	}
	return (1);
}

int	check_valid_elements(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E'
				&& map[y][x] != 'P' && map[y][x] != '1'
				&& map[y][x] != '\n' && map[y][x] != 'M')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_rectangular(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y][x] && map[y][x] != '\n')
		x++;
	while (map[y])
		y++;
	if (y >= x)
		return (0);
	return (1);
}

typedef struct check_element_utils{
	int	y;
	int	x;
	int	exit;
	int	coin;
	int	player;
}	t_check_element_utils;

int	check_element(char **map)
{
	t_check_element_utils	utils;

	utils.y = -1;
	utils.exit = 1;
	utils.coin = 0;
	utils.player = 1;
	while (map[++(utils.y)])
	{
		utils.x = -1;
		while (map[utils.y][++(utils.x)])
		{
			if (map[utils.y][utils.x] == 'E')
				utils.exit++;
			if (map[utils.y][utils.x] == 'C')
				utils.coin++;
			if (map[utils.y][utils.x] == 'P')
				utils.player++;
		}
	}
	if (utils.exit != 2 || utils.player != 2 || utils.coin == 0)
		return (0);
	return (1);
}

int	check_map(t_game game)
{
	if (check_rectangular(game.map)
		&& check_valid_elements(game.map) && check_walls(game.map)
		&& check_element(game.map) && check_end_line(game.map))
		return (1);
	return (0);
}
