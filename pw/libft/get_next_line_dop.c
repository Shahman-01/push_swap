/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_dop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:49:12 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:49:16 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_gnl(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (len == 0)
		return (d);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	have_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	st_len;
	char	*rtn;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen_gnl((char *)s1);
	s2_len = ft_strlen_gnl((char *)s2);
	st_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * st_len);
	if (!rtn)
		return (0);
	ft_memmove_gnl(rtn, s1, s1_len);
	ft_memmove_gnl(rtn + s1_len, s2, s2_len);
	rtn[st_len - 1] = '\0';
	free((char *)s1);
	return (rtn);
}
