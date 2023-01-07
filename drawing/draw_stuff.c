/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:12:49 by tsharma           #+#    #+#             */
/*   Updated: 2023/01/07 04:50:42 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_zoom_zoom(int keycode, t_data *img)
{
	if (keycode == 82)
		img->params.zoom -= 1;
	else if (keycode == 87)
		img->params.zoom += 1;
}

// 124 is right. 123 is left.
// 126 is up. 125 is down.
void	translate_it(int keycode, t_data *img)
{
	if (keycode == 123)
		img->params.zero_x -= 30;
	else if (keycode == 124)
		img->params.zero_x += 30;
	else if (keycode == 125)
		img->params.zero_y += 30;
	else if (keycode == 126)
		img->params.zero_y -= 30;
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 124 || keycode == 123 || keycode == 126 || keycode == 125)
		translate_it(keycode, img);
	else if (keycode == 53)
		free_data(img);
	else if (keycode == 82 || keycode == 87)
		zoom_zoom_zoom(keycode, img);
	else if (keycode == 91)
		img->params.beta += (M_PI / 18);
	else if (keycode == 84)
		img->params.beta -= (M_PI / 18);
	else if (keycode == 86)
		img->params.alpha -= (M_PI / 18);
	else if (keycode == 88)
		img->params.alpha += (M_PI / 18);
	else if (keycode == 92)
		img->params.gamma += (M_PI / 18);
	else if (keycode == 83)
		img->params.gamma -= (M_PI / 18);
	get_updated_co_ordinates(img);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGHT);
	create_mesh(img);
	return (0);
}

void	initialize_params(t_data *img)
{
	img->params.zoom = 5;
	img->params.alpha = 0.0;
	img->params.beta = 0.0;
	img->params.gamma = 0.0;
	img->params.zero_x = WIN_WIDTH / 10;
	img->params.zero_y = WIN_HEIGHT / 10;
}

// TODO: Display text on screen.
void	draw_stuff(char *title, t_input *input)
{
	t_data		img;
	int			i;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.input = input;
	initialize_params(&img);
	img.map = (t_point **)malloc(sizeof(t_point *) * input->row_count);
	i = -1;
	while (++i < input->row_count)
	{
		img.map[i] = (t_point *)malloc(sizeof(t_point) * input->column_count);
		if (!img.map[i])
			exit(EXIT_SUCCESS);
	}
	get_updated_co_ordinates(&img);
	create_mesh(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, &key_hook, &img);
	mlx_loop(img.mlx);
}
