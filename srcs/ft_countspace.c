/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:19:36 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/08 13:33:24 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t		ft_countnb(long int nb)
{
	size_t	res;

	res = 0;
	if (nb == 0)
		res++;
	else
		while (nb)
		{
			res++;
			nb /= 10;
		}
	return (res);
}

static void		ft_checkspaces(t_entry *entry, size_t spaces[5])
{
	size_t			nb;
	struct passwd	*name;
	struct group	*grp;

	if ((nb = ft_countnb(entry->stats.st_nlink)) > spaces[0])
		spaces[0] = nb;
	if ((name = getpwuid(entry->stats.st_uid)))
		if ((nb = ft_strlen(name->pw_name)) > spaces[1])
			spaces[1] = nb;
	if ((nb = ft_countnb(entry->stats.st_uid)) > spaces[1])
		spaces[1] = nb;
	if ((grp = getgrgid(entry->stats.st_gid)))
		if ((nb = ft_strlen(grp->gr_name)) > spaces[2])
			spaces[2] = nb;
	if ((nb = ft_countnb(entry->stats.st_gid)) > spaces[2])
		spaces[2] = nb;
	if (!S_ISCHR(entry->stats.st_mode) && !S_ISBLK(entry->stats.st_mode))
	{
		if ((nb = ft_countnb(entry->stats.st_size)) > spaces[3])
			spaces[3] = nb;
	}
	else
	{
		if ((nb = ft_countnb(MAJOR(entry->stats.st_rdev))) > spaces[3])
			spaces[3] = nb;
		if ((nb = ft_countnb(MINOR(entry->stats.st_rdev))) > spaces[4])
			spaces[4] = nb;
	}
}

size_t		*ft_countspace(t_entry *entries, int flag, int flag_type)
{
	static size_t	spaces_dir[5] = {0, 0, 0, 0, 0};
	static size_t	spaces_files[5] = {0, 0, 0, 0, 0};

	if (flag == SET)
		while (entries)
		{
			if (flag_type == 1)
				ft_checkspaces(entries, spaces_dir);
			else
				ft_checkspaces(entries, spaces_files);
			entries = entries->next;
		}
	else if (flag == RESET)
	{
		if (flag_type == 1)
			ft_bzero(spaces_dir, sizeof(spaces_dir));
		else
			ft_bzero(spaces_files, sizeof(spaces_files));
	}
	if (flag_type == 1)
		return ((size_t*)spaces_dir);
	else
		return ((size_t*)spaces_files);
}
