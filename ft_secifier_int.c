/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secifier_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:29:40 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 14:02:52 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		headint(int sign, int *wiac, t_pars *printer, long int data)
{
	int			accu;
	int			width;
	int			dot;
	const int	len = ft_intlen(data);

	accu = wiac[1];
	width = wiac[0];
	dot = printer->dot;
	if (sign)
		write(1, "-", 1);
	if (accu > len)
		ft_printchr('0', accu - len);
	if (dot && !accu && !data)
		write(1, NULL, 1);
	else
		ft_putnbr(data);
	ft_printchr(' ', width - accu - sign);
	return (len);
}

int		tailint(int sign, int *wiac, t_pars *printer, long int data)
{
	int			accu;
	int			width;
	int			dot;
	const int	len = ft_intlen(data);
	const int	flag = printer->flag;

	accu = wiac[1];
	width = wiac[0];
	dot = printer->dot;
	if (flag != 1 && width > accu + sign)
		ft_printchr(' ', width - accu - sign);
	if (sign)
		write(1, "-", 1);
	if (flag == 1 && width > accu + sign)
		ft_printchr('0', width - accu - sign);
	if (accu > len && !(flag == 1 && width > accu + sign))
		ft_printchr('0', accu - len);
	if (dot && !accu && !data)
		write(1, NULL, 1);
	else
		ft_putnbr(data);
	return (len);
}
