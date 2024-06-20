/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:57:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/20 15:32:03 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_img(t_map *game, char *path, void **ptr)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	*ptr = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (*ptr == NULL)
	{
		ft_printf("Failed to load image : %s\n", path);
		close_game(game);
	}
}

void	put_image(t_map *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
			x * 64, y * 64);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.anim[game->wall.frame], x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.anim[game->exit.frame], x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.collect,
			x * 64, y * 64);
	else if (c == 'P')
	{
		if (game->steps == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->spawn.anim[game->spawn.frame], x * 64, y * 64);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->player.anim[game->player.frame], x * 64, y * 64);
	}
	else if (c == 'N')
		mlx_put_image_to_window(game->mlx, game->win, game->img.enemies,
			x * 64, y * 64);
}

void	put_img(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->split[y])
	{
		x = 0;
		while (game->split[y][x])
		{
			put_image(game, game->split[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	ft_gaming(t_map *game)
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
	game->wall.frame = 0;
	game->exit.frame = 0;
	game->spawn.frame = 0;
	game->player.frame = 0;
	game->steps = 0;
	// get_image(game);
	put_img(game);
	mlx_loop_hook(game->mlx, update_anim, game);
}

