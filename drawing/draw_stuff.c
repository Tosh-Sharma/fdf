/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:12:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/24 21:40:15 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_data(t_data *img)
{
	int	i;

	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->img);
	free(img->mlx_win);
	free(img->mlx);
	i = 0;
	while (i < img->input->row_count)
	{
		free(img->input->map[i]);
		i++;
	}
	free(img->input->map);
}

// put_pixel(&img, x * 15, y * 15, 0x00FF0000);
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//	We use the keypad to handle inputs
//	0	1	2	3	4	5	6	7	8	9
//	48	49	50	51	52	53	54	55	56	57
int	key_hook(int keycode, t_data *img)
{
	t_point	**map;

	if (keycode == 53)
	{
		free_data(img);
		system("leaks fdf");
		exit(1);
	}
	if (keycode == 48)
		img->params.zoom -= 0.5;
	else if (keycode == 53)
		img->params.zoom += 0.5;
	else if (keycode == 56)
		img->params.beta += (M_PI / 18);
	else if (keycode == 50)
		img->params.beta -= (M_PI / 18);
	else if (keycode == 52)
		img->params.alpha -= (M_PI / 18);
	else if (keycode == 54)
		img->params.alpha += (M_PI / 18);
	else if (keycode == 57)
		img->params.gamma += (M_PI / 18);
	else if (keycode == 49)
		img->params.gamma -= (M_PI / 18);
	map = get_updated_co_ordinates(img);
	// TODO: Destroy the image here before rewriting it.
	create_mesh(map, img);
	return (0);
}

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
	img.params.zoom = 7;
	img.params.alpha = 0.0;
	img.params.beta = 45.0;
	img.params.gamma = 35.264;
	map = get_updated_co_ordinates(&img);
	create_mesh(map, &img);
	mlx_key_hook(img.mlx_win, &key_hook, &img);
	mlx_loop(img.mlx);
}
