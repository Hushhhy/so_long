/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:27:02 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/20 15:42:37 by acarpent         ###   ########.fr       */
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
}

void	del_player(t_map *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (game->player.anim[i] != NULL)
			mlx_destroy_image(game->mlx, game->player.anim[i]);
		i++;
	}
}

void	del_wall(t_map *game)
{
	int	i;

	i = 0;
	while (i < WALL_FRAMES)
	{
		if (game->wall.anim[i] != NULL)
			mlx_destroy_image(game->mlx, game->wall.anim[i]);
		i++;
	}
}

void	del_exit(t_map *game)
{
	int	i;

	i = 0;
	while (i < EXIT_FRAMES)
	{
		if (game->spawn.anim[i] != NULL)
			mlx_destroy_image(game->mlx, game->player.anim[i]);
		i++;
	}
}

void	del_spawn(t_map *game)
{
	int	i;

	i = 0;
	while (i < SPAWN_FRAMES)
	{
		if (game->spawn.anim[i] != NULL)
			mlx_destroy_image(game->mlx, game->spawn.anim[i]);
		i++;
	}
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
	ft_free(game->split);
	exit(0);
}