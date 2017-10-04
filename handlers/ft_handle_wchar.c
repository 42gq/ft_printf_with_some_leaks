/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 06:17:32 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/04 05:27:01 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_wchar(wint_t v_arg, t_env *e)
{
	char	*mem;
	char	*add;
	wint_t	chr;

	mem = NULL;
	add = NULL;
	chr = v_arg;
	add = ft_conv_wint_to_str(chr, e);
	if (e->preci_size && e->size_w > e->preci)
		ft_strclr(add);
	mem = ft_apply_optionschar(add, e);
	ft_strclr(add);
	e->size += (chr) ? ft_strlen(mem) : ft_strlen(mem);
	if (!(e->stock = ft_strjoinfree(e->stock, mem)))
		return (-1);
	return (1);
}
