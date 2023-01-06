/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:33:38 by tsharma           #+#    #+#             */
/*   Updated: 2023/01/06 22:54:09 by tsharma          ###   ########.fr       */
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
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
	{
		printf("x and y are %d and %d\n", x, y);
		return ;
	}
	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_sign(double x)
{
	if (x >= 0)
		return (1);
	else
		return (-1);
}

void	draw_line(t_point p1, t_point p2, t_data *img)
{
	t_point	delta;
	t_point	p;
	t_point	sign;
	double	step;

	p.x = p1.x;
	p.y = p1.y;
	sign.x = ft_sign(p2.x - p1.x);
	sign.y = ft_sign(p2.y - p1.y);
	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	if (fabs(delta.x) > fabs(delta.y))
		step = fabs(delta.x);
	else
		step = fabs(delta.y);
	delta.x = delta.x / step;
	delta.y = delta.y / step;
	while (sign.x == ft_sign(p2.x - p.x) && sign.y == ft_sign(p2.y - p.y))
	{
		put_pixel(img, p.x, p.y, 0x00FF0000);
		p.x += delta.x;
		p.y += delta.y;
	}
}
