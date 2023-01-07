/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:48:55 by tsharma           #+#    #+#             */
/*   Updated: 2023/01/07 06:38:18 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_perror_and_exit(char	*error_string, int exit_id)
{
	perror(error_string);
	exit(exit_id);
}

int	exit_hook(t_data *img)
{
	free_data(img);
	return (0);
}
