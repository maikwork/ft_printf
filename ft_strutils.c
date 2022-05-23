/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:50:24 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/06 12:52:40 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			l;

	l = 0;
	if (!s)
		return (NULL);
	while (s[l])
		l++;
	if (start >= l)
		return (ft_calloc(1, sizeof(char)));
	if (!(s2 = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (len--)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}

int		ft_strlen(const char *s)
{
	int l;

	l = 0;
	if (!s)
		return (-1);
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	ft_putstr(char *s, int accu, int dot)
{
	int len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (!dot)
		accu = len;
	write(1, s, accu);
}
