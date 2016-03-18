/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:56:08 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/18 15:52:12 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

static t_entry	*ft_addentryerror(int error, char *path)
{
	t_entry		*entry;

	if ((entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
	{
		entry->path = path;
		entry->error = error;
	}
	return (entry);
}

static t_entry	*ft_addentry(struct dirent *readfile, char *path)
{
	t_entry		*entry;

	if ((entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
	{
		entry->file = readfile;
		if (readfile)
			entry->path = ft_strsj(path, readfile->d_name, readfile->d_namlen);
		else
			entry->path = path;
		if (stat(entry->path, &(entry->stats)) == -1)
			ft_error(0, 1);
		entry->next = NULL;
	}
	return (entry);
}

static void		ft_readdir(t_entry **entry, char *path, DIR *opendirectory)
{
	struct dirent	*readfile;
	t_entry			*entry_buf;

	entry_buf = *entry;
	errno = 0;
	if (entry_buf)
	{
		while (entry_buf->next)
			entry_buf = entry_buf->next;
	}
	while ((readfile = readdir(opendirectory)))
	{
		if (entry_buf)
		{
			entry_buf->next = ft_addentry(readfile, path);
			entry_buf = entry_buf->next;
		}
		else
		{
			*entry = ft_addentry(readfile, path);
			entry_buf = *entry;
		}
	}
}

static void		ft_opendir(t_entry **entry, char *path)
{
	DIR		*opendirectory;
	t_entry	*entry_buf;

	entry_buf = NULL;
	if ((opendirectory = opendir(path)))
		ft_readdir(entry, path, opendirectory);
	else
	{
		entry_buf = *entry;
		if (!entry_buf)
			*entry = ft_addentryerror(errno, path);
		else
		{
			while (entry_buf->next)
				entry_buf = entry_buf->next;
			entry_buf->next = ft_addentryerror(errno, path);
		}
	}
}

t_entry			*ft_fillentry(char **paths)
{
	t_entry		*entry;
	t_entry		*entry_buf;
	int			i;
	struct stat	stats;

	entry = NULL;
	i = 0;
	while (paths[i])
	{
		if (stat(paths[i], &stats) == -1)
			ft_error(0, 1);
		if (S_ISDIR(stats.st_mode))
			ft_opendir(&entry, paths[i]);
		else
		{
			if (!entry)
				entry = ft_addentry(NULL, paths[i]);
			else
			{
				entry_buf = entry;
				while (entry->next)
					entry = entry->next;
				entry->next = ft_addentry(NULL, paths[i]);
				entry = entry_buf;
			}
		}
		i++;
	}
	return (entry);
}
