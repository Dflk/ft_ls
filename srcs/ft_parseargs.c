/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:47:34 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/18 10:10:26 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int	ft_countargs(int argc, char **argv)
{
	int		i;
	int		nargs;

	i = 0;
	nargs = 0;
	while (++i < argc)
		if (argv[i] && ft_strcmp(argv[i], "--") != 0)
			nargs++;
	return (nargs);
}

static void	ft_fillpaths(char **paths, int argc, char **argv)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (++i < argc)
		if (argv[i] && ft_strcmp(argv[i], "--") != 0)
		{
			paths[i2] = ft_strdup(argv[i]);
			i2++;
		}
	paths[i2] = NULL;
}

char		**ft_parseargs(int argc, char **argv)
{
	char	**paths;
	int		nargs;

	nargs = ft_countargs(argc, argv);
	paths = NULL;
	if (nargs == 0)
	{
		if ((paths = (char**)ft_memalloc(sizeof(char*) * 2)))
		{
			paths[0] = ft_strdup(".");
			paths[1] = NULL;
		}
	}
	else if ((paths = (char**)ft_memalloc(sizeof(char*) * (nargs + 1))))
		ft_fillpaths(paths, argc, argv);
	return (paths);
}
