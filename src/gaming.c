/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:57:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/13 16:33:57 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_gaming(t_map *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (ft_free(game->split), ft_putstr_fd("MLX Error!\n", 2), 1);
	init_game(game);
}

void	init_game(t_map *game)
{
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if (game->width * 64 > game->screen_width
		|| game->height * 64 > game->screen_height)
	{
		ft_putstr_fd("Error! Map too big!\n", 2);
		close_game(game);
	}
	game->win = mlx_new_window(game->mlx, game->width * 64,
					game->height * 64, "so_long");
	get_img(game);
	put_img(game);
}

int	close_game(t_map *game)
{
	del_img(game);
	del_player(game);
	del_wall(game);
	del_exit(game);
	del_spawn(game);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free(game->split);
	exit(0);
}