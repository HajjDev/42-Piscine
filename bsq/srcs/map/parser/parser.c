/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:48:31 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 17:48:33 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	*read_entire_file(int fd, long *final_size)
{
	char	*content;
	long	size;
	long	capacity;
	int		bytes_read;

	ft_initialize_read(&size, &capacity, &content);
	if (!content)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, content + size, capacity - size);
		if (bytes_read <= 0)
			break ;
		size += bytes_read;
		if (size >= capacity)
		{
			content = resize_buffer(content, size, capacity * 2);
			if (!content)
				return (NULL);
			capacity *= 2;
		}
	}
	content[size] = '\0';
	*final_size = size;
	return (content);
}

static void	populate_lines(char **lines, char *buffer, long size)
{
	int		line_index;
	long	i;

	line_index = 0;
	if (size > 0)
	{
		lines[line_index] = buffer;
		line_index++;
	}
	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			if (i + 1 < size)
			{
				lines[line_index] = &buffer[i + 1];
				line_index++;
			}
		}
		i++;
	}
	lines[line_index] = NULL;
}

static int	count_total_lines(char *buffer, long size)
{
	int		line_count;
	long	i;

	if (size == 0)
		return (0);
	line_count = 0;
	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			line_count++;
		i++;
	}
	if (buffer[size - 1] != '\n')
		return (-1);
	return (line_count);
}

static char	**parse_buffer_in_place(char *buffer, long size)
{
	int		line_count;
	char	**lines;

	if (size == 0)
	{
		lines = malloc(sizeof(char *));
		if (lines)
			lines[0] = NULL;
		return (lines);
	}
	line_count = count_total_lines(buffer, size);
	if (line_count == -1)
		return (NULL);
	lines = malloc(sizeof(char *) * (line_count + 1));
	if (!lines)
		return (NULL);
	populate_lines(lines, buffer, size);
	return (lines);
}

char	**parse_file(char *file_name, char **file_content_ptr)
{
	int		fd;
	char	**lines;
	long	file_size;

	if (!file_name)
		fd = 0;
	else
		fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (map_error());
	*file_content_ptr = read_entire_file(fd, &file_size);
	close(fd);
	if (!(*file_content_ptr))
		return (NULL);
	lines = parse_buffer_in_place(*file_content_ptr, file_size);
	if (!lines || !follow_pattern(lines) || !same_length(lines))
	{
		map_error();
		if (lines)
			free(lines);
		free(*file_content_ptr);
		return (NULL);
	}
	return (lines);
}
