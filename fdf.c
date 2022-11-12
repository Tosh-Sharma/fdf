/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:14:48 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/12 16:29:33 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, int color);

// The way to solve is as follows.
// 1. Read file, ensure file is correctly parsed and not stupid.
// 2. Take all the numbers as pixels into the code
// 3. Assign co-ordinates to them all according to their positioning.
// 4. Now for the real part, first, print pixels in 2D correctly.
// 5. Then draw lines for everything.
// 6. Then turn everything by 45 degrees and print it.
// 7. Now account for the 3rd dimension and print the pixels
//		accordingly in the 3rd dimension.
// 8. Hopefully the lines are all still connecting,
//		therefore mission accomplished.
// 9. Now do Bonuses: colors, rotation, translation, zoom in
//		and zoom out and so on.
int	main(int argc, char **argv)
{
	t_input	input;
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	if (argc != 2)
	{
		perror("You can only pass one argument. \
			Don't waste time testing stupid stuff.");
		exit(0);
	}
	else
	{
		traverse_file(argv[1], &input);
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 1920, 1080, argv[1]);
		// img.img = mlx_new_image(mlx, 1920, 1080);
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		// 		&img.line_length, &img.endian);
		// put_pixel(&img, 5, 5, 0x00FF0000);
		// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		// mlx_loop(mlx);
	}
	return (0);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
