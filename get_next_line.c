/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbikandi <nbikandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:18:28 by nbikandi          #+#    #+#             */
/*   Updated: 2022/07/19 15:34:15 by nbikandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buf1, char *buf2)
{
	char	*aux;

	aux = ft_strjoin(buf1, buf2);
	free(buf1);
	return (aux);
}

char	*ft_lines(char *buf1)
{
	char	*lines;
	int		j;

	j = 0;
	if (!buf1[j])
		return (NULL);
	while (buf1[j] && buf1[j] != '\n')
		j++;
	lines = (char *)ft_calloc(j + 2, sizeof(char));
	j = 0;
	while (buf1[j] && buf1[j] != '\n')
	{
		lines[j] = buf1[j];
		j++;
	}
	if (buf1[j] && buf1[j] == '\n')
	{
		lines[j++] = '\n';
	}
	return (lines);
}

char	*ft_read(int fd, char *save)
{
	char	*buf1;
	int		i;

	if (!save)
		save = (char *)ft_calloc(1, 1);
	buf1 = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf1, BUFFER_SIZE);
		if (i == (-1))
		{
			free(buf1);
			return (NULL);
		}
		buf1[i] = 0;
		save = ft_free(save, buf1);
		if (ft_strchr(buf1, '\n'))
			break ;
	}
	free(buf1);
	return (save);
}

char	*ft_save(char *buf1)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf1[i] && buf1[i] != '\n')
		i++;
	if (!buf1[i])
	{
		free(buf1);
		return (NULL);
	}
	line = (char *)ft_calloc((ft_strlen(buf1) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf1[i])
		line[j++] = buf1[i++];
	free(buf1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_lines(str);
	str = ft_save(str);
	return (line);
}
