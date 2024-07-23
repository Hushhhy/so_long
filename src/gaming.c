/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:57:29 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/23 14:45:22 by acarpent         ###   ########.fr       */
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
		ft_printf("Error!\nFailed to load image : %s\n", path);
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
			game->img.wall, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.collect,
			x * 64, y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * 64, y * 64);
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
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error!\n");
		exit(0);
	}
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if (game->width * 64 > game->screen_width
		|| game->height * 64 > game->screen_height)
	{
		ft_putstr_fd("Error!\nMap too big!\n", 2);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_free(game->split);
		free(game->map);
		exit(0);
	}
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	game->steps = 0;
	get_image(game);
	put_img(game);
}
