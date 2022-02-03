/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:04:30 by ppeapod           #+#    #+#             */
/*   Updated: 2021/04/27 19:04:35 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_getstr(int *len, int *tmp, int *n, char *str)
{
	int	i;

	if (*n < 0)
	{
		str[0] = '-';
		*n = -(*n);
		i = 1;
	}
	else
		i = 0;
	while (*len)
	{
		*tmp = *n / *len;
		str[i] = '0' + *tmp;
		*n %= *len;
		*len /= 10;
		i++;
	}
	return (str[i] = '\0');
}		

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;
	int		j;

	j = 1;
	tmp = n / 10;
	len = 1;
	if (n < 0)
		j = 2;
	while (tmp)
	{
		j++;
		len *= 10;
		tmp /= 10;
	}
	if ((long)n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * j + 1 );
	if (!str)
		return (NULL);
	ft_getstr(&len, &tmp, &n, str);
	return (str);
}
