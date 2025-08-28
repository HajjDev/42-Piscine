/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:54:04 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 22:59:58 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static int	read_from_stdin(char *buffer, int *count, int bytes)
{
	int	status;

	*count = 0;
	while (1)
	{
		status = read(0, &buffer[*count % bytes], 1);
		if (status <= 0)
			break ;
		(*count)++;
	}
	return (status);
}

int	ft_handleinput(int multi, int file_count, char *prog, int bytes)
{
	char	*buffer;
	int		count;
	int		status;

	if (bytes == 0)
		return (0);
	buffer = malloc(bytes);
	if (!buffer)
		return (ft_malloc_error(0, prog));
	if (multi)
		print_header(file_count, "standard input");
	status = read_from_stdin(buffer, &count, bytes);
	if (status == -1)
	{
		ft_error(errno, prog, "standard input");
		free(buffer);
		return (1);
	}
	print_tailed_buffer(buffer, count, bytes);
	free(buffer);
	return (0);
}
