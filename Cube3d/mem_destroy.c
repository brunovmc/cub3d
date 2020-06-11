/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:46:59 by vminomiy          #+#    #+#             */
/*   Updated: 2020/06/11 16:45:51 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    	        free_window(t_index *index)
{
	if (index->window.image && index->window.mlx)
		mlx_destroy_image(index->window.mlx, index->window.mlx);
	if (index->window.window && index->window.mlx)
		mlx_destroy_window(index->window.window, index->window.mlx);
}

void               free_file(t_index *index)
{
	int         i;

	i = 0;
	while (i < 5)
	{
		if (index->file.keys[i])
			free(index->file.keys[i]);
		i++;
	}
	ft_arraylen(index->file.data);
	init_file(&index->file);
}