/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:33:38 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/26 02:28:30 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	apply_rotation(t_data *img, t_point **map, t_trig z)
{
	int	i;
	int	j;

	i = -1;
	while (++i < img->input->row_count)
	{
		j = -1;
		while (++j < img->input->column_count)
		{
			map[i][j].x = (((i * (z.cos_b * z.cos_g)) + (j * ((z.sin_a * z.sin_b
									* z.cos_g) - (z.cos_a * z.sin_g))) + (
							img->input->map[i][j] * ((z.cos_a * z.sin_b
									* z.cos_g) + (z.sin_a * z.sin_g))))
					+ WIN_WIDTH / 2) * img->params.zoom;
			map[i][j].y = (((i * (z.cos_b * z.cos_g)) + (j * (z.sin_a * z.sin_b
								* z.cos_g + z.cos_a * z.sin_g)) + (
							img->input->map[i][j] * ((z.cos_a * z.sin_b
									* z.sin_g) - (z.sin_a * z.sin_g))))
					+ WIN_HEIGHT / 10) * img->params.zoom;
		}
	}
}

// TODO: Handle the stuff to handle translate information correctly.
// TODO: Handle angle rotation and so on
void	get_updated_co_ordinates(t_data *img)
{
	t_trig	z;

	assign_angles(img->params, &z);
	apply_rotation(img, img->map, z);
}
