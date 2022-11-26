/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:39:07 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/26 02:24:40 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	create_mesh(t_data *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < img->input->row_count)
	{
		i = -1;
		while (++i < img->input->column_count)
		{
			if (j != (img->input->row_count - 1))
				draw_line(img->map[j][i], img->map[j + 1][i], img);
			if (i != (img->input->column_count - 1))
				draw_line(img->map[j][i], img->map[j][i + 1], img);
		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
