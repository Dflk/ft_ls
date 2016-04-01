/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:02:28 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/30 12:54:10 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_entry			*ft_sortentry(t_entry *begin_entries)
{
	t_entry	*turtle_entry;
	t_entry	*entries;
	t_entry	*max;
	t_entry	*limit;

	limit = NULL;
	while (ft_lastentry(begin_entries, limit) != begin_entries)
	{
		entries = ft_lastentry(begin_entries, limit);
		max = ft_findmax_name(begin_entries, limit);
		turtle_entry = ft_lastentry(begin_entries, max);
		if (max == begin_entries)
			begin_entries = begin_entries->next;
		else if (max->next != limit)
			turtle_entry->next = max->next;
		max->next = entries->next;
		if (max != entries)
			entries->next = max;
		limit = max;
	}
	return (begin_entries);
}


t_entry			*ft_sortentry_dir(t_entry *begin_entries)
{
	t_entry	*entries;
	t_entry	*entries_buf;
	size_t	len;
	size_t	i;

	entries = begin_entries;
	len = ft_countlst(begin_entries);
	i = 0;
	while (++i <= len)
		if (entries->dir)
		{
			if (entries == begin_entries)
			{
				begin_entries = begin_entries->next;
				entries_buf = begin_entries;
			}
			else
			{
				ft_lastentry(begin_entries, entries)->next = entries->next;
				entries_buf = ft_lastentry(begin_entries, entries->next);
			}
			ft_lastentry(entries, NULL)->next = entries;
			entries->next = NULL;
			entries = entries_buf;
		}
		else
			entries = entries->next;
	return (begin_entries);
}

void			ft_sortpaths(char **paths)
{
	int		i;
	char	*buf;

	i = 0;
	while (paths[i + 1])
	{
		if (ft_strcmp(paths[i], paths[i + 1]) > 0)
		{
			buf = paths[i];
			paths[i] = paths[i + 1];
			paths[i + 1] = buf;
			i = 0;
		}
		else
			i++;
	}
}
