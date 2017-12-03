/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:54:29 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/03 22:51:33 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

/*
** main.c:
*/
# define ERROR_MSG "error\n"
void	ft_error(void);

/*
** read.c:
** READ_SIZE 21 because there's 21 charcaters to read per tet inc newlines
*/
# define READ_SIZE 21
char	**ft_read(int fd);

#endif
