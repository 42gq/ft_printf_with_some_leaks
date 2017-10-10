/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_llunt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 01:57:36 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/10 05:28:33 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_stockllutoa(unsigned long long int a, t_env *e)
{
	char	*str;
	int		base;

	if (e->condi == 'o' || e->condi == 'O')
		base = 8;
	else if (e->condi == 'x' || e->condi == 'X' || e->condi == 'p')
		base = 16;
	else if (e->condi == 'b')
		base = 2;
	else
		base = 10;
	str = ft_llutoa(a, base);
	return (str);
}

int		ft_handle_llunt(t_env *e)
{
	char	*add;

	add = NULL;
	e->nbr = (unsigned long long int)e->nbr;
	if (!(add = ft_stockllutoa(e->nbr, e)))
		return (-1);
	add = ft_apply_options(add, e);
	e->size += ft_strlen(add);
	if (e->condi > 64 && e->condi < 91)
		ft_capitalize(add);
	if (!(e->stock = ft_strjoinfree(e->stock, add)))
		return (-1);
	return (1);
}
