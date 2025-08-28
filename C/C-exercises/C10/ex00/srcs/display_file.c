/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:41:25 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/19 23:16:13 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	ft_displayfile(char *file_name)
{
	int		fd;
	int		status;
	char	buffer[128];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	status = read(fd, buffer, sizeof(buffer));
	while (status > 0)
	{
		if (write(1, buffer, status) == -1)
		{
			close(fd);
			return (0);
		}
		status = read(fd, buffer, sizeof(buffer));
	}
	if (status == -1)
	{
		close(fd);
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}
