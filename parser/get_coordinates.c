/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:33:38 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/24 23:33:03 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// TODO: Handle the stuff to handle translate information correctly.
// TODO: Handle angle rotation and so on
t_point	**get_updated_co_ordinates(t_data *img)
{
	int		i;
	int		j;
	t_point	**map;
	t_trig	z;

	map = (t_point **)malloc(sizeof(t_point *) * img->input->row_count);
	assign_angles(img->params, &z);
	i = -1;
	while (++i < img->input->row_count)
	{
		map[i] = (t_point *)malloc(sizeof(t_point) * img->input->column_count);
		if (!map[i])
			exit(EXIT_SUCCESS);
	}
	i = -1;
	while (++i < img->input->row_count)
	{
		j = -1;
		while (++j < img->input->column_count)
		{
			map[i][j].x = (i * (z.cos_b * z.cos_g)) + (j * ((z.sin_a * z.sin_b
							* z.cos_g) - (z.cos_a * z.sin_g))) + (
					img->input->map[i][j] * ((z.cos_a * z.sin_b * z.cos_g)
						+ (z.sin_a * z.sin_g)));
			// map[i][j].y = (i * (z.cos_b * z.cos_g)) + (j * (z.sin_a * z.sin_b));
		}
	}
	return (map);
}

// map[i][j].x = ((j - img->input->map[i][j]) * cos(M_PI / 6)) * 10;
// map[i][j].y = (i + (j + img->input->map[i][j]) * sin(M_PI / 6)) * 10;
// printf("Old (x, y, z) is %d, %d, %d\n", i, j, input->map[i][j]);
// printf("New (x, y) is %f, %f\n", map[i][j].x, map[i][j].y);