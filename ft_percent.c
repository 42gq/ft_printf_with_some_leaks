/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 06:18:27 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/05 05:09:57 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent(t_env *e)
{
	char	*add;

	add = NULL;
	if (!(add = ft_memalloc(sizeof(char) * 2)))
		return (-1);
	add[0] = '%';
	add[1] = '\0';
	e->size += 1;
	add = ft_apply_options(add, e);
	if (!(e->stock = ft_strjoinfree(e->stock, add)))
		return (-1);
	return (2);
}
