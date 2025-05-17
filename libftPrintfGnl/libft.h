/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:07:07 by mbudkevi          #+#    #+#             */
/*   Updated: 2025/05/17 15:12:11 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int i);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *lt, size_t len);
char	**ft_split(char const *s, char c);
int		print_char(char a);
int		print_int(int number);
int		print_string(char *str);
int		print_hexadecimal(unsigned int number, char symbol);
int		print_unsigned_d(unsigned int number);
int		print_pointer(void *ptr);
int		ft_printf(const char *format, ...);
void	free_gnl_stash(void);
char	**get_stash_reference(void);
char	*get_next_line(int fd);
char	**ft_multi_split(char const *s, char *delim);
void	ft_free_split(char **splitted);

#endif
