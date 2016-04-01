/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:28:39 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/01 16:15:01 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void			ft_print_ls(t_entry *entry, unsigned char params,
		size_t *spaces)
{
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
			ft_putchar('\n');
		}
	}
}

static void			ft_printls_r(t_entry *entries, unsigned char params)
{
	char	**path;

	while (entries)
	{
		while (entries->files)
		{
			if (ft_strcmp(entries->files->name, ".")
					&& ft_strcmp(entries->files->name, "..")
					&& S_ISDIR(entries->files->stats.st_mode))
				if (CHECK_BIT(params, PARAM_A_POS) ||
						(entries->files->name[0] != '.'))
					if ((path = (char**)ft_memalloc(sizeof(char*) * 2)))
					{
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

	if ((entries = ft_fillentry(paths)))
	{
		if (entries->next)
			entries = ft_sortentry_dir(entries);
		begin_entries = entries;
		while (entries)
		{
			if (entries->files)
			{
				ft_print_ls(entries->files, params, ft_countspace(entries->files, SET));
				if (entries->next)
					ft_putchar('\n');
			}
			else
			{
				ft_printfile(entries, params, ft_countspace(entries, SET));
				if (entries->next && entries->next->files)
					ft_putchar('\n');
			}
			entries = entries->next;
		}
	}
	if (CHECK_BIT(params, PARAM_R_MAX_POS))
		ft_printls_r(begin_entries, params);
}
