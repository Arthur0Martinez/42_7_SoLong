/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:45:40 by artmarti          #+#    #+#             */
/*   Updated: 2023/07/17 17:56:38 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_keypress2(int keysym, t_id *d)
{
	if (keysym == 119)
	{
		if (d->mapp.map[d->mapp.player.x - 1][d->mapp.player.y] == EXIT
			&& d->mapp.collect.nbr == 0)
			close_all(d);
		else if (d->mapp.map[d->mapp.player.x - 1][d->mapp.player.y] != WALL)
			change_map(&d->mapp, 119);
	}
	else if (keysym == 115)
	{
		if (d->mapp.map[d->mapp.player.x + 1][d->mapp.player.y] == EXIT
			&& d->mapp.collect.nbr == 0)
			close_all(d);
		else if (d->mapp.map[d->mapp.player.x + 1][d->mapp.player.y] != WALL)
			change_map(&d->mapp, 115);
	}
	else if (keysym == 97)
	{
		if (d->mapp.map[d->mapp.player.x][d->mapp.player.y - 1] == EXIT
			&& d->mapp.collect.nbr == 0)
			close_all(d);
		else if (d->mapp.map[d->mapp.player.x][d->mapp.player.y - 1] != WALL)
			change_map(&d->mapp, 97);
	}
}

int	handle_keypress(int keysym, t_id *d)
{
	if (keysym == XK_Escape)
		close_all(d);
	if (keysym == 119 || keysym == 115 || keysym == 97)
		handle_keypress2(keysym, d);
	else if (keysym == 100)
	{
		if (d->mapp.map[d->mapp.player.x][d->mapp.player.y + 1] == EXIT
			&& d->mapp.collect.nbr == 0)
			close_all(d);
		else if (d->mapp.map[d->mapp.player.x][d->mapp.player.y + 1] != WALL)
			change_map(&d->mapp, 100);
	}
	return (0);
}

void	ft_init_window(int nbr_y, int nbr_x, t_map *map)
{
	t_id	d;

	d.mapp = *map;
	d.mlx = mlx_init();
	if (d.mlx == NULL)
		return ;
	d.win = mlx_new_window(d.mlx, (WH * nbr_y), (WW * nbr_x), "Toad");
	if (d.win == NULL)
	{
		free(d.win);
		return ;
	}
	d.nbr_y = nbr_y;
	d.nbr_x = nbr_x;
	d.play.mi = mlx_xpm_file_to_image(d.mlx, "./f/P.xpm", &d.play.w, &d.play.h);
	d.exit.mi = mlx_xpm_file_to_image(d.mlx, "./f/E.xpm", &d.exit.w, &d.exit.h);
	d.coll.mi = mlx_xpm_file_to_image(d.mlx, "./f/C.xpm", &d.coll.w, &d.coll.h);
	d.wall.mi = mlx_xpm_file_to_image(d.mlx, "./f/W.xpm", &d.wall.w, &d.wall.h);
	d.grnd.mi = mlx_xpm_file_to_image(d.mlx, "./f/G.xpm", &d.grnd.w, &d.grnd.h);
	mlx_loop_hook(d.mlx, &render, &d);
	mlx_hook(d.win, KeyPress, KeyPressMask, &handle_keypress, &d);
	mlx_hook(d.win, 17, 1L << 0, close_all, &d);
	mlx_loop(d.mlx);
	return ;
}

int	ext_main(int argc, char *c)
{
	int	i;

	if (argc != 2)
	{
		if (argc < 2)
			write(2, "\nError : Map parameter missing\n\n", 32);
		else
			write(2, "\nError : Too much arguments\n\n", 29);
		return (1);
	}
	i = 0;
	while (c[i] != '\0')
		i++;
	if (c[i - 1] != 'r' || c[i - 2] != 'e'
		|| c[i - 3] != 'b' || c[i - 4] != '.')
	{
		write(2, "\nError : Not a .ber file\n\n", 26);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map2;
	t_map	dmap;

	if (ext_main(argc, argv[1]) == 1)
		return (1);
	dmap.map = get_map(argv[1], size_map(argv[1]));
	map2 = get_map(argv[1], size_map(argv[1]));
	if (ext_main2(dmap.map, map2) == 1 || dmap.map == NULL || map2 == NULL)
		return (1);
	dmap.size = size_map(argv[1]);
	check_exit_pose(&dmap.exit, dmap.map);
	check_player_pose(&dmap.player, dmap.map);
	if (main2(&dmap, map2, argv) == 1)
	{
		free_map(map2);
		free_map(dmap.map);
		return (1);
	}
	free_map(map2);
	ft_printf("\nPosition : %i, %i\n", dmap.player.x, dmap.player.y);
	ft_printf("Moves : 0\nCollectibles left : %i\n\n", dmap.collect.nbr);
	ft_init_window(size_line(dmap.map), size_map(argv[1]), &dmap);
	return (0);
}
