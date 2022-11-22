/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:51 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/22 17:13:28 by tsharma          ###   ########.fr       */
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

void	compare_and_update_variable(t_point *p, char c)
{
	if (c == 'x')
	{
		if (p[0].x < p[1].x)
			p[0].x++;
		else
			p[0].x--;
	}
	else
	{
		if (p[0].y < p[1].y)
			p[0].y++;
		else
			p[0].y--;
	}
}

void	plot_pixel(t_point *p, t_input *input, t_data *img, int *diff)
{
	int	pk;
	int	i;

	(void)input;
	i = 0;
	pk = 2 * diff[1] - diff[0];
	while (i <= diff[0])
	{
		compare_and_update_variable(p, 'x');
		if (pk < 0)
		{
			if (diff[2] == 0)
				put_pixel(img, p[0].x * 5, p[0].y * 5, 0x00FF0000);
			else
				put_pixel(img, p[0].y * 5, p[0].x * 5, 0x00FF0000);
			pk = pk + 2 * diff[1];
		}
		else
		{
			compare_and_update_variable(p, 'y');
			if (diff[2] == 0)
				put_pixel(img, p[0].x * 5, p[0].y * 5, 0x000000FF);
			else
				put_pixel(img, p[0].y * 5, p[0].x * 5, 0x0000FF00);
		}
		i++;
	}
}

void	draw_line(t_point p1, t_point p2, t_input *input, t_data *img)
{
	// int		dx;
	// int		dy;
	// t_point	*array;
	// int		*diff_array;

	(void)input;
	p1.x = p1.x + (WIN_WIDTH / 10);
	p1.y = p1.y + (WIN_HEIGHT / 10);
	p2.x = p2.x + (WIN_WIDTH / 10);
	p2.y = p2.y + (WIN_HEIGHT / 10);
	put_pixel(img, p1.x * 5, p1.y * 5, 0x00FF0000);
	// put_pixel(img, (p1.x + p2.x) * 5 / 2, (p1.y + p2.y) * 5 / 2, 0x00FF0000);
	put_pixel(img, p2.x * 5, p2.y * 5, 0x00FF0000);
	// dx = fabs(p2.x - p1.x);
	// dy = fabs(p2.y - p1.y);
	// array = (t_point *)malloc(sizeof(t_point) * 2);
	// diff_array = (int *)malloc(sizeof(int) * 3);
	// if (dx > dy)
	// {
	// 	array[0] = p1;
	// 	array[1] = p2;
	// 	diff_array[0] = dx;
	// 	diff_array[1] = dy;
	// 	diff_array[2] = 0;
	// }
	// else
	// {
	// 	array[0] = p2;
	// 	array[1] = p1;
	// 	diff_array[0] = dy;
	// 	diff_array[1] = dx;
	// 	diff_array[2] = 1;
	// }
	// plot_pixel(array, input, img, diff_array);
}
