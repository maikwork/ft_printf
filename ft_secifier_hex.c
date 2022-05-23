/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secifier_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:28:24 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 14:01:42 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		headhex(int *wiac, t_pars *p, unsigned int data, char font(char))
{
	const int	len = ft_hexlen(data);
	const int	width = wiac[0];

	if (wiac[1] > len)
		ft_printchr('0', wiac[1] - len);
	if (p->dot && !wiac[1] && !data)
		write(1, NULL, 1);
	else
		ft_puthex(data, font);
	ft_printchr(' ', width - wiac[1]);
	if (!wiac[1] && !data)
		return (0);
	return (len);
}

int		tailhex(int *wiac, t_pars *p, unsigned int data, char font(char))
{
	const int	len = ft_hexlen(data);
	const int	width = wiac[0];
	int			accu;

	accu = wiac[1];
	if (p->flag != 1 && width > accu)
		ft_printchr(' ', width - wiac[1]);
	if (p->flag == 1 && width > accu)
		ft_printchr('0', width - wiac[1]);
	if (accu > len && !(p->flag == 1 && width > accu))
		ft_printchr('0', wiac[1] - len);
	if (p->dot && !wiac[1] && !data)
		write(1, NULL, 1);
	else
		ft_puthex(data, font);
	if (!accu && !data)
		return (0);
	return (len);
}
