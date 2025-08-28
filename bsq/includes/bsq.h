/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:40:26 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 16:58:56 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUF_SIZE 8192
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_max_square
{
	int	size;
	int	i;
	int	j;
}	t_max_square;

typedef struct s_coords
{
	int	y;
	int	x;
}	t_coords;

void	ft_assign(int **m, int i, int j, t_max_square *max_element);
int		n(int a, int b, int c);
void	ft_solve(int **m, t_max_square *max_element, int row, int col);
void	ft_size(char **map, int *col, int *row);
int		**transform(char **map, char sep);
void	ft_modify(char **map, t_max_square *max_element, char fill);
void	ft_print(char **map);
int		ft_strlen(char *str);
char	**map_error(void);
char	*resize_buffer(char *old, long size, long new_cap);
int		ft_atoi(char *str);
int		follow_pattern(char **lines);
int		same_length(char **lines);
char	**init_map(char **lines, char *legend);
char	**parse_file(char *file_name, char **file_content_ptr);
int		init_max(t_max_square **max_element);
void	find_largest_cube(char *file_name);
void	ft_free_array(int **array);
void	free_max_element(t_max_square **max_element);
void	assign_legend(char *line_0, char *legend);
void	ft_initialize_read(long *size, long *capacity, char **content);
int		correct_chars(char *str, char **lines);

#endif