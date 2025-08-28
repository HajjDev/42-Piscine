/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:46:32 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/23 10:35:14 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	ft_handleoptions(char **files)
{
	int		i;
	int		status;
	int		err;

	i = 1;
	err = 0;
	while (files[i])
	{
		if (files[i][0] == '-' && files[i][1] == '\0')
		{
			if (ft_displayinput(0, files))
				err = 1;
		}
		else
		{
			status = ft_displayfile(files[i]);
			if (!status)
			{
				err = 1;
				ft_showerror(files[0], files[i]);
			}
		}
		i++;
	}
	return (err);
}
