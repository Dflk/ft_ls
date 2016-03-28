/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:17:01 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/27 19:27:30 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

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

static void		ft_putspaces(void *content, size_t spaces, int flag)
{
	size_t	i;

	i = (flag) ? ft_countnb(*((int*)content)) : ft_strlen((char*)content);
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
	struct stat	stats;

	stat(entry->path, &stats);
	ft_putchar(ft_printtypeoffile(stats));
	ft_printpermissions(stats);
	ft_putchar(' ');
	ft_putspaces(&(stats.st_nlink), spaces[0], 1);
	ft_putnbr(stats.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(stats.st_uid)->pw_name);
	ft_putchar(' ');
	ft_putspaces(&(getpwuid(stats.st_uid)->pw_name), spaces[1], 0);
	ft_putstr(getgrgid(stats.st_gid)->gr_name);
	ft_putspaces(&(getgrgid(stats.st_gid)->gr_name), spaces[2], 0);
	ft_putchar(' ');
	ft_putspaces(&(stats.st_size), spaces[3], 1);
	ft_putnbr(stats.st_size);
	ft_putchar(' ');
	ft_puttime(&(stats.st_mtime));
	ft_putchar(' ');
	ft_putstr(entry->name);
}
