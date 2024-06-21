/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:27:02 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/21 15:53:50 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	del_img(t_map *game)
{
	if (game->img.floor != NULL)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.collect != NULL)
		mlx_destroy_image(game->mlx, game->img.collect);
	if (game->img.enemies != NULL)
		mlx_destroy_image(game->mlx, game->img.enemies);
	if (game->img.exit != NULL)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.player != NULL)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.wall != NULL)
		mlx_destroy_image(game->mlx, game->img.wall);
}
