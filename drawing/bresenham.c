/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:51 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/21 21:34:09 by tsharma          ###   ########.fr       */
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
void	draw_line(t_point p1, t_point p2, t_input *input, t_data *img)
{
	(void)input;
	p1.x = p1.x + (WIN_WIDTH / 10);
	p1.y = p1.y + (WIN_HEIGHT / 10);
	p2.x = p2.x + (WIN_WIDTH / 10);
	p2.y = p2.y + (WIN_HEIGHT / 10);
	put_pixel(img, p1.x * 5, p1.y * 5, 0x00FF0000);
	// put_pixel(img, (p1.x + p2.x) * 5 / 2, (p1.y + p2.y) * 5 / 2, 0x00FF0000);
	put_pixel(img, p2.x * 5, p2.y * 5, 0x00FF0000);
}
