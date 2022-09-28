/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:44:26 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:31:27 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_printf
{
	const char	*fmt;
	int			i;
	int			count;
	va_list		args;
}				t_printf;

typedef struct s_arg
{
	long int	flags;
	int			width;
	int			has_precision;
	int			precision;
	char		length;
	char		specifier;
}				t_arg;

typedef struct s_formatted
{
	int			left_justify;
	int			spaces;
	int			zeroes;
	char		prefix;
	int			c_null;
	char		sign;
	char		*content;
}				t_formatted;

typedef enum e_flags {
	LEFT_JUSTIFY = 1 << 0,
	SHOW_SIGN = 1 << 1,
	NO_SIGN = 1 << 2,
	SHOW_PREFIX = 1 << 3,
	PAD_ZERO = 1 << 4,
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_t_printf_init(t_printf *pr, const char *fmt);
int				ft_t_printf_peek(t_printf *pr, char *next);
void			ft_t_arg_init(t_arg *arg);
t_arg			ft_parse_arg(t_printf *pr);
void			ft_parse_flags(t_printf *pr, t_arg *arg);
void			ft_parse_width(t_printf *pr, t_arg *arg);
void			ft_parse_precision(t_printf *pr, t_arg *arg);
void			ft_parse_length(t_printf *pr, t_arg *arg);
void			ft_parse_specifier(t_printf *pr, t_arg *arg);
void			ft_t_formatted_init(t_formatted *f);
int				ft_print_arg(t_printf *pr, t_arg *arg);
void			ft_t_formatted_free(t_formatted *f);
void			ft_do_print(t_formatted *f);
int				ft_count_printed(t_formatted *f);
int				ft_print_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putspace(int len, char l);
int				ft_corresponding(char c, char *s);
void			ft_handle_width(t_arg *arg, t_formatted *f);
void			ft_handle_flags(t_arg *arg, t_formatted *f);
void			ft_handle_zeroes(t_arg *arg, t_formatted *f);
void			ft_handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f);
char			*ft_itoa_base(int value, const char *base, char spec);
char			*ft_itoa_base_ptr(long int value, int base);
int				ft_len_base(int nb, int b);
int				ft_len_ptr(long int nb);
void			ft_spec_number(t_printf *pr, t_arg *arg, t_formatted *f);
void			ft_spec_string(t_printf *pr, t_arg	*arg, t_formatted *f);
void			ft_spec_char(t_printf *pr, t_formatted *f);
void			ft_spec_pointer(t_printf *pr, t_formatted *f);
void			ft_spec_percent(t_arg *arg, t_formatted *f);
void			ft_spec_n(t_printf *pr);
size_t			ft_print_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
