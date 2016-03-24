/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:56:08 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/24 14:15:21 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

static t_entry	*ft_addentry(struct dirent *readfile, char *path)
{
	t_entry		*entry;

	if ((entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
	{
		if (readfile)
		{
			entry->path = ft_strsj(path, readfile->d_name, readfile->d_namlen);
			entry->name = readfile->d_name;
			entry->name[readfile->d_namlen] = '\0';
		}
		else
		{
			entry->path = path;
			entry->name = path;
		}
		entry->error = errno;
		entry->next = NULL;
	}
	return (entry);
}

static void		ft_readdir(t_entry **entry, char *path, DIR *opendirectory)
{
	struct dirent	*readfile;
	t_entry			*entry_buf;

	entry_buf = NULL;
	if (*entry)
		entry_buf = ft_lastentry(*entry, NULL);
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
		if (!*entry)
			*entry = ft_addentry(NULL, path);
		else
		{
			entry_buf = ft_lastentry(*entry, NULL);
			entry_buf->next = ft_addentry(NULL, path);
		}
	}
}

static void		ft_readpath(t_entry **entry, char *path)
{
	t_entry		*entry_buf;

	entry_buf = NULL;
	if (!*entry)
		*entry = ft_addentry(NULL, path);
	else
	{
		entry_buf = ft_lastentry(*entry, NULL);
		entry_buf->next = ft_addentry(NULL, path);
	}
}

t_entry			*ft_fillentry(char **paths)
{
	t_entry		*entry;
	int			i;
	struct stat	stats;

	entry = NULL;
	i = 0;
	while (paths[i])
	{
		errno = 0;
		stat(paths[i], &stats);
		if (S_ISDIR(stats.st_mode))
			ft_opendir(&entry, paths[i]);
		else
			ft_readpath(&entry, paths[i]);
		i++;
	}
	return (entry);
}
