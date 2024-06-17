/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:57:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/17 16:13:51 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_gaming(t_map *game)
{
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if (game->width * 64 > game->screen_width
			|| game->height * 64 > game->screen_height);
	{
		ft_putstr_fd("Error! Map too big!\n", 2);
		close_game(game);
	}
	game->win = mlx_new_window(game->mlx, game->width * 64,
					game->height * 64, "so_long");
	game->wall.frame = 0;
	game->exit.frame = 0;
	game->spawn.frame = 0;
	game->player.frame = 0;
	game->steps = 0;
	get_img(game);
	put_img(game);
	mlx_loop_hook(game->mlx, update_anim, map);
}

