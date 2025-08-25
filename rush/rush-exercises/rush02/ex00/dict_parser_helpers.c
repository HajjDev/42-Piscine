/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:34 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:36 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	get_key_indices(char *line, int *start, int *end)
{
	int	i;

	i = 0;
	while (ft_is_space(line[i]))
		i++;
	*start = i;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	*end = i;
}

void	get_val_indices(char *line, int *start, int *end)
{
	int	i;

	i = 0;
	while (line[i] != ':' && line[i] != '\0')
		i++;
	if (line[i] == ':')
		i++;
	while (ft_is_space(line[i]))
		i++;
	*start = i;
	while (is_printable(line[i]))
		i++;
	*end = i;
	while (*end > *start && ft_is_space(line[*end - 1]))
		(*end)--;
}
