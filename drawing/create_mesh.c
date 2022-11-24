/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:39:07 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/23 22:56:16 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	create_mesh2(t_point **map, t_input *input, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < input->row_count)
	{
		j = -1;
		while (++j < input->column_count)
		{
			map[i][j].x = map[i][j].x + (WIN_WIDTH / 10);
			map[i][j].y = map[i][j].y + (WIN_HEIGHT / 10);
			printf("x=%f, y=%f \n", map[i][j].x, map[i][j].y);
			if (input->map[i][j] > 0)
				put_pixel(img, map[i][j].x * 5, map[i][j].y * 5, 0x00FF0000);
			else
				put_pixel(img, map[i][j].x * 5, map[i][j].y * 5, 0x00FFFFFF);
		}
	}
}

void	create_mesh(t_point **map, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < img->input->row_count)
	{
		j = -1;
		while (++j < img->input->column_count)
		{
			if (i != (img->input->row_count - 1))
				draw_line(map[i][j], map[i + 1][j], img->input, img);
			if (j != (img->input->column_count - 1))
				draw_line(map[i][j], map[i][j + 1], img->input, img);
		}
	}
}
