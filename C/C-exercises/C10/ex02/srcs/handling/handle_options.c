/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:49:41 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/23 11:28:15 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_handleoptions(int argc, char **files, int bytes)
{
	int	headers;
	int	i;
	int	err;
	int	file_count;

	i = 3;
	headers = 0;
	file_count = 3;
	err = 0;
	if (argc == 3)
		return (ft_handleinput(headers, file_count, files[0], bytes));
	if (argc > 4)
		headers = 1;
	while (files[i])
	{
		if (files[i][0] == '-' && files[i][1] == '\0')
			ft_handleinput(headers, file_count, files[0], bytes);
		else
			if (ft_displayfile(headers, file_count, files, bytes))
				err = 1;
		i++;
		file_count++;
	}
	return (err);
}
