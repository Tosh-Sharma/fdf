/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:04:40 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/24 01:10:14 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# include <fcntl.h>
# include <stdio.h>

# define WIN_HEIGHT 720
# define WIN_WIDTH 1280

typedef struct s_input {
	int	**map;
	int	row_count;
	int	column_count;
}	t_input;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	t_input	*input;
	void	*mlx;
	void	*mlx_win;
}	t_data;

typedef struct s_2d_point {
	double	x;
	double	y;
}	t_point;

/*	Parsing functions	*/
void	traverse_file(char *path, t_input *input);
void	convert_input(int file_fd, t_input *input);
t_point	**get_updated_co_ordinates(t_input *input);

/*	Drawing functions	*/
void	draw_stuff(char *title, t_input *input);
void	put_pixel(t_data *data, int x, int y, int color);
void	create_mesh(t_point **map, t_data *img);
void	draw_line(t_point p1, t_point p2, t_input *input, t_data *img);

/*	Error functions		*/
void	ft_perror_and_exit(char	*error_string, int exit_id);

#endif