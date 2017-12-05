/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:54:29 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/05 15:03:51 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_tetra
{
	t_point	pos[4];
	int		index;
	int		is_used;
}				t_tetra;

typedef struct	s_map
{
	char	*grid;
	int		width;
}				t_map;

/*
** helpers.c
*/
# define ERROR_MSG "error\n"

void			ft_error(void);

/*
** read.c:
** READ_SIZE 21 because there's 21 characters to read per tet inc newlines
*/
# define READ_SIZE 21

char			**ft_read(int fd);
t_tetra			*ft_parse(char **input);

/*
** solve.c
*/

/*
** print.c
*/
void			ft_display(t_tetra *tab, t_map map);

/*
** main.c:
*/

#endif
