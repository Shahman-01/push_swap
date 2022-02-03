/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:13:23 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/15 19:13:31 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if ((*s1 == '\0') && (*s2 == '\0'))
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i])
	{
		i++;
		if (!s1[i] && !s2[i])
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
