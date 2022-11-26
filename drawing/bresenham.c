/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:51 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/26 19:54:29 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
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
