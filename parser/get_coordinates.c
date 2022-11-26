/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:33:38 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/26 22:58:42 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// In case you are curious about the following formula: refer to below link
//	https://en.wikipedia.org/wiki/Rotation_matrix#General_rotations
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
					+ img->params.zero_x) * img->params.zoom;
			map[i][j].y = (((i * (z.cos_b * z.cos_g)) + (j * (z.sin_a * z.sin_b
								* z.sin_g + z.cos_a * z.cos_g)) + (
							img->input->map[i][j] * ((z.cos_a * z.sin_b
									* z.sin_g) - (z.sin_a * z.sin_g))))
					+ img->params.zero_y) * img->params.zoom;
		}
	}
}

void	get_updated_co_ordinates(t_data *img)
{
	t_trig	z;

	z.cos_a = cos(img->params.alpha);
	z.cos_b = cos(img->params.beta);
	z.cos_g = cos(img->params.gamma);
	z.sin_a = sin(img->params.alpha);
	z.sin_b = sin(img->params.beta);
	z.sin_g = sin(img->params.gamma);
	apply_rotation(img, img->map, z);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char		*dst;
	static int	flag = 0;

	if (flag == 0)
	{
		flag = 1;
		printf("(x, y) is (%d,%d)\n", x, y);
	}
	printf("x, y is %d\n");
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
	{
		printf("x and y are %d and %d\n", x, y);
		return ;
	}
	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_line(t_line	*line, t_data *img)
{
	double	pixel_x;
	double	pixel_y;

	pixel_x = line->start.x;
	pixel_y = line->start.y;
	while (line->pixels > 0)
	{
		put_pixel(img, pixel_x, pixel_y, 0x00FF0000);
		pixel_x += line->delta_y;
		pixel_y += line->delta_y;
		--line->pixels;
	}
}

void	draw_line(t_point p1, t_point p2, t_data *img)
{
	put_pixel(img, p1.x, p1.y, 0x00FF0000);
	put_pixel(img, (p1.x + p2.x) / 2, (p1.y + p2.y) / 2, 0x00FFFFFF);
	put_pixel(img, p2.x, p2.y, 0x00FF0000);
	// t_line	line;

	// line.delta_x = p2.x - p1.x;
	// line.delta_y = p2.y - p1.y;
	// line.pixels = sqrt((line.delta_x * line.delta_x)
	// 		+ (line.delta_y * line.delta_y));
	// line.delta_x /= line.pixels;
	// line.delta_y /= line.pixels;
	// line.start = p1;
	// line.end = p2;
	// put_line(&line, img);
}
