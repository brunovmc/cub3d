/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 00:55:23 by vminomiy          #+#    #+#             */
/*   Updated: 2020/06/11 17:38:36 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		g_error_number;

int				exit_program(t_index *index, int ret)
{
	free_window(index);
	free_file(index);
	exit(ret);
}

int				launch_game(t_index *index)
{
	init_pos(index);
	if (!(load_file(index, index->file.filename)) || !(init_default(index)))
		return (0);
	//mem_sprites(index);
	window_init(&index->window);
	return (1);
}

int				check_args(t_index *index, int argc, char **argv)
{
	if (argc <= 0)
		g_error_number = ERR_FILE_INVALIDARG;
	else if (argc == 1)
	{
		index->file.filename = "./mapa.cub";
		return (1);
	}
	else if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] +
				(ft_strlen(argv[1]) - 4), ".cub", 4) != 0)
		g_error_number = ERR_FILE_INVALIDFNAME;
	//if (argc == 3 & ft_strncmp(argv[2], "--save", 6) != 0)
		//g_error_number = ERR_INVALID_SEC_ARG;
	if (g_error_number)
		return (0);
	index->file.filename = argv[1];
	return (argc - 1);
}

int				main(int argc, char **argv)
{
	t_index		index;
	int			args;

	if (!(index.window.mlx = mlx_init()))
	{
		g_error_number = ERR_MLX;
		ft_error_check(&index, GAME_CLOSE_NOCLEAR);
	}
	args = check_args(&index, argc, argv);
	if (!(args))
		ft_error_check(&index, GAME_CLOSE_NOCLEAR);
	if (!(launch_game(&index)))
		ft_error_check(&index, GAME_CLOSE_NOCLEAR);	
	if (args == 2)
		exit_program(&index, 0);
	mlx_loop(index.window.mlx);
	return (0);
}