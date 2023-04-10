/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:55:20 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/27 00:31:41 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	get_lines_len(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (i);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	map = malloc(sizeof(char *) * get_lines_len(file) + 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_error("No such file or directory\n");
		exit(1);
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = malloc(sizeof(char) * get_str_len(line));
		ft_strcpy(map[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	map[i] = 0;
	return (map);
}

void	free_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}
