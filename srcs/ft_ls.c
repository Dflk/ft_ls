/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:28:39 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/24 11:26:33 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

static void			ft_print_ls(t_entry *entry, unsigned char params)
{
	if ((CHECK_BIT(params, PARAM_A_POS) && entry->name[0] == '.') ||
			entry->name[0] != '.')
	{
		if (CHECK_BIT(params, PARAM_L_POS))
			ft_printl(entry);
		else
			ft_putstr(entry->name);
		ft_putchar('\n');
	}
}

void				ft_ls(char **paths, unsigned char params)
{
	t_entry	*entries;

	if ((entries = ft_fillentry(paths)))
	{
		entries = ft_sortentry(entries, 0);
		entries = ft_sortentry(entries, 1);
		while (entries)
		{
			ft_print_ls(entries, params);
			entries = entries->next;
		}
	}
}
