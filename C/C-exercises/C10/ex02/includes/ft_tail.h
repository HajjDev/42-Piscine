/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:50:45 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 22:50:46 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>
# include <stdlib.h>

typedef struct s_tail_file
{
	char	*prog;
	char	*file_name;
}	t_tail_file;

int		ft_displayfile(int multi, int file_count, char **files, int bytes);
int		ft_handleinput(int header, int file_count, char *prog, int bytes);
int		ft_handleoptions(int argc, char **files, int bytes);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
int		ft_error(int err, char *prog, char *file_name);
int		ft_tail_read_loop(int fd, char *buffer, int bytes, t_tail_file file);
int		ft_invalid_bytes(char *prog, char *value);
int		ft_error_reading(char *prog, char *file_name);
int		ft_error_opening(char *prog, char *file_name);
void	print_header(int index, char *file_name);
int		ft_malloc_error(int fd, char *prog);
void	print_tailed_buffer(char *buffer, int total_read, int bytes);

#endif