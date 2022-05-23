/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:50:36 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 13:49:05 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((unsigned int*)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void *test;

	if (!(test = malloc(count * size)))
		return (NULL);
	ft_bzero(test, count * size);
	return (test);
}

void	ft_delpar(t_pars *p)
{
	free(p->width);
	free(p->accu);
	free(p);
}
