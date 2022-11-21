/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:29:04 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/18 18:08:11 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_them_all(char **numbers, int column_count)
{
	int	i;

	i = 0;
	while (i < column_count)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

char	**get_line(int file_fd)
{
	char	*line1;
	char	**line2;
	char	**numbers;

	line1 = get_next_line(file_fd);
	line2 = ft_split(line1, '\n');
	numbers = ft_split(line2[0], ' ');
	free(line1);
	free(line2[0]);
	free(line2[1]);
	free(line2);
	return (numbers);
}

void	convert_input(int file_fd, t_input *input)
{
	int		i;
	int		j;
	char	**numbers;

	input->map = (int **)malloc(sizeof(int *) * input->row_count);
	if (!input->map)
		ft_perror_and_exit("Could not allocate memory. Try again", 1);
	i = 0;
	while (i < input->row_count)
	{
		j = 0;
		input->map[i] = (int *)malloc(sizeof(int) * (input->column_count));
		if (!input->map[i])
			ft_perror_and_exit("Could not allocate memory. Try again", 1);
		numbers = get_line(file_fd);
		while (j < input->column_count)
		{
			input->map[i][j] = ft_superatoi(numbers[j]);
			j++;
		}
		free_them_all(numbers, input->column_count);
		i++;
	}
}
