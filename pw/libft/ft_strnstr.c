/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:53:10 by ppeapod           #+#    #+#             */
/*   Updated: 2021/04/24 20:53:12 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *strA, const char *strB, size_t len)
{
	unsigned int	n;
	size_t			len_strB;

	if (*strB == '\0')
		return ((char *)strA);
	n = 0;
	len_strB = ft_strlen(strB);
	while (*strA != '\0')
	{
		if (n + len_strB > len)
			return (NULL);
		if (ft_strncmp(strA, strB, len_strB) == 0)
			return ((char *)strA);
		strA++;
		n++;
	}
	return (NULL);
}
