/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:02:28 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/06 18:05:50 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_entry	*ft_sortentry_dir(t_entry *begin_entries, t_entry **entries)
{
	t_entry	*entries_buf;
	t_entry	*entries_buf2;

	if ((*entries)->dir)
	{
		if (begin_entries == *entries)
		{
			entries_buf = begin_entries;
			begin_entries = begin_entries->next;
			*entries = begin_entries;
		}
		else
		{
			entries_buf = ft_lastentry(begin_entries, *entries);
			entries_buf2 = entries_buf;
			entries_buf->next = (*entries)->next;
			entries_buf = *entries;
			*entries = entries_buf2;
		}
		ft_lastentry(begin_entries, NULL)->next = entries_buf;
		entries_buf->next = NULL;
	}
	else
		(*entries) = (*entries)->next;
	return (begin_entries);
}

void			ft_sortentries(t_entry **entries, unsigned char params)
{
	int		len;
	int		i;
	t_entry	*begin_entries;

	i = 0;
	merge_sort(entries, &ft_order_byname);
	if (CHECK_BIT(params, PARAM_T_POS))
		merge_sort(entries, &ft_order_bytime);
	begin_entries = *entries;
	len = ft_countlst(*entries);
	if ((*entries)->next)
		while (i < len)
		{
			begin_entries = ft_sortentry_dir(begin_entries, entries);
			i++;
		}
	*entries = begin_entries;
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
