/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:17:01 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/01 13:56:58 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char		ft_printtypeoffile(struct stat stats)
{
	char	perm;

	perm = 0;
	if (S_ISBLK(stats.st_mode))
		perm = 'b';
	else if (S_ISCHR(stats.st_mode))
		perm = 'c';
	else if (S_ISFIFO(stats.st_mode))
		perm = 's';
	else if (S_ISREG(stats.st_mode))
		perm = '-';
	else if (S_ISDIR(stats.st_mode))
		perm = 'd';
	else if (S_ISLNK(stats.st_mode))
		perm = 'l';
	else if (S_ISSOCK(stats.st_mode))
		perm = 's';
	return (perm);
}

static void		ft_printpermissions(struct stat stats)
{
	ft_putchar(ISRUSR(stats.st_mode) ? 'r' : '-');
	ft_putchar(ISWUSR(stats.st_mode) ? 'w' : '-');
	ft_putchar(ISXUSR(stats.st_mode) ? 'x' : '-');
	ft_putchar(ISRGRP(stats.st_mode) ? 'r' : '-');
	ft_putchar(ISWGRP(stats.st_mode) ? 'w' : '-');
	ft_putchar(ISXGRP(stats.st_mode) ? 'x' : '-');
	ft_putchar(ISROTH(stats.st_mode) ? 'r' : '-');
	ft_putchar(ISWOTH(stats.st_mode) ? 'w' : '-');
	ft_putchar(ISXOTH(stats.st_mode) ? 'x' : '-');
}

static void		ft_putspaces(size_t i, size_t spaces)
{
	while (i++ < spaces)
		ft_putchar(' ');
}

static void		ft_puttime(time_t *t)
{
	char *str;

	str = ctime(t) + 4;
	str[12] = '\0';
	ft_putstr(str);
}

void			ft_printl(t_entry *entry, size_t *spaces)
{
	char		buf[256];
	ssize_t		len;

	ft_putchar(ft_printtypeoffile(entry->stats));
	ft_printpermissions(entry->stats);
	ft_putchar(' ');
	ft_putspaces(ft_countnb(entry->stats.st_nlink), spaces[0]);
	ft_putnbr(entry->stats.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(entry->stats.st_uid)->pw_name);
	ft_putchar(' ');
	ft_putspaces(ft_strlen((getpwuid(entry->stats.st_uid)->pw_name)), spaces[1]);
	ft_putstr(getgrgid(entry->stats.st_gid)->gr_name);
	ft_putspaces(ft_strlen((getgrgid(entry->stats.st_gid)->gr_name)), spaces[2]);
	ft_putchar(' ');
	ft_putspaces(ft_countnb(entry->stats.st_size), spaces[3]);
	ft_putnbr(entry->stats.st_size);
	ft_putchar(' ');
	ft_puttime(&(entry->stats.st_mtime));
	ft_putchar(' ');
	ft_putstr(entry->name);
	if ((len = readlink(entry->path, (char*)buf, 256)) != -1)
	{
		ft_putstr(" -> ");
		buf[len] = '\0';
		ft_putstr((char*)buf);
	}
}
