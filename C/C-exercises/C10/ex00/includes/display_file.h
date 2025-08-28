/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:29:34 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/19 22:19:30 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

# include <unistd.h>
# include <fcntl.h>

int		ft_displayfile(char *file_name);
void	ft_putstr_err(char *str);
int		ft_error(int argc);

#endif