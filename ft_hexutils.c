/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:49:57 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 12:49:46 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_chrhex(int num)
{
	const char hexarr[] = "abcdef";

	if (num >= 10 && num <= 15)
		return (hexarr[num - 10]);
	return (num + 48);
}

int		has_hex(size_t num)
{
	size_t	max_divhex;
	size_t	mod;
	size_t	n;

	n = num;
	max_divhex = 1;
	while (n / max_divhex > 15)
		max_divhex *= 16;
	while (max_divhex)
	{
		mod = n / max_divhex;
		if (mod > 9)
			return (1);
		n %= max_divhex;
		max_divhex /= 16;
	}
	return (0);
}

int		ft_hexlen(size_t data)
{
	size_t	dec;
	int		count;

	dec = 1;
	count = 1;
	while (data / dec > 15)
	{
		dec *= 16;
		count++;
	}
	return (count);
}
