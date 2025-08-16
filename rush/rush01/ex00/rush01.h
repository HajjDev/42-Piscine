/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-moo <thde-moo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:06:36 by thde-moo          #+#    #+#             */
/*   Updated: 2025/08/16 13:29:04 by thde-moo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>

/*utils*/
void	ft_putchar(char ch);
void	ft_putstr(char *str);
int		is_space(char ch);
int		error(void);
/*parsing && print*/
int		set_clue(int clues[4][4], int clue_idx, char ch);
int		parse_input(char *input, int clues[4][4]);
void	print_grid(int grid[4][4]);
/*is_ok*/
int		row_unique_ok(int grid[4][4], int row);
int		col_unique_ok(int grid[4][4], int col);
int		row_vis_ok(int grid[4][4], int row, int left, int right);
int		col_vis_ok(int grid[4][4], int col, int top, int bot);
/*calculator*/
int		vis_row_left(int grid[4][4], int row);
int		vis_row_right(int grid[4][4], int row);
int		vis_col_top(int grid[4][4], int col);
int		vis_col_bottom(int grid[4][4], int col);
/*backtracking*/
int		line_col_check(int grid[4][4], int clues[4][4], int row, int col);
int		try_place(int grid[4][4], int clues[4][4], int pos);

#endif
