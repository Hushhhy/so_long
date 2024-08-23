/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:26:46 by acarpent          #+#    #+#             */
/*   Updated: 2024/08/23 12:19:40 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_getmap(t_map *map, char *str);
void	ft_checkname(char *str);
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
		if (!map->map)
		{
			close(map->fd);
			return (free(line), NULL);
		}
		free(line);
		line = get_next_line(map->fd);
		free(tmp);
	}
	close(map->fd);
	return (&map->map);
}

void	ft_checkname(char *str)
{
	char	*tmp;

	tmp = ft_strrchr(str, '.');
	if (!tmp || ft_strncmp(tmp, ".ber\0", 5) != 0)
	{
		ft_printf("Error!\nName incorect!6\n");
		exit(0);
	}
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
			ft_printf("Error!\nWrong map format!7\n");
			free(game->map);
			ft_free(game->split);
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
		ft_printf("Error!\nWrong map Format!8\n");
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
