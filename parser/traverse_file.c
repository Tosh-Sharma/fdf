/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:16:26 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/26 02:40:59 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_number_of_rows(char *input)
{
	int		n;
	int		file_fd;
	char	*line;

	n = 0;
	file_fd = open(input, O_RDONLY);
	while (1)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			break ;
		else
		{
			free(line);
			n++;
		}
	}
	close(file_fd);
	if (n == 0)
		ft_perror_and_exit("There are no rows.", 0);
	return (n);
}

void	free_strings(char **input)
{
	int	i;

	i = 0;
	while (input[i] != NULL)
	{
		free(input[i]);
		i++;
	}
	free(input);
}

int	get_initial_count(int file_fd)
{
	int		column_count;
	char	*line;
	char	**numbers;
	char	**eliminate_new_line;

	line = get_next_line(file_fd);
	eliminate_new_line = ft_split(line, '\n');
	if (eliminate_new_line[0] == NULL)
	{
		free_strings(eliminate_new_line);
		ft_perror_and_exit("What a useless input", 0);
	}
	numbers = ft_split(eliminate_new_line[0], ' ');
	free_strings(eliminate_new_line);
	column_count = 0;
	while (numbers[column_count] != NULL)
		column_count++;
	free(line);
	free_strings(numbers);
	return (column_count);
}

int	get_number_of_columns(int file_fd, int row_count)
{
	int		i;
	int		n;
	int		column_count;
	char	*line;
	char	**numbers;

	column_count = get_initial_count(file_fd);
	i = 2;
	while (i < row_count)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			break ;
		numbers = ft_split(line, ' ');
		n = 0;
		while (numbers[n] != NULL)
			n++;
		if (n != column_count)
			ft_perror_and_exit("File format is bad.", 0);
		free(line);
		free_strings(numbers);
		i++;
	}
	close(file_fd);
	return (column_count);
}

void	traverse_file(char *path, t_input *input)
{
	int		file_fd;

	input->row_count = get_number_of_rows(path);
	file_fd = open(path, O_RDONLY);
	input->column_count = get_number_of_columns(file_fd, input->row_count);
	file_fd = open(path, O_RDONLY);
	convert_input(file_fd, input);
	close(file_fd);
}
