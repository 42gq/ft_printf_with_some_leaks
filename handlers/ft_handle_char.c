/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 04:10:45 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/04 04:18:22 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_char(char v_arg, t_env *e)
{
	char *add;
	char c;

	c = v_arg;
	add = NULL;
	if (!(add = ft_strchar(add, v_arg)))
		add = ft_strdup("\0");
	add = ft_apply_optionschar(add, e);
	if (e->condi != 'C')
		e->size += (c) ? ft_strlen(add) : ft_strlen(add) + 1;
	if (!(e->stock = ft_strjoinfree(e->stock, add)))
		return (-1);
	return (1);
}
