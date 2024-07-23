/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:23:25 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/10 13:44:49 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_map *game)
{
	del_img(game);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free(game->split);
	free(game->map);
	exit(0);
}

void	exit_game(t_map *game, int win)
{
	game->steps += 1;
	ft_printf("steps %d\n", game->steps);
	if (win == 1)
		ft_printf("Congrats! You won!\n");
	else
		ft_printf("You're Dead! Try again!\n");
	del_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit_handler(game);
	exit(0);
}
