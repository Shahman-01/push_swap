/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:15:13 by ppeapod           #+#    #+#             */
/*   Updated: 2021/04/27 15:15:15 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (!(ft_strchr(set, *s1)))
			break ;
		s1++;
	}
	res = (char *)s1 + (ft_strlen(s1) - 1);
	while (res >= s1)
	{
		if (!(ft_strchr(set, *res)))
			break ;
		res--;
	}
	return (ft_substr((char *)s1, 0, ++res - s1));
}
