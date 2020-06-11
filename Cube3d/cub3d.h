/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 00:14:49 by vminomiy          #+#    #+#             */
/*   Updated: 2020/06/11 16:45:59 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define WINDOW_TITLE "Cub3d"

# define GAME_CLOSE_NOCLEAR 0
# define GAME_CLOSE_CLEAR 1

typedef struct			s_window
{
	void			*mlx;
	void			*window;
	void			*image;
	void			*address;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	int				width;
	int				height;
	float			fov;
}						t_window;

typedef struct			s_file
{
	char			*filename;
	char			**data;
	char			*keys[5];
}						t_file;

typedef struct			s_map
{
	int				**map;
	int				height;
	int				width;
}						t_map;

typedef struct          s_index
{
	t_window		window;
	t_file			file;
	t_map			map;
	float			rotation_angle;
	float			speed;
	int				ceiling_color;
	int				floor_color;
}						t_index;

int				main(int argc, char **argv);
int				launch_game(t_index *index);
int				load_file(t_index *index, char *filename);
char            **read_file(char *filename);
char			**malloc_files(char **str);
int				ft_arraylen(char **array);

void			init_pos(t_index *index);
void            window_init(t_window *window);
int				init_default(t_index *index);
void			init_file(t_file *file);

int             ft_error_check(t_index *index, int exit_code);
char            *get_error(int error);

void			free_window(t_index *index);
void			free_file(t_index *index);

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_FILE_INVALIDARG 2
# define ERR_FILE_INVALIDFNAME 25
# define ERR_INVALID_SEC_ARG 22
# define ERR_MLX 30

extern int		g_error_number;

#endif

#endif