/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:25:06 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 22:18:21 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	init_max(t_max_square **max_element)
{
	*max_element = malloc(sizeof(t_max_square));
	if (*max_element == NULL)
		return (0);
	(*max_element)->size = 0;
	(*max_element)->i = 0;
	(*max_element)->j = 0;
	return (1);
}

void	free_max_element(t_max_square **max_element)
{
	free(*max_element);
}
