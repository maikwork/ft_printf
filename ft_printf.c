/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:52:04 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 14:14:07 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pars	*ft_parser(char *str_pos, int *p_i)
{
	int		i;
	t_pars	*tab;

	i = *p_i + 1;
	while (str_pos[i] == ' ')
		write(1, &str_pos[i++], 1);
	tab = (t_pars *)malloc(sizeof(t_pars));
	set_default(tab);
	tab->flag = get_flag(str_pos, &i);
	if ((str_pos[i] >= '0' && str_pos[i] <= '9') || str_pos[i] == '*')
		tab->width = get_value(str_pos, &i);
	if (str_pos[i] == '.')
	{
		tab->dot = 1;
		i++;
		if ((str_pos[i] >= '0' && str_pos[i] <= '9') || str_pos[i] == '*')
			tab->accu = get_value(str_pos, &i);
	}
	tab->type = str_pos[i];
	*p_i = ++i;
	return (tab);
}

void	checker_star(t_pars *printer, va_list *ap)
{
	if (printer->width && printer->width[0] == '*')
	{
		free(printer->width);
		printer->width = ft_itoa(va_arg(*ap, int));
	}
	if (printer->accu && printer->accu[0] == '*')
	{
		free(printer->accu);
		printer->accu = ft_itoa(va_arg(*ap, int));
	}
}

int		opertype(t_pars *p, va_list ap, int *p_count)
{
	int count;

	count = *p_count;
	if (p->type == '%')
	{
		count += ft_usewiac_int(p, '%');
		*p_count = count;
		return (1);
	}
	else if (p->type == 's')
		count += ft_usewiac(p, (void *)va_arg(ap, char *));
	else if (p->type == 'p' || p->type == 'x' || p->type == 'X')
		count += ft_usewiac(p, (void *)va_arg(ap, size_t));
	else if (p->type == 'u')
		count += ft_usewiac_uns(p, va_arg(ap, unsigned int));
	else
		count += ft_usewiac_int(p, va_arg(ap, int));
	*p_count = count;
	return (0);
}

char	printup_pers(char *format, int *p_i, int *p_count)
{
	int i;
	int count;

	i = *p_i;
	count = *p_count;
	while (format[i] && format[i] != '%' && ++count)
		write(1, &format[i++], 1);
	*p_i = i;
	*p_count = count;
	return (format[i]);
}

int		ft_printf(char *format, ...)
{
	int				i;
	int				count;
	va_list			ap;
	t_pars			*p;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (!printup_pers(format, &i, &count))
			break ;
		p = ft_parser(format, &i);
		checker_star(p, &ap);
		opertype(p, ap, &count);
		ft_delpar(p);
	}
	return (count);
}
