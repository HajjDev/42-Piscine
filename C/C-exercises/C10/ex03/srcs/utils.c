/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:19:56 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 10:48:27 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putstr_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_zeros(int j)
{
	while (j > 0)
	{
		write(1, "0", 1);
		j--;
	}
}

int	ft_error(char *file_name, char *prog_name)
{
	ft_putstr_err(prog_name);
	ft_putstr_err(": ");
	ft_putstr_err(file_name);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
	return (1);
}

void	ft_put_prog_err(char *prog_name, char *message)
{
	ft_putstr_err(prog_name);
	ft_putstr_err(": ");
	ft_putstr_err(message);
	ft_putstr_err("\n");
}
