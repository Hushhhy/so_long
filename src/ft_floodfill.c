/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:48:44 by acarpent          #+#    #+#             */
/*   Updated: 2024/08/22 11:50:18 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_floodfill(int x, int y, char **copy, t_map *map);
void	checkfloodfill(t_map *ptr);
char	**ft_mapcopy(char **map, t_map *ptr);

void	ft_floodfill(int x, int y, char **copy, t_map *map)
{
	if (x >= map->width || y >= map->height || copy[y][x] == 'X')
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'N')
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = '1';
		return ;
	}
	copy[y][x] = 'X';
	ft_floodfill(x + 1, y, copy, map);
	ft_floodfill(x - 1, y, copy, map);
	ft_floodfill(x, y + 1, copy, map);
	ft_floodfill(x, y - 1, copy, map);
	return ;
}

void	checkfloodfill(t_map *ptr)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = ft_mapcopy(ptr->split, ptr);
	ft_floodfill(ptr->x, ptr->y, copy, ptr);
	while (i < ptr->height)
	{
		j = 0;
		while (j < ptr->width)
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				ft_printf("Error!\nMap Invalid!\n");
				ft_free(copy);
				ft_free(ptr->split);
				free(ptr->map);
				exit(1);
			}
			j++;
		}
		i++;
	}
	ft_free(copy);
}

char	**ft_mapcopy(char **map, t_map *ptr)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (ptr->height + 1));
	if (!copy)
		return (NULL);
	while (i < ptr->height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
