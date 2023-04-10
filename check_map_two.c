/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:37:27 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/27 00:09:22 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_end_line(char **map)
{
	int	y;
	int	x;
	int	width;

	y = 0;
	x = 0;
	while (map[y][x] && map[y][x] != '\n')
		x++;
	width = x;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
			x++;
		if (x != width)
			return (0);
		y++;
	}
	return (1);
}

void	get_player_position(char **map, t_utils *utils, char c)
{
	int	y_func;
	int	x_func;

	y_func = 0;
	while (map[y_func])
	{
		x_func = 0;
		while (map[y_func][x_func])
		{
			if (map[y_func][x_func] == c)
			{
				utils->y = y_func;
				utils->x = x_func;
				utils->old_y = y_func;
				utils->old_x = x_func;
				return ;
			}
			x_func++;
		}
		y_func++;
	}
}

int	ft_tabchr(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_putnbr_itoa(int n, char *str, int *i)
{
	if (n == -2147483648)
	{
		str[++*i] = '-';
		str[++*i] = '2';
		ft_putnbr_itoa(147483648, str, i);
	}
	else if (n > 9)
	{
		ft_putnbr_itoa(n / 10, str, i);
		str[++*i] = (n % 10) + '0';
	}
	else if (n < 0)
	{
		str[++*i] = '-';
		ft_putnbr_itoa(-n, str, i);
	}
	else
	{
		str[++*i] = n + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		temp;
	int		len;
	int		i;

	temp = n;
	i = -1;
	len = 0;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	str = malloc(sizeof(char) * len + 2);
	if (!str)
		return (0);
	ft_putnbr_itoa(n, str, &i);
	if (n <= 0)
		str[len + 1] = '\0';
	else
		str[len] = '\0';
	return (str);
}
