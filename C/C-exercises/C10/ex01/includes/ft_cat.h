/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:21:34 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/23 10:34:11 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# define BUFF_SIZE 29696

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

int		ft_displayfile(char *file_name);
int		ft_displayinput(int fd, char **argv);
int		ft_handleoptions(char **files);
void	ft_putstr_err(char *str);
int		ft_showerror(char *prog, char *filename);

#endif