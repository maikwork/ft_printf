/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:08:01 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/13 13:36:26 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		secipoint(int *wiac, size_t data, t_pars *p)
{
	const int	len = ft_hexlen(data) + 2;
	int			flag;
	int			width;
	int			checker;

	width = wiac[0];
	flag = p->flag;
	checker = p->dot && !wiac[1];
	if (!~flag)
	{
		ft_putpoint(data, checker);
		ft_printchr(' ', width - len);
		return (len);
	}
	ft_printchr(' ', width - len);
	ft_putpoint(data, checker);
	return (len);
}

int		secint(int *wiac, long int data, t_pars *printer)
{
	const int	len = ft_intlen(data);
	int			sign;
	int			flag;
	int			dot;
	int			zero;

	sign = 0;
	zero = 0;
	dot = printer->dot;
	if (dot && wiac[1] >= 0 && printer->flag != -1)
		printer->flag = 0;
	flag = printer->flag;
	if (dot && !data && !wiac[1])
		zero = 1;
	if (!zero && wiac[1] < len)
		wiac[1] = len;
	if (data < 0 && ++sign)
		data *= -1;
	if (!~flag)
		return (headint(sign, wiac, printer, data));
	return (tailint(sign, wiac, printer, data));
}

int		secihex(int *wiac, unsigned int d, t_pars *p, char font(char))
{
	const int	len = ft_hexlen(d);
	int			zero;

	zero = 0;
	if (p->dot && wiac[1] >= 0 && p->flag != -1)
		p->flag = 0;
	if (p->dot && !d && !wiac[1])
		zero = 1;
	if (!zero && wiac[1] < len)
		wiac[1] = len;
	if (!~p->flag)
		return (headhex(wiac, p, d, font));
	return (tailhex(wiac, p, d, font));
}

int		secistr(int *wiac, char *data, t_pars *printer)
{
	const int	len = ft_strlen(data);

	if (wiac[1] < 0)
		wiac[1] = len;
	if (~len && (wiac[1] > len || !printer->dot))
		wiac[1] = len;
	if (!data)
	{
		if ((!printer->dot && !wiac[1]) || wiac[1] > 6 || wiac[1] < 0)
			wiac[1] = 6;
		data = ft_strdup("(null)");
	}
	if (!~printer->flag)
	{
		ft_putstr(data, wiac[1], printer->dot);
		ft_printchr(' ', wiac[0] - wiac[1]);
		if (printer->dot)
			return (wiac[1]);
		return (len - wiac[1]);
	}
	ft_printchr(' ', wiac[0] - wiac[1]);
	ft_putstr(data, wiac[1], printer->dot);
	if (printer->dot)
		return (wiac[1]);
	return (len);
}

int		secichr(int width, int data, int flag)
{
	int len;

	len = 1;
	if (width > len)
		len = width;
	if (!~flag)
	{
		ft_putchar(data);
		if (width > 1)
			ft_printchr(' ', width - 1);
		return (len);
	}
	if (data == '%' && flag == 1)
		ft_printchr('0', width - 1);
	if (width > 1 && flag != 1)
		ft_printchr(' ', width - 1);
	ft_putchar(data);
	return (len);
}
