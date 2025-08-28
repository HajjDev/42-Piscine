/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:52:03 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 10:53:47 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static void	init_state(t_state *state, int is_c_option)
{
	state->is_first_line = 1;
	state->star_printed = 0;
	state->offset = 0;
	state->is_c_option = is_c_option;
	state->any_file_ok = 0;
}

static void	process_files(int ac, char **av, int i, t_state *state)
{
	int	fd;

	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			ft_error(av[i], basename(av[0]));
		else
		{
			state->any_file_ok = 1;
			if (ft_hexdump(fd, state) != 0)
				ft_error(av[i], basename(av[0]));
			close(fd);
		}
		i++;
	}
}

int	ft_handle(int ac, char **av, int start_index, int is_c)
{
	t_state	state;
	int		width;

	init_state(&state, is_c);
	if (ac == start_index)
	{
		ft_hexdump(0, &state);
		state.any_file_ok = 1;
	}
	else
		process_files(ac, av, start_index, &state);
	if (state.offset > 0)
	{
		width = 7;
		if (state.is_c_option)
			width = 8;
		ft_printaddress(state.offset, "0123456789abcdef", width);
		write(1, "\n", 1);
	}
	if (ac > start_index && !state.any_file_ok)
		ft_put_prog_err(basename(av[0]), "all input file arguments failed");
	return (0);
}
