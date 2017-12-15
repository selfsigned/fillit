/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:22:38 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/17 19:51:41 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	needle_len;

	if (!(*needle))
		return ((char*)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && needle_len <= len--)
	{
		if (*haystack == *needle
				&& !(ft_memcmp(haystack, needle, needle_len)))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
