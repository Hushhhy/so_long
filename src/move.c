/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/21 16:24:52 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_map *game)
{
	if (game->split[game->y - 1][game->x] != '1')
	{
		if (game->split[game->y - 1][game->x] == 'E' && game->c == 0)
			exit_game(game, 1);
		else if (game->split[game->y - 1][game->x] == 'E' && game->c != 0)
			return ;
		else if (game->split[game->y - 1][game->x] == 'N')
			exit_game(game, 0);
		game->split[game->y][game->x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
			game->x * 64, game->y * 64);
		game->y -= 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			game->x * 64, game->y * 64);
		game->steps += 1;
		ft_printf("steps %d\n", game->steps);
	}
}

void	move_down(t_map *game)
{
	if (game->split[game->y + 1][game->x] != '1')
	{
		if (game->split[game->y + 1][game->x] == 'E' && game->c == 0)
			exit_game(game, 1);
		else if (game->split[game->y + 1][game->x] == 'E' && game->c != 0)
			return ;
		else if (game->split[game->y + 1][game->x] == 'N')
			exit_game(game, 0);
		game->split[game->y][game->x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
			game->x * 64, game->y * 64);
		game->y += 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			game->x * 64, game->y * 64);
		game->steps += 1;
		ft_printf ("steps %d\n", game->steps);
	}
}

void	move_left(t_map *game)
{
	if (game->split[game->y][game->x - 1] != '1')
	{
		if (game->split[game->y][game->x - 1] == 'E' && game->c == 0)
			exit_game(game, 1);
		else if (game->split[game->y][game->x - 1] == 'E' && game->c != 0)
			return ;
		else if (game->split[game->y][game->x - 1] == 'N')
			exit_game(game, 0);
		game->split[game->y][game->x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
			game->x * 64, game->y * 64);
		game->x -= 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			game->x * 64, game->y * 64);
		game->steps += 1;
		ft_printf("steps %d\n", game->steps);
	}
}

void	move_right(t_map *game)
{
	if (game->split[game->y][game->x + 1] != '1')
	{
		if (game->split[game->y][game->x + 1] == 'E' && game->c == 0)
			exit_game(game, 1);
		else if (game->split[game->y][game->x + 1] == 'E' && game->c != 0)
			return ;
		else if (game->split[game->y][game->x + 1] == 'N')
			exit_game(game, 0);
		game->split[game->y][game->x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
			game->x * 64, game->y * 64);
		game->x += 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			game->x * 64, game->y * 64);
		game->steps += 1;
		ft_printf("steps %d\n", game->steps);
	}
}

void	display_steps(t_map *game)
{
	char	*msg;
	char	*scount;

	scount = ft_itoa(game->steps);
	msg = ft_strjoin("Step count: ", scount);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, msg);
	free(scount);
	free(msg);
}
