/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:17:13 by xlebecq           #+#    #+#             */
/*   Updated: 2024/06/25 23:34:54 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// LIBFT

typedef struct s_libft
{
	void			*content;
	struct s_libft	*next;
}					t_libft;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(const char *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *litlle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_lstadd_front(t_libft **lst, t_libft *new);
t_libft				*ft_lstnew(void *content);
void				ft_lstdelone(t_libft *lst, void (*del)(void *));
int					ft_lstsize(t_libft *lst);
void				ft_lstiter(t_libft *lst, void (*f)(void *));
t_libft				*ft_lstmap(t_libft *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstclear(t_libft **lst, void (*del)(void *));
t_libft				*ft_lstlast(t_libft *lst);
void				ft_lstadd_back(t_libft **lst, t_libft *new);

// PRINTF

int					ft_printf(const char *input, ...);
char				*ft_strdup(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_threat(char c, va_list args, int *input_count);
void				ft_putchar_rtn(char c, int *input_count);
void				ft_putstr_rtn(char *s, int *input_count);
size_t				ft_strlen(const char *s);
void				ft_putnbr_base(unsigned long long n, char *base,
						int *input_count, char c);
void				ft_putnbr(int n, int *intput_count);
void				ft_putnbr_unsigned(unsigned int n, int *input_count);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				ft_create_lst(t_list **lst, char *buffer);
void				ft_create_list(t_list **lst, char *buffer, int fd);
int					ft_read(t_list **lst, int fd);
int					ft_find_nl(t_list *lst);
char				*concatenate_lst(t_list *lst);
void				ft_rest(t_list **lst);
t_list				*ft_listlast(t_list *lst);
int					ft_lstsize_nl(t_list *lst);
void				ft_create_line(t_list *lst, char *line);
void				ft_clear_lst(t_list **lst, t_list *lst_rest, char *rest);

#endif
