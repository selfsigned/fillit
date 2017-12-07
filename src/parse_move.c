/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:31:45 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/07 21:16:32 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		line_isempty(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static	int		column_isempty(char **tab)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][0] == '#')
			return (0);
		i++;
	}
	return (TRUE);
}

static	void	ft_replace_line(char **tab)
{
	int		i;
	char	*c;

	i = 0;
	while (i < 3)
	{
		c = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = c;
		i++;
	}
}

static	void	ft_replace_column(char **tab)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			c = tab[j][i];
			tab[j][i] = tab[j][i + 1];
			tab[j][i + 1] = c;
			i++;
		}
		j++;
	}
}

void			ft_move_left(char **tab)
{
	int		i;

	i = 0;
	if (tab[0][0] == '#')
		return ;
	while (line_isempty(tab[0]) != 0 || column_isempty(tab) != 0)
	{
		if (line_isempty(tab[0]))
			ft_replace_line(tab);
		if (column_isempty(tab))
			ft_replace_column(tab);
	}
}
