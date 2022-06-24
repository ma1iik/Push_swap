/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:09:56 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/23 12:03:45 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *str);
int		ft_isalpha(int c);
char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbrunsigned(unsigned int n);
int		ft_putptr(unsigned long long ptr);
char	*ft_strdup(char *src);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t len);
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
char	*ft_strchr2(const char *str, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncpy(char *dst, const char *src, ssize_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

// PRINTF //
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putptr(unsigned long long ptr);
int		ft_base_hex(unsigned long long n);
int		ft_printf(const char *str, ...);
int		ft_base_hexbig(unsigned int n);
int		ft_putnbrunsigned(unsigned int n);
int		ft_formats(va_list args, char c);

//GNL//
char	*first_line(int fd, char *saveline);
char	*clean_line(char *s);
char	*ft_save_line(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);

#endif