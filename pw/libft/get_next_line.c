/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:48:53 by ppeapod           #+#    #+#             */
/*   Updated: 2021/10/16 14:49:01 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*posle_n(char *ost)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ost)
		return (0);
	while (ost[i] && ost[i] != '\n')
		i++;
	if (!ost[i])
	{
		free(ost);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen_gnl(ost) - i) + 1));
	if (!(rtn))
		return (0);
	i++;
	while (ost[i])
		rtn[j++] = ost[i++];
	rtn[j] = '\0';
	free(ost);
	return (rtn);
}

static char	*do_n(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!(rtn))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	prov_rd(int rd, char *buff)
{
	if (rd == -1)
	{
		free(buff);
		return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*ost;
	int				rd;

	rd = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buff))
		return (-1);
	while (!have_n(ost) && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (prov_rd(rd, buff) == -1)
			return (-1);
		buff[rd] = '\0';
		ost = ft_join(ost, buff);
	}
	free(buff);
	*line = do_n(ost);
	ost = posle_n(ost);
	if (rd == 0)
		return (0);
	return (1);
}
