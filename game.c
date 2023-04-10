/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:43:50 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/04/10 01:52:45 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_window_size(void *mlx, char *path)
{
	int		fd;
	char	*line;
	void	*win;
	int		w;
	int		h;

	fd = open(path, O_RDONLY);
	w = 0;
	h = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			++h;
		else
		{
			free(line);
			break ;
		}
		w = get_str_len(line);
		free(line);
	}
	win = mlx_new_window(mlx, w * 32, (h * 32) + 32, "./so_long");
	close(fd);
	return (win);
}

int	key_hook(int keycode, t_game *game)
{
	printf("%d\n", keycode);
	if (keycode == 119)
		player_move(game, 1, 0, '0');
	if (keycode == 115)
		player_move(game, -1, 0, '0');
	if (keycode == 97)
		player_move(game, 0, 1, 'l');
	if (keycode == 100)
		player_move(game, 0, -1, 'r');
	if (keycode == 65307)
	{
		close_message();
		free(game->map);
		exit(1);
	}
	return (1);
}

int	close_win(t_game *game)
{
	close_message();
	free(game->map);
	exit(1);
	return (0);
}

int	render_next_frame(t_game *game)
{
	game->speed++;
	if (game->speed >= 1000)
	{
		move_enemy(game);
		if (!ft_strcmp(game->coin, COIN))
			game->coin = COIN2;
		else
			game->coin = COIN;
		render_map(game);
		game->speed = 0;
	}
	check_player_exist(game->map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_error("failed to initialize"));
	if (!check_file(argv[1]))
		return (ft_error("Please check if the extension of file is .ber\n"));
	game.map = get_map(argv[1]);
	if (!check_map(game))
		return (invalid_message());
	if (!check_path(argv[1]))
		return (0);
	game.exit = DOOR_CLOSE;
	game.coin = COIN;
	game.win = get_window_size(game.mlx, argv[1]);
	game.player = PLAYER_RIGHT;
	render_map(&game);
	mlx_string_put(game.mlx, game.win, 0, 0,
		0x001958b9, "Number of moves is : 0");
	mlx_key_hook(game.win, key_hook, &game);
	// mlx_hook(game.win, 2, 0, key_hook, &game);
	// mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	printf("gooood\n");
	mlx_loop(game.mlx);
}
