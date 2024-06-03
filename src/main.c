/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:34:09 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/03 15:15:48 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	ft_structinit(t_map *game)
{
	game->C = 0;
	game->E = 0;
	game->P = 0;
	game->x = 0;
	game->y = 0;
}

int	main(int ac, char **av)
{
	char 	*map;
	char	**split;
	t_map	*game;

	game = malloc(sizeof(t_map));
	if (ac == 2)
	{
		ft_checkname(av[1]);	
		map = ft_getmap(av[1]);
		ft_emptyline(map);
		split = ft_split(map, '\n');
		ft_parsemap(split, game);
		printf("Valid map!");
	}
	else
	{
		ft_printf("Error! Argument number must be 1 !");
		return (0);
	}
	free(map);
	return (0);
}
