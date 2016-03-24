/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:17:01 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/24 16:19:22 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		ft_printtypeoffile(struct stat stats)
{
	if (S_ISBLK(stats.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(stats.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(stats.st_mode))
		ft_putchar('s');
	else if (S_ISREG(stats.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(stats.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(stats.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(stats.st_mode))
		ft_putchar('s');
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

void			ft_printl(t_entry *entry)
{
	struct stat	stats;

	stat(entry->path, &stats);
	ft_printtypeoffile(stats);
	ft_printpermissions(stats);
	ft_putstr("  ");
	ft_putnbr(stats.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(stats.st_uid)->pw_name);
	ft_putstr("  ");
	ft_putstr(getgrgid(stats.st_gid)->gr_name);
	ft_putchar('\t');
	ft_putstr(entry->name);
}
