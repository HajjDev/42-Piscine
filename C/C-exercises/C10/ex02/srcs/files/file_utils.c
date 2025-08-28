/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:14:14 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/23 11:48:31 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_finishprint(char *buffer, int start, int bytes, int fd)
{
	write(1, &buffer[start], bytes - start);
	if (start > 0)
		write(1, buffer, start);
	free(buffer);
	if (fd != 0)
		close(fd);
	return (0);
}

int	ft_error(int err, char *prog, char *file_name)
{
	if (err == EISDIR)
		return (ft_error_reading(prog, file_name));
	else
		return (ft_error_opening(prog, file_name));
}
