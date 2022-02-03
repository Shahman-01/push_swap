/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:42:07 by ppeapod           #+#    #+#             */
/*   Updated: 2021/04/24 19:42:09 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strA, const char *strB)
{
	int		i;
	int		k;
	char	*str1;
	char	*str2;
	char	*res;

	k = ft_strlen(strB);
	i = 0;
	str1 = (char *)strA;
	str2 = (char *)strB;
	while (*str1)
	{
		if (*str1 == *str2)
		{
			res = str1 - 1;
			i++;
			str1++;
			str2++;
		}
		else
			str1++;
	}
	if (i == k)
		return (res);
	return (NULL);
}
