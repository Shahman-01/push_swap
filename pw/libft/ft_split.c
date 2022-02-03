/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:32:13 by ppeapod           #+#    #+#             */
/*   Updated: 2021/04/27 15:32:16 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pointer(char const *s1, char c)
{
	int	count;
	int	p;

	count = 0;
	p = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			p = 0;
		else if (p == 0)
		{
			p = 1;
			count++;
		}
		s1++;
	}
	return (count);
}

static int	ft_pointer2(char const *s2, char c, int start)
{
	int	lenght;

	lenght = 0;
	while (s2[start] != c && s2[start] != '\0')
	{
		lenght++;
		start++;
	}
	return (lenght);
}

static char	**ft_freee(char **str, int counter)
{
	while (counter > 0)
	{
		counter--;
		free((void *)str[counter]);
	}
	free(str);
	return (NULL);
}

static char	**ft_get(char const *s, char **str, char c, int len)
{
	int	i;
	int	counter;
	int	ch;

	i = 0;
	counter = 0;
	while (s[i] != '\0' && counter < len)
	{
		ch = 0;
		while (s[i] == c)
			i++;
		str[counter] = (char *)malloc(sizeof(char) * ft_pointer2(s, c, i) + 1);
		if (str[counter] == NULL)
			return (ft_freee((char **)str, counter));
		while (s[i] != '\0' && s[i] != c)
			str[counter][ch++] = s[i++];
		str[counter][ch] = '\0';
		counter++;
	}
	str[counter] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_pointer(s, c);
	str = (char **)malloc(sizeof(char *) * (len + 1));
	if (str == NULL)
		return (NULL);
	return (ft_get(s, str, c, len));
}
