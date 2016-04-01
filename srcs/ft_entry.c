/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:56:08 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/01 15:30:46 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_entry	*ft_addentryfile(struct dirent *readfile, char *path)
{
	t_entry		*entry;

	if ((entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
	{
		entry->path = ft_strsj(path, readfile->d_name);
		if (lstat(entry->path, &(entry->stats)) == -1)
			entry->error = errno;
		entry->name = ft_strdup(readfile->d_name);
		entry->dir = 0;
		entry->files = NULL;
		entry->next = NULL;
	}
	return (entry);
}

static void		ft_readdir(t_entry *entry, DIR *opendirectory)
{
	struct dirent	*readfile;
	t_entry			*entry_buf;

	while ((readfile = readdir(opendirectory)))
	{
		if (!(entry->files))
		{
			entry->files = ft_addentryfile(readfile, entry->path);
			entry_buf = entry->files;
		}
		else
		{
			entry_buf->next = ft_addentryfile(readfile, entry->path);
			entry_buf = entry_buf->next;
		}
	}
	if (entry->files)
		entry->files = ft_sortentry(entry->files);
}

static int		ft_opendir(t_entry *entry)
{
	DIR		*opendirectory;
	int		error;

	error = 0;
	if ((opendirectory = opendir(entry->path)))
	{
		ft_readdir(entry, opendirectory);
		closedir(opendirectory);
	}
	else
		error = errno;
	entry->dir = 1;
	return (error);
}

static t_entry	*ft_addentry(char *path)
{
	t_entry		*entry;

	if ((entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
	{
		if (lstat(path, &(entry->stats)) == -1)
			entry->error = errno;
		entry->path = path;
		entry->name = path;
		entry->files = NULL;
		entry->dir = 0;
		if (errno == 0 && S_ISDIR(entry->stats.st_mode))
			entry->error = ft_opendir(entry);
		entry->next = NULL;
	}
	return (entry);
}

t_entry			*ft_fillentry(char **paths)
{
	t_entry		*entry_begin;
	t_entry		*entry;
	int			i;

	entry_begin = NULL;
	i = 0;
	while (paths[i])
	{
		errno = 0;
		if (!entry_begin)
		{
			entry_begin = ft_addentry(paths[i]);
			entry = entry_begin;
		}
		else
		{
			entry->next = ft_addentry(paths[i]);
			entry = entry->next;
		}
		i++;
	}
	return (entry_begin);
}
