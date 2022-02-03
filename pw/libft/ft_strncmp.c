/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srencmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:20:03 by ppeapod           #+#    #+#             */
/*   Updated: 2021/04/20 15:20:13 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (((a[i] != '\0') || (b[i] != '\0')) && (n != 0))
	{
		if (a[i] == b[i])
		{
			i++;
			n--;
		}
		else if (a[i] > b[i])
		{
			return (a[i] - b[i]);
		}
		else if (b[i] > a[i])
		{
			return (a[i] - b[i]);
		}
	}
	return (0);
}
