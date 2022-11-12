/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:29:04 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/12 16:46:08 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	convert_input(int file_fd, t_input *input)
{
	int		i;
	int		j;
	char	*line;
	char	**numbers;

	input->map = (int **)malloc(sizeof(int *) * input->row_count);
	if (!input->map)
		ft_perror_and_exit("Could not allocate memory. Try again", 1);
	i = 0;
	while (i < input->row_count)
	{
		j = 0;
		input->map[i] = (int *)malloc(sizeof(int) * input->column_count);
		if (!input->map[i])
			ft_perror_and_exit("Could not allocate memory. Try again", 1);
		line = get_next_line(file_fd);
		numbers = ft_split(line, ' ');
		while (j < input->column_count)
		{
			input->map[i][j] = ft_superatoi(numbers[j]);
			j++;
		}
		i++;
	}
}
