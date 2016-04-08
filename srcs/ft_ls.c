/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:28:39 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/08 18:27:22 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			ft_printlst(t_entry *entries, unsigned char params,
		size_t *spaces)
{
	t_entry *entry;

	entry = entries->files;
	if (CHECK_BIT(params, PARAM_L_POS))
		ft_puttotal
	while (entry)
	{
		if ((CHECK_BIT(params, PARAM_A_POS) && entry->name[0] == '.') ||
				entry->name[0] != '.')
		{
			if (CHECK_BIT(params, PARAM_L_POS))
				ft_printl(entry, spaces, 1);
			else
				ft_putstr(entry->name);
			ft_putchar('\n');
		}
		entry = entry->next;
	}
	if (entries->next)
		ft_putchar('\n');
	ft_countspace(NULL, RESET, 1);
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
				ft_printl(entry, spaces, 0);
			else
				ft_putstr(entry->path);
			ft_putchar('\n');
			if (entry->next->dir == 1)
				ft_putchar('\n');
		}
	}
}

static void			ft_printls_r(t_entry **entries, unsigned char params)
{
	char	*path[2];

	while (*entries)
	{
		if (ft_strcmp((*entries)->name, ".")
				&& ft_strcmp((*entries)->name, "..")
				&& S_ISDIR((*entries)->stats.st_mode))
			if (CHECK_BIT(params, PARAM_A_POS) ||
					((*entries)->name[0] != '.'))
			{
				path[0] = (*entries)->path;
				path[1] = NULL;
				ft_putchar('\n');
				ft_putpath(path[0]);
				ft_ls(path, params);
			}
		*entries = ft_free(entries, 0);
	}
}

void				ft_ls(char **paths, unsigned char opt)
{
	t_entry	*entries;
	t_entry	*begin_entries;

	if ((entries = ft_fillentry(paths, opt)))
	{
		ft_sortentries(&entries, opt);
		begin_entries = entries;
		ft_countspace(begin_entries, SET, 0);
		while (entries)
		{
			if (entries->files)
			{
				if (paths[1])
					ft_putpath(entries->path);
				ft_printlst(entries, opt, ft_countspace(entries->files, SET, 1));
				if (CHECK_BIT(opt, PARAM_R_MAX_POS))
					ft_printls_r(&(entries->files), opt);
				if (entries->next)
					ft_putchar('\n');
			}
			else
				ft_printfile(entries, opt, ft_countspace(NULL, 2, 0));
			entries = ft_free(&entries, 1);
		}
	}
}
