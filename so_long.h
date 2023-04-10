/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:46:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/04/09 18:35:03 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "mlx_int.h"
# include "fcntl.h"
# include "get_next_line.h"
#include "stdio.h"

# define FLOOR "./textures/floor.xpm"
# define DOOR_CLOSE "./textures/door.xpm"
# define DOOR_OPEN "./textures/door_open.xpm"
# define DOOR DOOR_CLOSE
# define COIN "./textures/coin.xpm"
# define PLAYER_LEFT "./textures/player_left.xpm"
# define PLAYER_RIGHT "./textures/player_right.xpm"
# define WALL "./textures/wall.xpm"
# define ENEMY "./textures/enemy.xpm"
# define COIN2 "./textures/coin_2.xpm"

typedef struct s_put_line_to_window_utils {
	int		i;
	int		width;
	int		height;
	void	*img;
	int		y;

}	t_put_line_to_window_utils;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	char	*exit;
	int		speed;
	char	*coin;
	char	*player;
	int		x;
}	t_game;

typedef struct s_utils
{
	int	y;
	int	x;
	int	old_y;
	int	old_x;
}	t_utils;

void	put_line_to_window(t_game *game, char *line, int *x);
int		check_map(t_game game);
char	**get_map(char *file);
void	render_map(t_game *game);
void	player_move(t_game *game, int y_move, int x_move, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int n);
int		check_file(char *str);
int		check_end_line(char **map);
void	close_message(void);
int		invalid_message(void);
void	succes_message(void);
void	over_message(void);
int		ft_error(char *txt);
int		ft_tabchr(char **map, char c);
int		check_path(char *file);
void	get_player_position(char **map, t_utils *utils, char c);
char	*ft_itoa(int n);
void	move_enemy(t_game *game);
void	free_tab(char **tab);
void	check_player_exist(char **map);

#endif
