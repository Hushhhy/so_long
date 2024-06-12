/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:34:09 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/12 14:22:49 by acarpent         ###   ########.fr       */
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
	t_map	*game;

	game = malloc(sizeof(t_map));
	if (game == NULL)
		return (ft_putstr_fd("Malloc Error!\n", 2), 1);
	ft_structinit(game);
	if (ac != 2 || ft_checkname(av[1]))
		return (free(game), ft_putstr_fd("Wrong Argument or map name!\n", 2), 1);
	game->map = *ft_getmap(game, av[1]);
	ft_emptyline(game->map);
	game->split = ft_split(game->map, '\n');
	ft_parsemap(game->split, game);
	printf("Valid map!");
	free(game);
	return (0);
}
