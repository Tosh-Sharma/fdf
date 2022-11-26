/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:12:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/26 02:42:21 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_data(t_data *img)
{
	int	i;

	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	i = 0;
	while (i < img->input->row_count)
	{
		free(img->input->map[i]);
		free(img->map[i]);
		i++;
	}
	free(img->input->map);
	free(img->map);
	exit(1);
}

// put_pixel(&img, x * 15, y * 15, 0x00FF0000);
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
		free_data(img);
	if (keycode == 82)
		img->params.zoom -= 1;
	else if (keycode == 87)
		img->params.zoom += 1;
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

// TODO: Display text on screen.
// Handle rotation and other stuff.
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
	img.params.zoom = 7;
	img.params.alpha = 0.0;
	img.params.beta = 0.0;
	img.params.gamma = 0.0;
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
