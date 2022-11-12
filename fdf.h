/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:04:40 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/12 16:36:14 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_data;

typedef struct s_input {
	int	**map;
	int	row_count;
	int	column_count;
}	t_input;

void	traverse_file(char *path, t_input *input);
void	ft_perror_and_exit(char	*error_string, int exit_id);
void	convert_input(int file_fd, t_input *input);

#endif