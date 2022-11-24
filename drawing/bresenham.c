/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:51 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/24 17:48:05 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Bresenham's algorithm goes here.
// TODO: Draw a line between P1 and P2.
//	Links from school.
//	https://git.42l.fr/Fabien/fdf
//	https://en.wikipedia.org/wiki/Isometric_projection
//	https://math.stackexchange.com/questions/363652/understanding-rotation-matrices
//	https://stackoverflow.com/questions/38096685/how-to-flip-only-one-axis-of-transformation-matrix/38103806#38103806
//	https://stackoverflow.com/questions/62380131/inverting-the-rotation-along-the-x-and-the-y-axis-while-keeping-z-intact

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
