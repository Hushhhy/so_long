/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:34:09 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/23 14:44:23 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_structinit(t_map *game)
{
	game->c = 0;
	game->e = 0;
	game->p = 0;
	game->x = 0;
	game->y = 0;
}

void	exit_handler(t_map *game)
{
	free(game->map);
	ft_free(game->split);
	exit(1);
}

int	key_pressed(int key, t_map *game)
{
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_W || key == KEY_UP)
		move_up(game);
	if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	if (key == KEY_D || key == KEY_RIGHT)
		move_right(game);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_map	game;

	if (ac != 2 || ft_checkname(av[1]) == 1)
	{
		ft_putstr_fd("Error!\nWrong Argument or map name!\n", 2);
		return (1);
	}
	if (!env[0])
		return (ft_printf("Empty env\n"), 0);
	ft_structinit(&game);
	if (!ft_getmap(&game, av[1]))
	{
		ft_printf("Error!\nMap doesn't exist\n");
		return (1);
	}
	ft_emptyline(&game);
	ft_checkchar(&game);
	game.split = ft_split(game.map, '\n');
	ft_parsemap(&game);
	ft_gaming(&game);
	mlx_hook(game.win, 2, 1L << 0, key_pressed, &game);
	mlx_hook(game.win, 17, 1L << 17, close_game, &game);
	mlx_loop(game.mlx);
	exit_handler(&game);
	return (0);
}
