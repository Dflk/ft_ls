/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:19:23 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/01 14:11:20 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_strsj(char *path, char *name)
{
	char	*str;

	if (!path)
		return (NULL);
	str = NULL;
	if (path[ft_strlen(path) - 1] != '/')
	{
		path = ft_strjoin(path, "/");
		str = path; 
	}
	if (name)
	{
		path = ft_strjoin(path, name);
		if (str)
			free(str);
	}
	return (path);
}
