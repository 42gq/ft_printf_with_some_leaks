/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_somme_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 06:32:46 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/05 04:18:06 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_somme_option(t_env *e)
{
	int i;
	//printf("e->space = %i\ne->h = %i\ne->diese = %i\ne->null = %i\ne->minus = %i\ne->preci_size = %i\ne->field_size = %i\ne->plus = %i\ne->l = %i\ne->j = %i\ne->z = %i\n\ne->size_arg = %i\ne->size = %i\n\n", e->space, e->h, e->diese, e->null, e->minus, e->preci_size, e->field_size, e->plus, e->l, e->j, e->z, e->size_arg, e->size);
	i = e->space + e->h + e->diese + e->null + e->minus
		+ e->preci_size + e->field_size + e->plus + e->l + e->j + e->z + 2;
	return (i);
}
