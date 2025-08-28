/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:00:17 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:50:15 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_invalid_bytes(char *prog, char *value)
{
	ft_putstr_err(prog);
	ft_putstr_err(": invalid number of bytes: '");
	ft_putstr_err(value);
	ft_putstr_err("'\n");
	return (1);
}

int	ft_error_reading(char *prog, char *file_name)
{
	ft_putstr_err(prog);
	ft_putstr_err(": error reading '");
	ft_putstr_err(file_name);
	ft_putstr_err("': ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
	return (1);
}

int	ft_error_opening(char *prog, char *file_name)
{
	ft_putstr_err(prog);
	ft_putstr_err(": cannot open '");
	ft_putstr_err(file_name);
	ft_putstr_err("' for reading: ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
	return (1);
}

int	ft_malloc_error(int fd, char *prog)
{
	ft_putstr_err(prog);
	ft_putstr_err(": Out of memory\n");
	if (fd != 0)
		close(fd);
	return (1);
}
