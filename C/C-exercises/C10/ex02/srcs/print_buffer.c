/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:48:05 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 22:50:10 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_tailed_buffer(char *buffer, int total_read, int bytes)
{
	int	start;

	if (total_read < bytes)
	{
		write(1, buffer, total_read);
	}
	else
	{
		start = total_read % bytes;
		write(1, &buffer[start], bytes - start);
		write(1, buffer, start);
	}
}
