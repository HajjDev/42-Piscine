/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:50:11 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:42:21 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	ft_displayinput(int fd, char **argv)
{
	int		status;
	char	buffer[BUFF_SIZE];

	status = read(fd, buffer, sizeof(buffer));
	while (status > 0)
	{
		if (write(1, buffer, status) == -1)
			return (ft_showerror(argv[0], "-"));
		status = read(fd, buffer, sizeof(buffer));
	}
	if (status == -1)
		return (ft_showerror(argv[0], "-"));
	return (0);
}
