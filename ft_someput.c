/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_someput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:51:02 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/12 11:38:14 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(size_t num, char font_size(char))
{
	size_t	max_divhex;
	size_t	mod;
	char	c;
	size_t	n;

	max_divhex = 1;
	n = num;
	while (n / max_divhex > 15)
		max_divhex *= 16;
	while (max_divhex)
	{
		mod = n / max_divhex;
		c = font_size(get_chrhex(mod));
		write(1, &c, 1);
		n %= max_divhex;
		max_divhex /= 16;
	}
}

void	ft_putpoint(size_t num, int checker)
{
	size_t	max_divhex;
	size_t	mod;
	size_t	n;
	char	c;

	max_divhex = 1;
	if (!has_hex(num))
		n = (size_t)&num;
	n = num;
	while (n / max_divhex > 15)
		max_divhex *= 16;
	write(1, "0x", 2);
	if (checker)
		return ;
	while (max_divhex)
	{
		mod = n / max_divhex;
		c = get_chrhex(mod);
		write(1, &c, 1);
		n %= max_divhex;
		max_divhex /= 16;
	}
}
