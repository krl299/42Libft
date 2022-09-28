/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:41:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 13:23:23 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_addstrtoarray(char *memory, unsigned int len, int words)
{
	char			**array;
	unsigned int	i;
	unsigned int	w;

	array = (char **) malloc(sizeof(char *) * (words + 1));
	if (array == 0)
		return (0);
	i = 0;
	w = 0;
	if (memory[i] != '\0')
		array[w++] = ft_strdup(&memory[i]);
	i++;
	while (i < len)
	{
		if (memory[i] != '\0' && memory[i - 1] == '\0')
			array[w++] = ft_strdup(&memory[i]);
		i++;
	}
	array[w] = 0;
	return (array);
}

// Allocates (with malloc(3)) and returns an array of strings
// obtained by splitting ’s’ using the character ’c’
// as a delimiter. The array must end with a NULL pointer.
char	**ft_split(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	int				words;
	char			*memory;
	char			**array;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	memory = ft_strdup(s);
	if (memory == 0)
		return (0);
	words = 0;
	i = 0;
	while (i < len)
	{
		if (memory[i] == c)
			memory[i] = '\0';
		else if (i == 0 || memory[i - 1] == '\0')
			words++;
		i++;
	}
	array = ft_addstrtoarray(memory, len, words);
	free(memory);
	return (array);
}
