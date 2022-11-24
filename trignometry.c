/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trignometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:12:41 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/24 22:28:07 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_angles(t_params params, t_trig *z)
{
	z->cos_a = cos(params.alpha);
	z->cos_b = cos(params.beta);
	z->cos_g = cos(params.gamma);
	z->sin_a = sin(params.alpha);
	z->sin_b = sin(params.beta);
	z->sin_g = sin(params.gamma);
}
