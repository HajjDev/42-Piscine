/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:02 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/23 13:08:43 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int	bytes;

	if (argc == 1)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
	{
		if (argv[2])
		{
			bytes = ft_atoi(argv[2]);
			if (bytes < 0)
				return (ft_invalid_bytes(argv[0], argv[2]));
			return (ft_handleoptions(argc, argv, bytes));
		}
	}
	return (0);
}
