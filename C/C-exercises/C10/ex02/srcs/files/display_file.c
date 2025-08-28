/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:48:22 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 22:57:43 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static int	init_vars(int *fd, char **buffer, char *filename, int bytes)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (1);
	*buffer = malloc(bytes);
	if (!*buffer)
	{
		close(*fd);
		return (1);
	}
	return (0);
}

int	ft_tail_read_loop(int fd, char *buffer, int bytes, t_tail_file file)
{
	int	count;
	int	status;

	(void)file;
	count = 0;
	while (1)
	{
		status = read(fd, &buffer[count % bytes], 1);
		if (status <= 0)
			break ;
		count++;
	}
	if (status == -1)
	{
		ft_error(errno, file.prog, file.file_name);
		return (-1);
	}
	return (count);
}

int	ft_displayfile(int multi, int file_count, char **files, int bytes)
{
	t_tail_file	file;
	int			fd;
	char		*buffer;
	int			total_read;

	if (bytes == 0)
		return (0);
	if (init_vars(&fd, &buffer, files[file_count], bytes))
		return (ft_error_opening(files[0], files[file_count]));
	if (multi)
		print_header(file_count, files[file_count]);
	file.prog = files[0];
	file.file_name = files[file_count];
	total_read = ft_tail_read_loop(fd, buffer, bytes, file);
	close(fd);
	if (total_read >= 0)
		print_tailed_buffer(buffer, total_read, bytes);
	free(buffer);
	if (total_read < 0)
		return (1);
	return (0);
}
