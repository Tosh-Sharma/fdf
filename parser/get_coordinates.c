/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:33:38 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/21 20:08:45 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// TODO: Handle the stuff to handle translate information correctly.
// TODO: Handle angle rotation and so on
t_point	**get_updated_co_ordinates(t_input *input)
{
	int		i;
	int		j;
	t_point	**map;

	map = (t_point **)malloc(sizeof(t_point *) * input->row_count);
	i = -1;
	while (++i < input->row_count)
	{
		map[i] = (t_point *)malloc(sizeof(t_point) * input->column_count);
		if (!map[i])
			exit(EXIT_SUCCESS);
	}
	i = -1;
	while (++i < input->row_count)
	{
		j = -1;
		while (++j < input->column_count)
		{
			map[i][j].x = (j - input->map[i][j]) * cos(PI / 6);
			map[i][j].y = i + (j + input->map[i][j]) * sin(PI / 6);
			// printf("Old (x, y, z) is %d, %d, %d\n", i, j, input->map[i][j]);
			// printf("New (x, y) is %f, %f\n", map[i][j].x, map[i][j].y);
		}
	}
	return (map);
}
