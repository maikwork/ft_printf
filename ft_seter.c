/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 10:51:17 by rbliss            #+#    #+#             */
/*   Updated: 2021/01/09 13:44:08 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_default(t_pars *list)
{
	list->type = '\0';
	list->width = NULL;
	list->accu = NULL;
	list->flag = 0;
	list->dot = 0;
}

int		get_flag(char *str_pos, int *p_i)
{
	int		i;
	int		flag;
	int		change;

	i = *p_i;
	flag = 0;
	change = 0;
	while (str_pos[i] && (ft_isflag(str_pos[i]) || str_pos[i] == ' '))
	{
		if (str_pos[i] == '-' && ++change)
			flag = -1;
		else if (!change && str_pos[i] == '0')
			flag = 1;
		i++;
	}
	*p_i = i;
	return (flag);
}

char	*get_value(char *str_pos, int *p_i)
{
	int		i;
	char	*value;

	i = *p_i;
	while ((str_pos[i] >= '0' && str_pos[i] <= '9') || (str_pos[i] == '*'))
		i++;
	value = ft_substr(str_pos, *p_i, i - *p_i);
	*p_i = i;
	return (value);
}

int		ft_isflag(int c)
{
	if (c == '0' || c == '-')
		return (1);
	return (0);
}
