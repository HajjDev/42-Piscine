/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:32:13 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/26 09:45:06 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_strcmp_buffer(char *b1, char *b2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (b1[i] != b2[i])
			return (1);
		i++;
	}
	return (0);
}

static void	print_line_content(int status, char *buffer, t_state *state)
{
	int	width;

	state->star_printed = 0;
	width = 7;
	if (state->is_c_option)
		width = 8;
	ft_printaddress(state->offset, "0123456789abcdef", width);
	if (state->is_c_option)
	{
		ft_printhex(status, buffer, "0123456789abcdef");
		ft_printchar(status, buffer);
	}
	else
		ft_printhex_default(status, buffer, "0123456789abcdef");
	write(1, "\n", 1);
}

void	ft_display_line(int status, char *buffer, t_state *state)
{
	int	i;

	if (!state->is_first_line
		&& ft_strcmp_buffer(buffer, state->prev_buffer, status) == 0)
	{
		if (!state->star_printed)
		{
			write(1, "*\n", 2);
			state->star_printed = 1;
		}
	}
	else
		print_line_content(status, buffer, state);
	i = 0;
	while (i < status)
	{
		state->prev_buffer[i] = buffer[i];
		i++;
	}
	state->is_first_line = 0;
}

int	ft_hexdump(int fd, t_state *state)
{
	char	buffer[16];
	int		bytes_in_buffer;
	int		read_status;

	bytes_in_buffer = 0;
	while (1)
	{
		read_status = read(fd, buffer + bytes_in_buffer, 16 - bytes_in_buffer);
		if (read_status > 0)
			bytes_in_buffer += read_status;
		if (bytes_in_buffer == 16 || (read_status <= 0 && bytes_in_buffer > 0))
		{
			ft_display_line(bytes_in_buffer, buffer, state);
			state->offset += bytes_in_buffer;
			bytes_in_buffer = 0;
		}
		if (read_status <= 0)
		{
			if (read_status == -1)
				return (1);
			return (0);
		}
	}
}
