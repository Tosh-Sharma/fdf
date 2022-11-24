/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:12:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/24 01:11:11 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// put_pixel(&img, x * 15, y * 15, 0x00FF0000);
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;
	// TODO: Move the code for shifting the origin away from here.
	x = x + (WIN_WIDTH / 10);
	y = y + (WIN_HEIGHT / 10);
	x = x + (WIN_WIDTH / 10);
	y = y + (WIN_HEIGHT / 10);
	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_data *img)
{
	t_point	**map;

	(void)img;
	if (keycode == 53)
		exit(1);
	if (keycode == 2)
	{
		map = get_updated_co_ordinates(img->input);
		create_mesh(map, img);
		// We need put image to window to push the image to the window.
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	return (0);
}

// TODO: Handle keyboard inputs like ESC to quit.
// TODO: Display text on screen.
// Handle rotation and other stuff.
void	draw_stuff(char *title, t_input *input)
{
	t_data		img;
	t_point		**map;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.input = input;
	map = get_updated_co_ordinates(img.input);
	create_mesh(map, &img);
	mlx_key_hook(img.mlx_win, &key_hook, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
