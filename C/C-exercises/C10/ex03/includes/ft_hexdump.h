/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:51:44 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 10:51:50 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>
# include <stdlib.h>

typedef struct s_state
{
	char	prev_buffer[16];
	int		is_first_line;
	int		star_printed;
	int		offset;
	int		is_c_option;
	int		any_file_ok;
}	t_state;

int		ft_error(char *file_name, char *prog_name);
void	ft_zeros(int j);
void	ft_put_prog_err(char *prog_name, char *message);
int		ft_strcmp_buffer(char *b1, char *b2, int n);
void	ft_printaddress(int nbr, char *base, int width);
void	ft_printhex(int status, char *buffer, char *base);
void	ft_printhex_default(int status, char *buffer, char *base);
void	ft_printchar(int status, char *buffer);
void	ft_display_line(int status, char *buffer, t_state *state);
int		ft_hexdump(int fd, t_state *state);
int		ft_handle(int ac, char **av, int start_index, int is_c);

#endif