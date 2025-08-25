/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:32:10 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:32:12 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static void	assign_args(int argc, char **argv, char **dict_p, char **num_s)
{
	if (argc == 2)
	{
		*dict_p = "numbers.dict";
		*num_s = argv[1];
	}
	else
	{
		*dict_p = argv[1];
		*num_s = argv[2];
	}
}

static int	setup_and_run(char *dict_path, char *number_str)
{
	t_dict	*dict;
	char	*num_to_convert;
	int		dict_size;
	int		first;

	if (!is_valid_number(number_str))
		return (ft_error("Error\n"));
	dict_size = count_valid_lines(dict_path);
	if (dict_size <= 0)
		return (ft_error("Dict Error\n"));
	dict = parse_dictionary(dict_path, dict_size);
	if (!dict)
		return (1);
	sort_dict(dict, get_dict_len(dict));
	first = 1;
	num_to_convert = ft_strdup(number_str);
	if (!num_to_convert)
	{
		free_dict(dict);
		return (ft_error("Dict Error\n"));
	}
	convert_number(num_to_convert, dict, &first);
	ft_putstr("\n");
	free_dict(dict);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number_str;

	if (argc < 2 || argc > 3)
		return (ft_error("Error\n"));
	assign_args(argc, argv, &dict_path, &number_str);
	if (argc == 2 && ft_strcmp(number_str, "-") == 0)
		return (handle_input(dict_path));
	return (setup_and_run(dict_path, number_str));
}
