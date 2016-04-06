/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:28:39 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/06 18:06:33 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			ft_printlst(t_entry *entries, unsigned char params,
		size_t *spaces)
{
	t_entry *entry;

	entry = entries->files;
	while (entry)
	{
		if ((CHECK_BIT(params, PARAM_A_POS) && entry->name[0] == '.') ||
				entry->name[0] != '.')
		{
			if (CHECK_BIT(params, PARAM_L_POS))
				ft_printl(entry, spaces);
			else
				ft_putstr(entry->name);
			ft_putchar('\n');
		}
		entry = entry->next;
	}
	if (entries->next)
		ft_putchar('\n');
	ft_countspace(NULL, RESET);
}

static void			ft_printfile(t_entry *entry, unsigned char params,
		size_t *spaces)
{
	if (entry->error)
		ft_error(entry->error, 0, entry->name);
	else
	{
		if ((CHECK_BIT(params, PARAM_A_POS) && entry->name[0] == '.') ||
				entry->name[0] != '.')
		{
			if (CHECK_BIT(params, PARAM_L_POS))
			{
				ft_printl(entry, spaces);
				ft_countspace(NULL, RESET);
			}
			else
				ft_putstr(entry->path);
			if (entry->next)
				ft_putstr("\n\n");
			else
				ft_putchar('\n');
		}
	}
}

static void			ft_printls_r(t_entry *entries, unsigned char params)
{
	char	*path[2];

	while (entries)
	{
		while (entries->files)
		{
			if (ft_strcmp(entries->files->name, ".")
					&& ft_strcmp(entries->files->name, "..")
					&& S_ISDIR(entries->files->stats.st_mode))
				if (CHECK_BIT(params, PARAM_A_POS) ||
						(entries->files->name[0] != '.'))
				{
						path[0] = entries->files->path;
						path[1] = NULL;
						ft_putchar('\n');
						ft_putstr(path[0]);
						ft_putstr(":\n");
						ft_ls(path, params);
				}
			entries->files = entries->files->next;
		}
		entries = entries->next;
	}
}

void				ft_ls(char **paths, unsigned char params)
{
	t_entry	*entries;
	t_entry	*begin_entries;

	if ((entries = ft_fillentry(paths, params)))
	{
		ft_sortentries(&entries, params);
		begin_entries = entries;
		while (entries)
		{
			if (entries->files)
				ft_printlst(entries, params, ft_countspace(entries->files, SET));
			else
				ft_printfile(entries, params, ft_countspace(entries, SET));
			entries = entries->next;
		}
	}
	if (CHECK_BIT(params, PARAM_R_MAX_POS))
		ft_printls_r(begin_entries, params);
}
