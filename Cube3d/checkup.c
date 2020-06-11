/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:20:01 by vminomiy          #+#    #+#             */
/*   Updated: 2020/06/11 05:47:29 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char            *get_error(int error)
{
    if (error == ERR_MLX)
        return ("MLX deu pau");
    if (error == ERR_FILE_INVALIDARG)
        return ("Invalid arguments in the file read");
    if (error == ERR_FILE_INVALIDFNAME)
        return ("Invalid File Name");
    if (error == ERR_INVALID_SEC_ARG)
        return ("The second argument is invalid. Try '--save'.");
    return ("Unkown Error");
}

int             ft_error_check(t_index *index, int exit_code)
{
    ft_putstr("Error\n");
    ft_putnbr(g_error_number);
    ft_putstr(" - ");
    ft_putstr(get_error(g_error_number));
    ft_putstr(".\n");
    /*
    if (exit_code >= GAME_CLOSE_CLEAR)
        exit_program (index, g_error_number);
    else if (exit_code == GAME_CLOSE_NOCLEAR)
        exit(g_error_number);
        */
}
    