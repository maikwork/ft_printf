/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:49:44 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 14:05:11 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void	ft_putchar(char c)
{
	unsigned char b;

	b = (unsigned char)c;
	if (b == '%')
		write(1, &b, 1);
	else
		write(1, &b, 1);
}

void	ft_printchr(char chr, int count)
{
	if (count < 0)
		return ;
	while (count--)
		write(1, &chr, 1);
}
