/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:09:48 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/07 22:32:07 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_printtypeoffile(struct stat stats)
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

void	ft_printpermissions(struct stat stats)
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
	ft_putchar(' ');
}

void	ft_putsize(t_entry *entry, size_t spaces)
{
	ft_putspaces(ft_countnb(entry->stats.st_size), spaces);
	ft_putnbr(entry->stats.st_size);
	ft_putchar(' ');
}

void	ft_puttime(time_t *t) 
{
	char *str;

	str = ctime(t) + 4;
	str[12] = '\0';
	ft_putstr(str);
	ft_putchar(' ');
}

void	ft_putid(t_entry *entry, size_t *spaces)
{
	if (GET_PWUID)
	{
		ft_putstr(GET_PWUID->pw_name);
		ft_putspaces(ft_strlen((GET_PWUID->pw_name)), spaces[1]);
	}
	else
	{
		ft_putnbr(ST_UID);
		ft_putspaces(ft_countnb(ST_UID), spaces[1]);
	}
	ft_putchar(' ');
	if (GET_GRGID)
	{
		ft_putstr(GET_GRGID->gr_name);
		ft_putspaces(ft_strlen((GET_GRGID->gr_name)), spaces[2]);
	}
	else
	{
		ft_putnbr(ST_GID);
		ft_putspaces(ft_countnb(ST_GID), spaces[2]);
	}
}
