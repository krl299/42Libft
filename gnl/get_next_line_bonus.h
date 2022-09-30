/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:56:21 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/06/08 13:27:33 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
//	<---	MAIN	--->
char	*get_next_line(int fd);
int		ft_fill_mem(char **mem, int fd);
char	*ft_get_line(char **mem);
void	ft_clean_mem(char **mem);
//	<---	UTILS	--->
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(char *str);
size_t	ft_len_line(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
