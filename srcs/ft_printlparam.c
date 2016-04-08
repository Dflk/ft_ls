/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:17:01 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/08 17:03:18 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		ft_putmajmin(t_entry *entry, size_t *spaces)
{
	ft_putspaces(ft_countnb(MAJOR(entry->stats.st_rdev)), spaces[3]);
	ft_putnbr(MAJOR(entry->stats.st_rdev));
	ft_putstr(", ");
	ft_putspaces(ft_countnb(MINOR(entry->stats.st_rdev)), spaces[4]);
	ft_putnbr(MINOR(entry->stats.st_rdev));
}

void			ft_printl(t_entry *entry, size_t *spaces, int file)
{
	char		buf[256];
	ssize_t		len;

	ft_printtypeoffile(entry->stats);
	ft_printpermissions(entry->stats);
	ft_putspaces(ft_countnb(entry->stats.st_nlink), spaces[0]);
	ft_putnbr(entry->stats.st_nlink);
	ft_putchar(' ');
	ft_putid(entry, spaces);
	ft_putchar(' ');
	spaces[4] ? ft_putmajmin(entry, spaces) : ft_putsize(entry, spaces[3]);
	ft_putchar(' ');
	ft_puttime(&(entry->stats.st_mtime));
	if (file)
		ft_putstr(entry->name);
	else
		ft_putstr(entry->path);
	if ((len = readlink(entry->path, (char*)buf, 256)) != -1)
	{
		ft_putstr(" -> ");
		buf[len] = '\0';
		ft_putstr((char*)buf);
	}
}
