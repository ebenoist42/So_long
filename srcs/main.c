/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 08:22:49 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/10 13:41:19 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game(t_game *game)
{
	int y;
	int x;

	y = 0;
	game->mlx= mlx_init();
	if(!game->mlx)
		error_mlx(game);
	x = ft_strlen(game->map[0]) - 1;
	while(game->map[y])
		y++;
	game->win = mlx_new_window(game->mlx, x * TILE_SIZE, y * TILE_SIZE, "so_long");
	if(!game->win)
		error_mlx(game);
	load_image(game);
	render_map(game);
}

int main (int ac, char **av)
{
	t_game game;

	ft_arg_error(ac, av[1]);
	game.map = read_file(av[1]);
	ft_check_norm(game.map);
	game.moves = 0;
	init_game(&game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
