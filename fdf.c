/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:14:48 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/21 16:16:40 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// The way to solve is as follows.
// 1. Read file, ensure file is correctly parsed and not stupid.
// 2. Take all the numbers as pixels into the code
// 3. Assign co-ordinates to them all according to their positioning.
// 4. Now for the real part, first, print pixels in 2D correctly.
// 5. Then turn everything by 45 degrees and print it.
// 6. Now account for the 3rd dimension and print the pixels
//		accordingly in the 3rd dimension.
// 7. Then draw lines for everything.
// 8. Now do Bonuses: colors, rotation, translation, zoom in
//		and zoom out and so on.
int	main(int argc, char **argv)
{
	t_input	input;

	if (argc != 2)
	{
		perror("You can only pass one argument. \
			Don't waste time testing stupid stuff.");
		exit(0);
	}
	else
	{
		traverse_file(argv[1], &input);
		draw_stuff(argv[1], &input);
	}
	return (0);
}
