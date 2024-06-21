/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:49:32 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/21 17:02:23 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_image(t_map *game)
{
	get_img(game, "images/floor/floor.xpm", (void **)&game->img.floor);
	get_img(game, "images/collect/collect.xpm", (void **)&game->img.collect);
	get_img(game, "images/enemie/enemie.xpm", (void **)&game->img.enemies);
	get_img(game, "images/exit/exit.xpm", (void **)&game->img.exit);
	get_img(game, "images/player/player.xpm", (void **)&game->img.player);
	get_img(game, "images/wall/wall.xpm", (void **)&game->img.wall);
}
