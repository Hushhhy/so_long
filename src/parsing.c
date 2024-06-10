/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:26:46 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/10 14:06:42 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

char	**ft_getmap(t_map *map, char *str);
int		ft_checkname(char *str);
void	ft_parsemap(char **map, t_map *game);
void	gamecheck(char **map, t_map *game);
void	ft_count(t_map *game, char **map);

char	**ft_getmap(t_map *map, char *str)
{
	char	*line;
	char	*tmp;

	map->fd = open(str, O_RDONLY);
	if (map->fd < 0)
		return (NULL);
	map->map = ft_strdup("");
	if (!map)
		return (NULL);
	while ((line = get_next_line(map->fd)) != NULL)
	{
		tmp = map->map;
		map->map = ft_strjoin(map->map, line);
		free(tmp);
		if (!map->map)
		{
			close(map->fd);
			return (NULL);
		}
	}
	close(map->fd);
	return (map->map);
}

int	ft_checkname(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0')
		{
			i -= 3;
			if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
				&& str[i + 3] == 'r')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_parsemap(char **map, t_map *game)
{
	char	*first;
	char	*last;
	int		i;

	ft_sizecheck(map);
	first = map[0];
	last = ft_lastline(map);
	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
		{
			ft_printf("Error! Wrong map format!");
			exit(1);
		}
		i++;
	}
	walls(map, first, last);
	gamecheck(map, game);
	checkfloodfill(game);
}

void	gamecheck(char **map, t_map *game)
{
	ft_count(game, map);
	if (game->P != 1 || game->C != 1 || game->E < 1)
	{
		ft_printf("Error! Wrong map Format!");
		exit(1);
	}
}

void	ft_count(t_map *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->x = i;
				game->y = j;
				game->P++;
			}
			if (map[i][j] == 'E')
				game->E++;
			if (map[i][j] == 'C')
				game->C++;
			j++;
		}
		i++;
	}
}
