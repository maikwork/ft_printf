/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:41:15 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 13:50:45 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		quant_ten(int n, int *doz)
{
	int len;
	int doz2;

	len = 1;
	doz2 = 1;
	n = n < 0 ? n * -1 : n;
	while (n / doz2 > 9)
	{
		doz2 *= 10;
		len++;
	}
	*doz = doz2;
	return (len);
}

static int		check_sign(int n, char *s, int *i)
{
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		*i += 1;
	}
	return (n);
}

static void		ft_modopr(int *n, int *mod, int *doz)
{
	*mod = *n / *doz;
	*n %= *doz;
	*doz /= 10;
}

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char			*ft_itoa(int n)
{
	int		doz;
	int		mod;
	int		len;
	char	*str;
	int		i;

	i = 0;
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else
	{
		len = quant_ten(n, &doz);
		str = n < 0 ? malloc(sizeof(char) * (len + 2))
					: malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		n = check_sign(n, str, &i);
		while (doz)
		{
			ft_modopr(&n, &mod, &doz);
			str[i++] = mod + 48;
		}
		str[i] = '\0';
	}
	return (str);
}
