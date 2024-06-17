/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/17 16:06:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_map *game)
{
	if (game->split[game->y - 1][game->x] != '1')
	{
		if (game->split[game->y - 1][game->x] == 'E' && game->c == 0)
			exit_game(game, 1);
		else if (game->split[game->y = 1][game->x] == 'E' && game->c != 0)
			return ;
		game->split[game->y][game->x] = '0';
		game->y -= 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] = 'P';
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
		game->split[game->y][game->x] = '0';
		game->y += 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] = 'P';
		game->steps += 1;
		ft_printf ("steps%d\n", game->steps);
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
		game->split[game->y][game->x] = '0';
		game->x -= 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] = 'P';
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
		game->split[game->y][game->x] = '0';
		game->x += 1;
		if (game->split[game->y][game->x] == 'C')
			game->c -= 1;
		game->split[game->y][game->x] == 'P';
		game->steps += 1;
		ft_printf("steps %d\n", game->steps);
	}
}