/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:04:16 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/03/19 15:40:41 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_stash(int fd, char *stash, char *buf)
{
	ssize_t	res;
	char	*temp;

	res = 1;
	while (res > 0)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res < 0)
			return (NULL);
		if (res == 0)
			break ;
		buf[res] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*process_stash(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line + i + 1));
	if (!temp)
		return (NULL);
	line[i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	char		*buf;

	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = fill_stash(fd, stash, buf);
	free(buf);
	if (!line)
		return (NULL);
	stash = process_stash(line);
	return (line);
}
