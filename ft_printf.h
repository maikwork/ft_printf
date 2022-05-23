/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:41:00 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/12 11:29:20 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "stdarg.h"

# define MAX_LONG 9223372036854775807

typedef struct	s_pars
{
	char		type;
	int			flag;
	char		*width;
	char		*accu;
	int			dot;
}				t_pars;

char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_strlen(const char *s);
void			ft_putstr(char *s, int accu, int dot);
char			*ft_strchr(const char *str, int c);

void			ft_putchar(char c);
char			ft_tolower(char c);
char			ft_toupper(char c);

char			get_chrhex(int num);
int				has_hex(size_t num);
int				ft_hexlen(size_t data);

void			ft_putnbr(long int n);
int				ft_atoi(const char *str);
int				ft_intlen(long int data);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);

void			ft_bzero(void *s, unsigned int n);
void			*ft_calloc(unsigned int count, unsigned int size);
void			ft_delpar(t_pars *p);

void			ft_puthex(size_t num, char font_size(char));
void			ft_putpoint(size_t num, int dot);

int				ft_usewiac(t_pars *printer, void *data);
int				ft_usewiac_int(t_pars *printer, int data);
void			ft_printchr(char chr, int count);
int				ft_usewiac_uns(t_pars *p, unsigned int d);

int				ft_isflag(int c);

void			set_default(t_pars *list);
int				get_flag(char *str_pos, int *p_i);
char			*get_value(char *str_pos, int *p_i);

int				secipoint(int *wiac, size_t data, t_pars *p);
int				secint(int *wiac, long int data, t_pars *printer);
int				secihex(int *wiac, unsigned int d, t_pars *p, char f(char));
int				secichr(int width, int data, int flag);
int				secistr(int *wiac, char *data, t_pars *printer);
int				headint(int sign, int *wiac, t_pars *printer, long int data);
int				tailint(int sign, int *wiac, t_pars *printer, long int data);
int				headhex(int *wiac, t_pars *p, unsigned int data, char f(char));
int				tailhex(int *wiac, t_pars *p, unsigned int data, char f(char));

int				ft_printf(char *format, ...);

#endif
