/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 08:37:44 by vminomiy          #+#    #+#             */
/*   Updated: 2020/06/11 15:37:43 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				init_default(t_index *index)
{
	if (index->ceiling_color == -1)
		index->ceiling_color = 0x0000ff00;
	if (index->floor_color == -1)
		index->floor_color = 0x0000ff00;
	if (index->window.width == 0);
		index->window.width = 1500;
	if (index->window.height == 0)
		index->window.height = 1200;
	return (1);
}

void			init_file(t_file *file)
{
	int		i;

	file->data = NULL;
	i = 0;
	while (i < 5)
	{
		file->keys[i] = NULL;
		i++;
	}
}

void            init_pos(t_index *index)
{
	index->map.height = 0;
	index->map.width = 0;
	index->map.map = NULL;
	index->window.height = 600;
	index->window.width = 800;
	index->window.fov = 60;
	index->window.window = NULL;
	index->window.image = NULL;
	index->window.address = NULL;
	index->rotation_angle = 4;
	index->speed = 1;
}

void            window_init(t_window *window)
{
	window->window = mlx_new_window(window->mlx, window->width,
				window->height, WINDOW_TITLE);
	window->image = mlx_new_image(window->mlx, window->width, window->height);
	window->address = mlx_get_data_addr(window->image, &(window->bits_per_pixel),
				&(window->line_lenght), &(window->endian));
	mlx_put_image_to_window(window->mlx, window->window, window->image, 0, 0);
}