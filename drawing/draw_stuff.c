/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:12:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/21 17:26:03 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// put_pixel(&img, x * 15, y * 15, 0x00FF0000);
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// TODO: Handle keyboard inputs like ESC to quit.
// TODO: Display text on screen.
// Handle rotation and other stuff.
void	draw_stuff(char *title, t_input *input)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_point		**map;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, title);
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	map = get_updated_co_ordinates(input);
	create_mesh(map, input, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
