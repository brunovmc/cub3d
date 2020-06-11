/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:14:16 by vminomiy          #+#    #+#             */
/*   Updated: 2020/06/11 16:20:06 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

char				**malloc_files(char **str)
{
	int			size;
	char		**tmp;
	int			i;

	i = 0;
	if (!str)
		str = (char **)ft_calloc(1, sizeof(char *));
	tmp = str;
	size = ft_arraylen(str);
	str = (char **)ft_calloc((size + 2), sizeof(char *));
	while (i < size)
	{
		str[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (str);
}

char                **read_file(char *filename)
{
	char        **str;
	char		*line;
	int			i;
	int			fd;
	int			ret;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		g_error_number = ERR_FILE_INVALIDFNAME;
		return (0);
	}
	i = 0;
	str = NULL;
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		str = malloc_files(str);
		str[i] = line;
		i++;
		if (ret == 0)
			break ;
	}
	close (fd);
	return (str);
}

int                 load_file(t_index *index, char *filename)
{
	init_file(&index->file);
	if (!(index->file.data = read_file(filename)))
		return (0);
	return (1);
}