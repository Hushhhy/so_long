/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:27:02 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/17 16:06:25 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	ft_free(game);
	exit(0);
}

void	exit_game(t_map *game, int win)
{
	game->steps += 1;
	ft_printf("steps %d\n", game->steps);
	if (win == 1)
		ft_printf("Congrats! You won!\n");
	else
		ft_printf("Nice try! You lose!\n");
	del_img(game);
	del_wall(game);
	del_exit(game);
	del_spawn(game);
	del_player(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free(game);
	exit(0);
}