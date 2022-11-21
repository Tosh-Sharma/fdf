/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:39:07 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/21 17:57:38 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// put_pixel(&img, x * 15, y * 15, 0x00FF0000);
void	create_mesh(t_point **map, t_input *input, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < input->row_count)
	{
		j = -1;
		while (++j < input->column_count)
		{
			map[i][j].x = map[i][j].x * cos(PI) - map[i][j].y * sin(PI);
			map[i][j].y = map[i][j].x * sin(PI) + map[i][j].y * cos(PI);
			if (input->map[i][j] > 0)
				put_pixel(img, map[i][j].x * 10, map[i][j].y * 10, 0x00FF0000);
			else
				put_pixel(img, map[i][j].x * 10, map[i][j].y * 10, 0x00FFFFFF);
		}
	}
}
