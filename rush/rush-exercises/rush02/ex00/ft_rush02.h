/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:32:00 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 16:26:31 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

typedef char*	t_big_int;

typedef struct s_dict
{
	t_big_int	number;
	char		*number_name;
}	t_dict;

typedef struct s_fill_vars
{
	char	line[1024];
	long	i;
	int		dict_idx;
	t_dict	*dict;
}	t_fill_vars;

int			ft_error(char *msg);
int			count_valid_lines(char *file);
t_dict		*parse_dictionary(char *file, int size);
int			is_valid_line(char *line);
t_dict		extract_entry(char *line);
void		get_key_indices(char *line, int *start, int *end);
void		get_val_indices(char *line, int *start, int *end);
int			key_exists(t_big_int num, t_dict *dict, int count);
void		sort_dict(t_dict *dict, int size);
void		free_dict(t_dict *dict);
t_dict		*find_entry(t_big_int n, t_dict *dict);
t_dict		*find_largest_smaller(t_big_int n, t_dict *dict);
int			get_dict_len(t_dict *dict);
void		convert_number(t_big_int n, t_dict *dict, int *first);
int			handle_direct_cases(t_big_int num, t_dict *dict, int *first);
void		process_division(t_big_int num, t_dict *e, t_dict *dict,
				int *first);
void		process_subtraction(t_big_int num, t_dict *e, t_dict *dict, int *f);
int			handle_input(char *dict_path);
void		process_line(char *line, t_dict *dict);
t_dict		*init_dictionary(char *filename);
int			is_valid_number(char *str);
void		ft_putstr(char *str);
int			ft_is_space(char c);
int			is_printable(char c);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(const char *s);
int			bigint_cmp(t_big_int s1, t_big_int s2);
t_big_int	bigint_sub(t_big_int n1, t_big_int n2);
void		bigint_div_mod(t_big_int n1, t_big_int n2, t_big_int *q,
				t_big_int *r);
t_big_int	trim_leading_zeros(t_big_int str);
void		perform_long_division(t_big_int n1, t_big_int n2, t_big_int *q,
				t_big_int *r);

#endif
