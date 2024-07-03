/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:26:46 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/03 12:47:47 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_getmap(t_map *map, char *str);
int		ft_checkname(char *str);
void	ft_parsemap(t_map *game);
void	gamecheck(t_map *game);
void	ft_count(t_map *game);

char	**ft_getmap(t_map *map, char *str)
{
	char	*line;
	char	*tmp;

	map->fd = open(str, O_RDONLY);
	if (map->fd < 0)
		return (NULL);
	map->map = ft_strdup("");
	if (!map->map)
		return (NULL);
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		tmp = map->map;
		map->map = ft_strjoin(map->map, line);
		free(tmp);
		if (!map->map)
		{
			close(map->fd);
			return (free(line), NULL);
		}
		free(line);
		line = get_next_line(map->fd);
	}
	close(map->fd);
	return (&map->map);
}

int	ft_checkname(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r')
			{
				if (str[i + 4] != '\0')
					return (1);
				return (0);
			}
			else
				return (1);
		}
		i++;
	}
	return (1);
}

void	ft_parsemap(t_map *game)
{
	char	*first;
	char	*last;
	int		i;

	ft_sizecheck(game);
	first = game->split[0];
	last = ft_lastline(game);
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
	walls(game);
	gamecheck(game);
	checkfloodfill(game);
}

void	gamecheck(t_map *game)
{
	ft_count(game);
	if (game->p != 1 || game->c < 1 || game->e != 1)
	{
		ft_printf("Error! Wrong map Format!");
		exit_handler(game);
	}
}

void	ft_count(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->split[i])
	{
		j = 0;
		while (game->split[i][j])
		{
			if (game->split[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				game->p++;
			}
			if (game->split[i][j] == 'E')
				game->e++;
			if (game->split[i][j] == 'C')
				game->c++;
			j++;
		}
		i++;
	}
}
