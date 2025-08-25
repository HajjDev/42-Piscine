/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:55 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:56 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_error(char *msg)
{
	ft_putstr(msg);
	return (1);
}
