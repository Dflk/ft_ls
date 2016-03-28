/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageentries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:55:44 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/27 20:06:13 by rbaran           ###   ########.fr       */
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

t_entry	*ft_findmax_name(t_entry *entries, t_entry *limit)
{
	t_entry	*max;

	max = entries;
	while (entries != limit)
	{
		if (ft_strcmp(entries->name, max->name) > 0)
			max = entries;
		entries = entries->next;
	}
	return (max);
}

t_entry	*ft_findmax_path(t_entry *entries, t_entry *limit)
{
	t_entry	*max;

	max = entries;
	while (entries != limit)
	{
		if (ft_strcmp(entries->path, max->path) > 0)
			max = entries;
		entries = entries->next;
	}
	return (max);
}
