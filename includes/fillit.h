/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:54:29 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/07 21:59:36 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define ERROR 0
# define SUCCESS 1
# define TRUE 1
# define FALSE 0

typedef struct	s_tetra
{
	char	**content;
	int		index;
}				t_tetra;

typedef struct	s_map
{
	char	**grid;
	int		width;
	int		is_solved;
}				t_map;

/*
** helpers.c
*/
# define ERROR_MSG "error\n"

void			ft_error(void);
void			free_mem(t_tetra *tab, char **input);

/*
** read.c:
** READ_SIZE 21 because there's 21 characters to read per tet inc newlines
*/
# define READ_SIZE 21

char			**ft_read(int fd);
t_tetra			*ft_parse(char **input);

/*
**parse_move.c
*/
void			ft_move_left(char **tab);

/*
** solve.c
*/
t_map			ft_algo(t_tetra *tet_in, t_map map, int mapwidth);
int				ft_solve(t_tetra *tet_in, t_map map);

/*
** print.c
*/
void			ft_display(char **map, int maplen);

/*
** main.c:
*/

#endif
