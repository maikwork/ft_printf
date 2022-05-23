/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:50:12 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 14:05:30 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int n)
{
	long int		doz;
	long int		mod;
	char			c;

	doz = 1;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n / doz > 9)
		doz *= 10;
	while (doz)
	{
		mod = n / doz;
		c = mod + 48;
		write(1, &c, 1);
		n %= doz;
		doz /= 10;
	}
}

int		ft_atoi(const char *str)
{
	int		i;
	size_t	num;
	int		minus;

	minus = 1;
	i = 0;
	num = 0;
	if (!str)
		return (0);
	while ((str[i] > 8 && str[i] < 16) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
		num = num * 10 + (str[i++] - '0');
	if (minus > 0 && num > MAX_LONG)
		return (-1);
	if (minus < 0 && num > MAX_LONG)
		return (0);
	if (num)
		return (minus * num);
	return (0);
}

int		ft_intlen(long int data)
{
	int			dec;
	int			count;
	long int	tmp;

	dec = 1;
	count = 1;
	tmp = data;
	if (tmp < 0)
		tmp *= -1;
	while (tmp / dec > 9)
	{
		dec *= 10;
		count++;
	}
	return (count);
}
