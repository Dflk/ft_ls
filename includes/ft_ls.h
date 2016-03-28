/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:00:56 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/27 22:23:01 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
//# include <uuid/uuid.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <libft.h>
# include <time.h>

/*
** Check parameters [altRr]
*/
# define PARAM_A_POS 1
# define PARAM_L_POS 2
# define PARAM_T_POS 3
# define PARAM_R_MAX_POS 4
# define PARAM_R_MIN_POS 5

/*
** Error type
*/
# define USAGE 255

/*
** Binary mask (used for parameters)
*/
# define CHECK_BIT(BYTE, POS) (BYTE & (1 << POS))

/*
** Check permissions Owner/Group/OtherUsers
** Those permissions can be found in the header stat.h (see DEFFILEMODE)
*/
# define ISRUSR(MOD) (MOD & S_IRUSR)
# define ISWUSR(MOD) (MOD & S_IWUSR)
# define ISXUSR(MOD) (MOD & S_IXUSR)
# define ISRGRP(MOD) (MOD & S_IRGRP)
# define ISWGRP(MOD) (MOD & S_IWGRP)
# define ISXGRP(MOD) (MOD & S_IXGRP)
# define ISROTH(MOD) (MOD & S_IROTH)
# define ISWOTH(MOD) (MOD & S_IWOTH)
# define ISXOTH(MOD) (MOD & S_IXOTH)

/*
** Structure of files/directories to list
*/
typedef struct	s_entry
{
	char			*path;
	char			*name;
	int				error;
	int				dir;
	struct s_entry	*next;
}				t_entry;

/*
** Print error
*/
void			ft_error(int flag, int exit);

/*
** Parse params/arguments
*/
unsigned char	ft_parseparams(int argc, char **argv);
char			**ft_parseargs(int argc, char **argv);

/*
** Print entries
** ft_printl is only for the -l parameter
*/
void			ft_printl(t_entry *entry, size_t *spaces);
void			ft_ls(char **paths, unsigned char params);

/*
** Manage entries
*/
t_entry			*ft_fillentry(char **paths);
char			*ft_strsj(char *path, char *name, unsigned int size_name);
t_entry			*ft_sortentry(t_entry *entries, int flag);
t_entry			*ft_sortentry_dir(t_entry *entries);
t_entry			*ft_lastentry(t_entry *entries, t_entry *limit);
t_entry			*ft_findmax_name(t_entry *entries, t_entry *limit);
t_entry			*ft_findmax_path(t_entry *entries, t_entry *limit);
size_t			*ft_countspace(t_entry *entries);
size_t			ft_countnb(unsigned int nb);

#endif
