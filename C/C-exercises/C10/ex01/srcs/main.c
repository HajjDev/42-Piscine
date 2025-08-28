/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:39:47 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/20 21:09:07 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_displayinput(0, argv));
	return (ft_handleoptions(argv));
}
