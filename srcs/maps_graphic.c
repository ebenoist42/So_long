/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:15:49 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/09 14:51:30 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
static void	collectible_environent(t_game *game, int *x, int *y)
{
	if(game->map[*y][*x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, *x *TILE_SIZE, *y * TILE_SIZE)
}
void	render_map(t_game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
				* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
					* TILE_SIZE, y * TILE_SIZE)
			else
					collectible_environent()
		}
	}
}
void	load_image(t_game *game)
{
	int i;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./img/tile-wall.xpm", &i,
			&i);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./img/sprite-player.xpm", &i, &i);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./img/tile-floor.xpm",
			&i, &i);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./img/chest1.xpm", &i,
			&i);
	if (!game->img_wall || !game->img_player || !game->img_floor
		|| !game->img_exit || !game->img_exit2 || !game->img_enemy)
		error_load(game);
}