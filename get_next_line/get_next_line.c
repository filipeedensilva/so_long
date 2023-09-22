/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:27:26 by feden-pe          #+#    #+#             */
/*   Updated: 2023/06/30 17:52:24 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	content = update_content(content, fd);
	if (!content)
		return (NULL);
	line = get_one_line(content);
	content = new_content(content);
	return (line);
}

char	*update_content(char *content, int fd)
{
	char	*temp;
	int		r_status;

	r_status = 1;
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr2(content, '\n') && r_status)
	{
		r_status = read(fd, temp, BUFFER_SIZE);
		if (r_status == -1)
		{
			free(temp);
			free(content);
			return (NULL);
		}
		temp[r_status] = '\0';
		content = ft_strjoin2(content, temp);
	}
	free(temp);
	return (content);
}

char	*get_one_line(char *content)
{
	char	*line;
	int		i;

	i = 0;
	if (!ft_strlen2(content))
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = content[i];
	return (line);
}

char	*new_content(char *content)
{
	char	*new_content;
	int		i;
	int		j;

	i = 0;
	if (!content)
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	if (!content[i])
	{
		free (content);
		return (NULL);
	}
	new_content = (char *)malloc(sizeof(char) * (ft_strlen2(content) - i) + 1);
	if (!new_content)
		return (NULL);
	j = 0;
	while (content[i])
		new_content[j++] = content[i++];
	new_content[j] = '\0';
	free(content);
	return (new_content);
}
