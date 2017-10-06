/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:27:56 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 09:05:26 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int		res;
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		return (-1);
	e->size = 0;
	if (e->stock)
		ft_strclr(e->stock);
	e->stock = ft_strnew(1);
	ft_init_arg(e);
	va_start(arg, format);
	res = ft_read(format, arg, e);
	ft_strdel(&e->stock);
	va_end(arg);
	return (res);
}
