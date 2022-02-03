/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:01:56 by ppeapod           #+#    #+#             */
/*   Updated: 2021/04/24 22:01:58 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*str;
	int				i;

	i = 0;
	cc = (unsigned char)c;
	str = (unsigned char *)arr;
	while (n--)
	{
		if (str[i] == cc)
			return (str + i);
		i++;
	}
	return (NULL);
}
