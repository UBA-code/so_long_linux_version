/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:35 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/27 01:17:39 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	coins_search(t_game game)
{
	int	y;
	int	x;

	y = -1;
	while (game.map[++y])
	{
		x = -1;
		while (game.map[y][++x])
			if (game.map[y][x] == 'C')
				return (1);
	}
	y = -1;
	return (0);
}

void	free_exit(t_game game, char c)
{
	mlx_clear_window(game.mlx, game.win);
	if (c == 'S')
		succes_message();
	if (c == 'O')
		over_message();
	free(game.map);
	mlx_clear_window(game.mlx, game.win);
	exit(0);
}

void	ft_put_counter_win(t_game game, int i)
{
	char	*nb;

	mlx_string_put(game.mlx, game.win, 0, 0,
		0x001958b9, "Number of moves is : ");
	nb = ft_itoa(i);
	mlx_string_put(game.mlx, game.win, 220, 0, 0x001958b9, nb);
	free(nb);
}

void	check_position(t_game game, int y_move, int x_move, int y)
{
	static int	i;

	if (!coins_search(game) && game.map[y - y_move][game.x - x_move] == 'E')
	{
		game.map[y][game.x] = '0';
		game.map[y - y_move][game.x - x_move] = 'P';
		ft_put_counter_win(game, ++i);
		ft_putstr("ur movement count is : ");
		ft_putnbr(i);
		free_exit(game, 'S');
	}
	else if (game.map[y - y_move][game.x - x_move] == 'M'
		|| game.map[y - y_move][game.x - x_move] == 'm')
		free_exit(game, 'O');
	else if (game.map[y - y_move][game.x - x_move] != '1'
		&& game.map[y - y_move][game.x - x_move] != 'E')
	{
		game.map[y][game.x] = '0';
		game.map[y - y_move][game.x - x_move] = 'P';
		mlx_clear_window(game.mlx, game.win);
		render_map(&game);
		ft_put_counter_win(game, ++i);
	}
}

void	player_move(t_game *game, int y_move, int x_move, char c)
{
	int	x;
	int	y;

	y = 0;
	if (c == 'r')
		game->player = PLAYER_RIGHT;
	else if (c == 'l')
		game->player = PLAYER_LEFT;
	while (*game->map[++y])
	{
		x = -1;
		while ((*game).map[y][++x])
		{
			if ((*game).map[y][x] == 'P')
			{
				game->x = x;
				check_position(*game, y_move, x_move, y);
				return ;
			}
		}
	}
}
