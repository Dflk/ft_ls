/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:00:56 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/06 18:08:50 by rbaran           ###   ########.fr       */
/*   Updated: 2016/04/01 16:14:17 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# ifdef __APPLE__
#  include <uuid/uuid.h>
# endif
# include <uuid/uuid.h>
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
** Binary mask (major/minor)
*/
# define MAJOR(ST_RDEV) ((ST_RDEV >> 24) & 0xff)
# define MINOR(ST_RDEV) (ST_RDEV & 0xff)

/*
** Error type
*/
# define USAGE 255

/*
** Flag countspaces
*/
# define RESET 0
# define SET 1

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
	struct stat		stats;
	struct s_entry	*files;
	struct s_entry	*next;
}				t_entry;

/*
** Print error
*/
void			ft_error(int flag, int exit, char *str);

/*
** Parse params/arguments
*/
unsigned char	ft_parseparams(int argc, char **argv);
char			**ft_parseargs(int argc, char **argv);
void			ft_sortpaths(char **paths);

/*
** Print entries
** ft_printl is only for the -l parameter
*/
void			ft_printl(t_entry *entry, size_t *spaces);
void			ft_ls(char **paths, unsigned char params);
void			ft_puttotal(t_entry *entries);

/*
** Sort
*/
int				ft_order_byname(t_entry *a, t_entry *b);
int				ft_order_bytime(t_entry *a, t_entry *b);

/*
** Manage entries
*/
t_entry			*ft_fillentry(char **paths, unsigned char params);
int				ft_countlst(t_entry *entries);
void			ft_sortentries(t_entry **entries, unsigned char params);
char			*ft_strsj(char *path, char *name);
void			merge_sort(t_entry **head_ref, int (*f)(t_entry*, t_entry*));
t_entry			*ft_lastentry(t_entry *entries, t_entry *limit);
size_t			*ft_countspace(t_entry *entries, int flag);
size_t			ft_countnb(long int nb);

#endif
