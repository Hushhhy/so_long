/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:48:44 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/06 10:57:04 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_floodfill(int x, int y, char **copy);
void	checkfloodfill(t_map *ptr);
char	**ft_mapcopy(char **map);

void	ft_floodfill(int x, int y, char **copy)
{
	t_map	*map;

	map = NULL;
	if (x >= map->width || y >= map->height || copy[y][x] == 'X')
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'N')
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = 'X';
		return ;
	}
	copy[y][x] = 'X';
	ft_floodfill(x + 1, y, copy);
	ft_floodfill(x - 1, y, copy);
	ft_floodfill(x, y + 1, copy);
	ft_floodfill(x, y - 1, copy);
	return ;
}

void	checkfloodfill(t_map *ptr)
{
	char 	**copy;
	int		i;
	int		j;

	i = 0;
	copy = ft_mapcopy(ptr->map);
	ft_floodfill(ptr->x, ptr->y, copy);
	while (i < ptr->height)
	{
		j = 0;
		while (j < ptr->width)
		{
			if (copy[i][j] == 'E' || copy[i][j] == 'C')
			{
				ft_printf("Error! Wrong floodfill!");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

char	**ft_mapcopy(char **map)
{
	t_map	*size;
	int		i;
	char	**copy;

	i = 0;
	size = NULL;
	copy = malloc(sizeof(char *) * (size->height + 1));
	if (!copy)
		return (NULL);
	while (i < size->height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
