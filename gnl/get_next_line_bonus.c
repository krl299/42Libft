/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:48:43 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/06/08 13:46:12 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Return the line that was read.
char	*get_next_line(int fd)
{
	static char	*mem[256] = {0};
	char		*line;

	if ((fd < 0) || (fd > 255))
		return (0);
	if (ft_fill_mem(&mem[fd], fd) == -1)
	{
		free (mem[fd]);
		mem[fd] = 0;
		return (0);
	}
	line = ft_get_line(&mem[fd]);
	if (!line)
	{
		free (mem[fd]);
		mem[fd] = 0;
	}
	return (line);
}

// Fill memory of next line.
int	ft_fill_mem(char **mem, int fd)
{
	int		ret;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	ft_clean_mem(mem);
	ret = 1;
	while (ret && !ft_strchr(*mem, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
			return (ret);
		buffer[ret] = 0;
		tmp = *mem;
		*mem = ft_strjoin(*mem, buffer);
		free(tmp);
	}
	return (ret);
}

// Clean mem for the next call to this function
void	ft_clean_mem(char **mem)
{
	char	*new_mem;
	size_t	len;
	size_t	new_len;

	if (!(*mem))
	{
		*mem = malloc(sizeof(char));
		**mem = 0;
		return ;
	}
	len = ft_len_line(*mem);
	new_len = ft_strlen(&(*mem)[len]) + 1;
	new_mem = (char *)malloc(sizeof(char) * new_len);
	ft_memcpy(new_mem, &(*mem)[len], new_len);
	free(*mem);
	*mem = new_mem;
}

// Get the line to return
char	*ft_get_line(char **mem)
{
	size_t	eol;
	char	*line;
	size_t	i;

	eol = ft_len_line(*mem);
	if (!eol)
		return (0);
	line = malloc(sizeof(char) * (eol + 1));
	i = 0;
	while (i < eol)
	{
		line[i] = (*mem)[i];
		i++;
	}
	line[i] = 0;
	return (line);
}
