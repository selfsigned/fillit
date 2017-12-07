/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:31:45 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/07 15:30:28 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_line(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_column(char **tab)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][0] == '#')
			return (0);
		i++;
	}
	return (1);
}

void	ft_replace_line(char **tab)
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

void	ft_replace_column(char **tab)
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

void	ft_move_left(char **tab)
{
	int		i;

	i = 0;
	if (tab[0][0] == '#')
		return ;
	while (ft_check_line(tab[0]) != 0 || ft_check_column(tab) != 0)
	{
		if (ft_check_line(tab[0]) == 1)
			ft_replace_line(tab);
		if (ft_check_column(tab) == 1)
			ft_replace_column(tab);
	}
}

void	ft_tetra_letter(char **tab, int tet_nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab[j][i] == '#')
				tab[j][i] += 30 + tet_nbr;
			i++;
		}
		j++;
	}
}
