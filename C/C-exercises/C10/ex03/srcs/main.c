/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:21:18 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/26 09:31:26 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	main(int argc, char **argv)
{
	int	start_index;
	int	is_c_option;

	if (argc > 1 && argv[1][0] == '-'
		&& argv[1][1] == 'C' && argv[1][2] == '\0')
	{
		is_c_option = 1;
		start_index = 2;
	}
	else
	{
		is_c_option = 0;
		start_index = 1;
	}
	return (ft_handle(argc, argv, start_index, is_c_option));
}
