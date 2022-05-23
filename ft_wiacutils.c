/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wiacutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:51:44 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/12 11:29:27 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_checkret(int *wiac, int count, int sign)
{
	if (wiac[0] > count && wiac[0] > wiac[1])
		return (wiac[0] - sign);
	if ((wiac[1] > count && wiac[1] >= wiac[0]))
		return (wiac[1]);
	return (count);
}

static int		*set_default_wiac(char *pr_width, char *pr_accu, int *p_count)
{
	const int	width = ft_atoi(pr_width);
	const int	accu = ft_atoi(pr_accu);
	int			*wiac;

	wiac = malloc(sizeof(int) * 2);
	wiac[0] = width;
	wiac[1] = accu;
	*p_count = 0;
	return (wiac);
}

int				ft_usewiac(t_pars *printer, void *data)
{
	int			count;
	int			*wiac;
	const char	type = printer->type;

	wiac = set_default_wiac(printer->width, printer->accu, &count);
	if (wiac[0] < 0)
		printer->flag = -1;
	if (wiac[0] < 0)
		wiac[0] *= -1;
	if (type == 's')
		count = secistr(wiac, (char *)data, printer);
	else if (type == 'p')
		count = secipoint(wiac, (size_t)data, printer);
	else if (type == 'x')
		count = secihex(wiac, (unsigned int)data, printer, ft_tolower);
	else if (type == 'X')
		count = secihex(wiac, (unsigned int)data, printer, ft_toupper);
	count = ft_checkret(wiac, count, 0);
	free(wiac);
	return (count);
}

int				ft_usewiac_int(t_pars *printer, int data)
{
	int			count;
	int			*wiac;
	const char	type = printer->type;
	int			sign;

	sign = 0;
	wiac = set_default_wiac(printer->width, printer->accu, &count);
	if (data < 0 && type != 'c')
		sign = 1;
	if (wiac[0] < 0)
		printer->flag = -1;
	if (wiac[0] < 0)
		wiac[0] *= -1;
	if (type == 'c' || type == '%')
		count += secichr(wiac[0], data, printer->flag);
	else
		count += secint(wiac, data, printer);
	if (wiac[1] == 0 && wiac[0] == 0 && printer->dot && data == 0)
		return (0);
	count = ft_checkret(wiac, count, sign) + sign;
	free(wiac);
	return (count);
}

int				ft_usewiac_uns(t_pars *p, unsigned int d)
{
	int			count;
	int			*wiac;

	wiac = set_default_wiac(p->width, p->accu, &count);
	if (wiac[0] < 0)
		p->flag = -1;
	if (wiac[0] < 0)
		wiac[0] *= -1;
	count += secint(wiac, d, p);
	if (wiac[1] == 0 && wiac[0] == 0 && p->dot && d == 0)
		return (0);
	count = ft_checkret(wiac, count, 0);
	free(wiac);
	return (count);
}
