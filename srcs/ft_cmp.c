/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:01:53 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/07 10:52:47 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	ft_order_byname(t_entry *a, t_entry *b)
{
	return (ft_strcmp(a->name, b->name) < 0);
}

int	ft_order_bytime(t_entry *a, t_entry *b)
{
	return (b->stats.st_mtime <= a->stats.st_mtime);
}
