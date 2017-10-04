/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:53:33 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/03 10:56:21 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkway(char *str, t_env *e)
{
	int i;

	i = 1;
	if (str[i] != '\0' && str[i] == '%')
	{
		e->condi = '%';
		return (1);
	}
	while (str[i] != '\0' && !(ft_condition(&str[i], e, 0)))
		i++;
	if (str[i] == '\0')
		return (-3);
	if (ft_condition(&str[i], e, 1) > 0)
		e->condi = str[i];
	else if (ft_condition(&str[i], e, 1) < 0)
	{
		return (-7);
	}
	return (1);
}
