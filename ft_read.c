/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 02:44:18 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/05 05:39:11 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		addon_read(t_env *e, char *tmp, int i, va_list arg)
{
	if (tmp[i] == '%')
	{
		ft_init_arg(e);
		if (ft_checkway(&tmp[i], e) < 0)
			return (ft_error_printf(-(ft_checkway(&tmp[i], e))));
		i += ft_save_arg(e, arg);
	}
	return (i);
}

int		ft_read(const char *format, va_list arg, t_env *e)
{
	int		i;
	int		l;
	char	*tmp;

	ft_strclr(e->stock);
	i = 0;
	l = ft_strlen(format);
	if (!(tmp = ft_strdup_until(format, l)))
		return (ft_error_printf(1));
	while (tmp[i] != '\0')
	{
		if (tmp[i] != '\0' && tmp[i] != '%' && ft_stock(&tmp[i], e) < 0)
			return (ft_error_printf(2));
		e->size += ft_strchr_count(&tmp[i], '%');
		i += ft_strchr_count(&tmp[i], '%');
		if (tmp[i] == '\0')
			break ;
		i = addon_read(e, tmp, i, arg);
		if (i < 0 || (e->error != 0 && e->error != 3))
			return (ft_error_printf(e->error));
	}
	write(1, e->stock, e->size);
	free(tmp);
	return (e->size);
}
