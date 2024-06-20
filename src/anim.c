/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:14:02 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/20 15:00:34 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_wall_anim(t_map *game, int fcount)
{
	if (fcount % WALL_DELAY == 0)
	{
		if (game->wall.frame == WALL_FRAMES - 1)
			game->wall.frame = 0;
		else
			game->wall.frame++;
	}
}

void	update_exit_anim(t_map *game, int fcount)
{
	if (fcount % EXIT_DELAY == 0)
	{
		if (game->exit.frame == EXIT_FRAMES - 1)
			game->exit.frame = 0;
		else
			game->exit.frame++;
	}
}

void	update_spawn_anim(t_map *game, int fcount)
{
	if (fcount % SPAWN_DELAY == 0)
	{
		if (game->spawn.frame == SPAWN_FRAMES - 1)
			game->spawn.frame = 0;
		else
			game->spawn.frame++;
	}
}

void	update_player_anim(t_map *game, int fcount)
{
	if (fcount % PLAYER_DELAY == 0)
	{
		if (game->player.frame == PLAYER_FRAMES - 1)
			game->player.frame = 0;
		else
			game->player.frame++;
	}
}

int	update_anim(t_map *game)
{
	static int	fcount = 0;

	fcount++;
	if (fcount > 94120)
		fcount = 0;
	update_wall_anim(game, fcount);
	update_exit_anim(game, fcount);
	update_spawn_anim(game, fcount);
	update_player_anim(game, fcount);
	if (fcount % FRAME_DELAY == 0)
	{
		put_img(game);
		display_steps(game);
	}
	return (0);
}
