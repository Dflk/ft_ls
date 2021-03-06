/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageentries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:55:44 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/06 18:06:43 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_entry	*ft_lastentry(t_entry *entries, t_entry *limit)
{
	if (entries != limit)
		while (entries->next != limit)
			entries = entries->next;
	return (entries);
}

int		ft_countlst(t_entry *entries)
{
	int		i;

	i = 0;
	while (entries)
	{
		entries = entries->next;
		i++;
	}
	return (i);
}
