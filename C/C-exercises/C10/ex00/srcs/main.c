/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:33:06 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/20 20:54:53 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
		return (ft_error(argc));
	if (!ft_displayfile(argv[1]))
		ft_putstr_err("Cannot read file.\n");
	return (0);
}
