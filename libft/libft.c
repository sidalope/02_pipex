/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:36:26 by abisiani          #+#    #+#             */
/*   Updated: 2025/06/05 11:21:20 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

// void	test_isalpha(void)
// {
// 	assert(ft_isalpha('a') == 1);
// 	assert(ft_isalpha('2') == 0);
// 	printf("ft_isalpha	OK\n");
// }

// void	test_isdigit(void)
// {
// 	assert(ft_isdigit('3') == 51);
// 	assert(ft_isdigit('0') == 48);
// 	assert(ft_isdigit('9') == 57);
// 	assert(ft_isdigit('\n') == 0);
// 	assert(ft_isdigit(3) == 0);
// 	printf("ft_isdigit	OK\n");
// }

// void	test_isalnum(void)
// {
// 	assert(ft_isalnum('3') == 51);
// 	assert(ft_isalnum('0') == 48);
// 	assert(ft_isalnum('9') == 57);
// 	assert(ft_isalnum('\n') == 0);
// 	assert(ft_isalnum(3) == 0);
// 	printf("ft_isalnum	OK\n");
// }

// void	test_isascii(void)
// {
// 	assert(ft_isascii('0') == 1);
// 	assert(ft_isascii('A') == 1);
// 	assert(ft_isascii('\n') == 1);
// 	assert(ft_isascii(0) == 1);
// 	assert(ft_isascii(127) == 1);
// 	assert(ft_isascii(-1) == 0);
// 	assert(ft_isascii(128) == 0);
// 	assert(ft_isascii(466) == 0);
// 	printf("ft_isascii	OK\n");
// }

// void	test_isprint(void)
// {
// 	assert(ft_isprint(' ') == 1);
// 	assert(ft_isprint(126) == 1);
// 	assert(ft_isprint(127) == 0);
// 	assert(ft_isprint(-1) == 0);
// 	assert(ft_isprint(30) == 0);
// 	printf("ft_isprint	OK\n");
// }

// void	test_strlen(void)
// {
// 	assert(ft_strlen("") == 0);
// 	assert(ft_strlen("abc def") == 7);
// 	assert(ft_strlen("a") == 1);
// 	printf("ft_strlen	OK\n");
// }

// void	test_memset(void)
// {
// 	void	*ptr_set;
// 	char	*ptr_view;

// 	ptr_set = malloc(10);
// 	ptr_view = (char *) ptr_set;
// 	assert(ft_memset(ptr_set, 50, 0) == ptr_set);
// 	assert(ft_memset(ptr_set, 50, 1) == ptr_set);
// 	assert(ptr_view[0] == 50);
// 	assert(ft_memset(ptr_set, 'f', 3) == ptr_set);
// 	assert(ptr_view[0] == 'f' && ptr_view[1] ==
// 'f'&& ptr_view[2] == 'f' && ptr_view[3] != 'f');
// 	free(ptr_set);
// 	printf("ft_memset	OK\n");
// }

// void	test_bzero(void)
// {
// 	void	*ptr_to_set;
// 	char	*ptr_to_view;

// 	ptr_to_set = malloc(10);
// 	ptr_to_view = (char *) ptr_to_set;
// 	ft_memset(ptr_to_set, 'f', 10);
// 	assert(ptr_to_view[0] == 'f');
// 	ft_bzero(ptr_to_set, (0));
// 	assert(ptr_to_view[0] == 'f');
// 	ft_bzero(ptr_to_set, 5);
// 	assert(ptr_to_view[4] == '\0');
// 	assert(ptr_to_view[5] == 'f');
// 	ft_bzero(ptr_to_set, 10);
// 	assert(ptr_to_view[9] == '\0');
// 	free(ptr_to_set);
// 	printf("ft_bzero	OK\n");
// }

// void	test_memcpy(void)
// {
// 	void	*ptr_to_dest;
// 	void	*ptr_to_src;
// 	char	*ptr_to_view;

// 	ptr_to_dest = malloc(10);
// 	ptr_to_src = malloc(10);
// 	ptr_to_view = (char *) ptr_to_dest;
// 	ft_memset(ptr_to_dest, '2', 10);
// 	ft_memset(ptr_to_src, '4', 10);

// 	ft_memcpy(ptr_to_dest, ptr_to_src, 0);
// 	assert(ptr_to_view[0] == '2');
// 	ft_memcpy(ptr_to_dest, ptr_to_src, 5);
// 	assert(ptr_to_view[0] == '4');
// 	assert(ptr_to_view[4] == '4');
// 	assert(ptr_to_view[5] == '2');
// 	ft_memcpy(ptr_to_dest, ptr_to_src, 10);
// 	assert(ptr_to_view[9] == '4');
// 	free(ptr_to_dest);
// 	free(ptr_to_src);
// 	printf("ft_memcpy	OK\n");
// }

// void	test_memmove(void)
// {
// 	void	*ptr_to_dest;
// 	void	*ptr_to_src;
// 	char	*ptr_to_view;

// 	// Test source before destination
// 	ptr_to_src = malloc(10);
// 	ptr_to_dest = ptr_to_src + 3;
// 	ptr_to_view = (char *) ptr_to_src;
// 	ft_memset(ptr_to_src, '4', 3);
// 	ft_memset(ptr_to_dest, '2', 7);
// 	ft_memmove(ptr_to_dest, ptr_to_src, 0);
// 	assert(ptr_to_view[0] == '4');
// 	ft_memmove(ptr_to_dest, ptr_to_src, 2);
// 	assert(ptr_to_view[0] == '4');
// 	assert(ptr_to_view[4] == '4');
// 	assert(ptr_to_view[5] == '2');
// 	ft_memmove(ptr_to_dest, ptr_to_src, 10);
// 	assert(ptr_to_view[9] == '2');
// 	free(ptr_to_src);
// 	// Test destination before source
// 	ptr_to_dest = malloc(10);
// 	ptr_to_src = ptr_to_dest + 2;
// 	ptr_to_view = (char *) ptr_to_dest;
// 	ft_memset(ptr_to_dest, '2', 10);
// 	ft_memset(ptr_to_src, '4', 3);
// 	// for(int i = 0; i < 10; i++)
// 	// {
// 	// 	printf("%c ", ptr_to_view[i]);
// 	// }
// 	// printf("\n");
// 	ft_memmove(ptr_to_dest, ptr_to_src, 2);
// 	// for(int i = 0; i < 10; i++)
// 	// {
// 	// 	printf("%c ", ptr_to_view[i]);
// 	// }
// 	// printf("\n");
// 	printf("ft_memmove	OK\n");
// }

// void	test_strlcpy(void)
// {
// 	char	*ptr_to_dest;
// 	char	*ptr_to_src;
// 	char 	a;
// 	char	b;

// 	ptr_to_dest = malloc(25);
// 	ptr_to_src = "Copied\0";
// 	memset(ptr_to_dest, 'x', 10);
// 	// printf("%zu\n", ft_strlcpy(ptr_to_dest, ptr_to_src, 3));
// 	// memset(ptr_to_dest, 'x', 10);
// 	// printf("%zu\n", strlcpy(ptr_to_dest, ptr_to_src, 3));
// 	// memset(ptr_to_dest, 'x', 10);
// 	a = ft_strlcpy(ptr_to_dest, ptr_to_src, 0);
// 	b = strlcpy(ptr_to_dest, ptr_to_src, 0);
// 	assert(a == b);
// 	memset(ptr_to_dest, 'x', 10);
// 	a = ft_strlcpy(ptr_to_dest, ptr_to_src, 3);
// 	b = strlcpy(ptr_to_dest, ptr_to_src, 3);
// 	assert(a == b);
// 	memset(ptr_to_dest, 'x', 10);
// 	a = ft_strlcpy(ptr_to_dest, ptr_to_src, 25);
// 	b = strlcpy(ptr_to_dest, ptr_to_src, 25);
// 	assert(a == b);
// 	memset(ptr_to_dest, 'x', 10);
// 	a = ft_strlcpy(ptr_to_dest, ptr_to_src, 26);
// 	b = strlcpy(ptr_to_dest, ptr_to_src, 26);
// 	assert(a == b);
// 	free(ptr_to_dest);
// 	printf("ft_strlcpy	OK\n");
// }

// void	test_strlcat(void)
// {
// 	// char	ptr_to_dest[15];
// 	// char	*ptr_to_src;
// 	// // At i == 12, src and a '\0' have beedn written to dst, meaning the
//  // // 	assert will fail.
// 	// for(int i = 0; i < 5; i++)
// 	// {
// 	// 	bzero(ptr_to_dest, 15);
// 	// 	memset(ptr_to_dest, 'x', 4);
// 	// 	ptr_to_src = "Catted\0";
// 	// 	printf(" strlcat with size %d\n", i);
// 	// 	printf("\n dest: %s\n", ptr_to_dest);
// 	// 	printf(" src: %s\n\n", ptr_to_src);
// 	// 	printf(" orig: %zu\n", strlcat(ptr_to_dest, ptr_to_src, i));
// 	// 	printf(" dest: %s\n", ptr_to_dest);
// 	// 	printf(" src: %s\n", ptr_to_src);
// 	// 	bzero(ptr_to_dest, 15);
// 	// 	memset(ptr_to_dest, 'x', 4);
// 	// 	printf(" mine: %zu\n", ft_strlcat(ptr_to_dest, ptr_to_src, i));
// 	// 	printf(" dest: %s\n", ptr_to_dest);
// 	// 	printf(" src: %s\n\n", ptr_to_src);
// 	// 	assert(ft_strlcat(ptr_to_dest, ptr_to_src, i) == 
// 	// 		strlcat(ptr_to_dest, ptr_to_src, i));
// 	// 	printf("~~~~~~~~~~~~~~~~~~~~~~~\n\n");
// 	// }
// 	printf("ft_strlcat	Cursed Beyond All Understanding\n");
// }

// void	test_tolower(void)
// {
// 	assert(ft_tolower('A') == 'a');
// 	assert(ft_tolower('3') == '3');
// 	assert(ft_tolower('\n') == '\n');
// 	printf("ft_tolower	OK\n");
// }

// void	test_toupper(void)
// {
// 	assert(ft_toupper('a') == 'A');
// 	assert(ft_toupper('3') == '3');
// 	assert(ft_toupper('\n') == '\n');
// 	printf("ft_toupper	OK\n");
// }

// void 	test_strchr(void)
// {
// 	const char	*test;
// 	char		*output;

// 	test = "Hello";
// 	output = ft_strchr(test, 'l');
// 	assert(*output == 'l');
// 	// printf("\n");
// 	// printf("%s", output);
// 	// printf("\n\n");
// 	output = 0;
// 	output = ft_strchr("Attempt Two", 't');
// 	assert(*output == 't');
// 	printf("ft_strchr	OK\n");
// }

// void 	test_strrchr(void)
// {
// 	const char	*test;
// 	char		*output;

// 	test = "Hello";
// 	output = ft_strrchr(test, 'l');
// 	assert(*output == 'l');
// 	// printf("\n");
// 	// printf("%s", output);
// 	// printf("\n\n");
// 	output = 0;
// 	output = ft_strrchr("Attempt Two", 't');
// 	assert(*output == 't');
// 	printf("ft_strrchr	OK\n");
// }

// void	test_strncmp(void)
// {
// 	int	a;
// 	int	b;

// 	a = strncmp("Hello", "Hello", 0);
// 	b = ft_strncmp("Hello", "Hello", 0);
// 	assert(a == b);
// 	a = strncmp("Hello", "Hello", 1);
// 	b = ft_strncmp("Hello", "Hello", 1);
// 	assert(a == b);
// 	a = strncmp("Hello", "Hello", 5);
// 	b = ft_strncmp("Hello", "Hello", 5);
// 	assert(a == b);
// 	a = strncmp("Hello", "Hello", 6);
// 	b = ft_strncmp("Hello", "Hello", 6);
// 	assert(a == b);
// 	a = strncmp("Hello", "Heddo", 0);
// 	b = ft_strncmp("Hello", "Heddo", 0);
// 	assert(a == b);
// 	a = strncmp("Hello", "Heddo", 1);
// 	b = ft_strncmp("Hello", "Heddo", 1);
// 	assert(a == b);	
// 	a = strncmp("Hello", "Heddo", 5);
// 	b = ft_strncmp("Hello", "Heddo", 5);
// 	printf("a: %i\nb: %i\n", a, b);
// 	assert(a == b);
// 	a = strncmp("Heddo", "Hello", 5);
// 	b = ft_strncmp("Heddo", "Hello", 5);
// 	assert(a == b);
// 	a = strncmp("Hello", "Heddo", 6);
// 	b = ft_strncmp("Hello", "Heddo", 6);
// 	assert(a == b);
// 	a = strncmp("Hello", "Hellooo", 6);
// 	b = ft_strncmp("Hello", "Hellooo", 6);
// 	assert(a == b);
// 	a = strncmp("Hello", "Hellooo", -1);
// 	b = ft_strncmp("Hello", "Hellooo", -1);
// 	assert(a == b);
// 	printf("ft_strncmp	OK\n");
// }

// void	test_memchr(void)
// {
// 	unsigned char	test_mem[5] = {0, 255, 12, 63, 8};
// 	unsigned char	*ptr_a;
// 	unsigned char	*ptr_b;

// 	ptr_a = memchr(test_mem, 12, 0);
// 	ptr_b = ft_memchr(test_mem, 12, 0);
// 	// printf("beat1_test\n");
// 	assert(ptr_a == ptr_b);
// 	ptr_a = memchr(test_mem, 12, 1);
// 	ptr_b = ft_memchr(test_mem, 12, 1);
// 	assert(ptr_a == ptr_b);
// 	ptr_a = memchr(test_mem, 12, 2);
// 	ptr_b = ft_memchr(test_mem, 12, 2);
// 	assert(ptr_a == ptr_b);
// 	ptr_a = memchr(test_mem, 12, 3);
// 	ptr_b = ft_memchr(test_mem, 12, 3);
// 	assert(ptr_a == ptr_b);
// 	ptr_a = memchr(test_mem, 12, 4);
// 	ptr_b = ft_memchr(test_mem, 12, 4);
// 	assert(ptr_a == ptr_b);
// 	ptr_a = memchr(test_mem, 12, 5);
// 	ptr_b = ft_memchr(test_mem, 12, 5);
// 	assert(ptr_a == ptr_b);
// 	ptr_a = memchr(test_mem, 12, 6);
// 	ptr_b = ft_memchr(test_mem, 12, 6);
// 	assert(ptr_a == ptr_b);
// 	printf("ft_memchr  	OK\n");
// }

// void	test_memcmp()
// {
// 	unsigned char	test_mem_1[5] = {0, 255, 12, 63, 8};
// 	unsigned char	test_mem_2[5] = {0, 255, 12, 63, 8};
// 	int				a;
// 	int				b;
// 	a = memcmp(test_mem_1, test_mem_2, 0);
// 	b = ft_memcmp(test_mem_1, test_mem_2, 0);
// 	assert(a == b);
// 	a = memcmp(test_mem_1, test_mem_2, 1);
// 	b = ft_memcmp(test_mem_1, test_mem_2, 1);
// 	assert(a == b);
// 	a = memcmp(test_mem_1, test_mem_2, 2);
// 	b = ft_memcmp(test_mem_1, test_mem_2, 2);
// 	assert(a == b);
// 	a = memcmp(test_mem_1, test_mem_2, 5);
// 	b = ft_memcmp(test_mem_1, test_mem_2, 5);
// 	assert(a == b);
// 	a = memcmp(test_mem_1, test_mem_2, 6);
// 	b = ft_memcmp(test_mem_1, test_mem_2, 6);
// 	assert(a == b);

// 	unsigned char	test_mem_3[5] = {0, 255, 3, 63, 8};

// 	// for (size_t i = 0; i < 5; i++)
// 	// 	printf("%li: %i, %i\n", i, test_mem_1[i], test_mem_3[i]);
// 	a = memcmp(test_mem_1, test_mem_3, 1);
// 	b = ft_memcmp(test_mem_1, test_mem_3, 1);
// 	assert(a == b);
// 	a = memcmp(test_mem_1, test_mem_3, 3);
// 	b = ft_memcmp(test_mem_1, test_mem_3, 3);
// 	// printf("a: %i\nb: %i\n", a, b);
// 	assert(a == b);
// 	a = memcmp(test_mem_1, test_mem_3, 5);
// 	b = ft_memcmp(test_mem_1, test_mem_3, 5);
// 	assert(a == b);
// 	printf("ft_memcmp  	OK\n");
// }

// void test_strnstr(void)
// {
// 	const char	*large = "Foo Bar Baz";
// 	const char	*small = "Bar";
// 	char		*a;
// 	char		*b;

// 	a = strnstr(large, small, 0);
// 	b = ft_strnstr(large, small, 0);
// 	assert(a == b);
// 	a = strnstr(large, small, 1);
// 	b = ft_strnstr(large, small, 1);
// 	assert(a == b);
// 	a = strnstr(large, small, 5);
// 	b = ft_strnstr(large, small, 5);
// 	assert(a == b);
// 	a = strnstr(large, small, 7);
// 	b = ft_strnstr(large, small, 7);
// 	assert(a == b);
// 	a = strnstr(large, small, 8);
// 	b = ft_strnstr(large, small, 8);
// 	assert(a == b);
// 	a = strnstr(large, small, 5);
// 	b = ft_strnstr(large, small, 5);
// 	assert(a == b);
// 	const char *large2 = "Foo Bar Baz";
// 	const char *small2 = "Bak";
// 	a = strnstr(large2, small2, 15);
// 	b = ft_strnstr(large2, small2, 15);
// 	assert(a == b);
// 	printf("ft_strnstr	OK\n");
// }

// void	test_atoi(void)
// {
// 	assert(atoi("Hello") == ft_atoi("Hello"));
// 	assert(atoi("") == ft_atoi(""));
// 	assert(atoi("234") == ft_atoi("234"));
// 	assert(atoi("0") == ft_atoi("0"));
// 	// printf("orig: %i\nft: %i\n", atoi("dfn"), ft_atoi("dfn"));
// 	assert(atoi("-2342Hello") == ft_atoi("-2342Hello"));
// 	assert(atoi("--2342Hello") == ft_atoi("--2342Hello"));
// 	assert(atoi("   +++2342Hello   ") == ft_atoi("   +++2342Hello   "));
// 	printf("ft_atoi  	OK\n");
// }

// void	test_calloc(void)
// {
// 	printf("ft_calloc	WIP!\n");
// }

// void	test_strdup(void)
// {
// 	char	*a;
// 	char	*b;
// 	a = ft_strdup("Hey, buddy.");
// 	b = strdup("Hey, buddy.");
// 	// printf("%s\n", a);
// 	// printf("%s\n", b);
// 	assert(a[0] == b[0]);
// 	assert(a[10] == b[10]);
// 	printf("ft_strdup	WIP!\n");
// }

// void	test_substr(void)
// {
// 	char	*a;

// 	a = ft_substr("Hello", 2, 2);
// 	// printf("%s\n", a);
// 	assert(a[0] == ("ll")[0]);
// 	assert(a[1] == ("ll")[1]);
// 	assert(a[2] == ("ll")[2]);
// 	printf("ft_substr	WIP!\n"); 
// }

// void	test_strjoin(void)
// {
// 	char	*a;
// 	a = ft_strjoin("Hell", "o");
// 	// printf("%s\n", a);
// 	assert(a[4] == ("Hello"[4]));
// 	printf("ft_strjoin	WIP!\n");
// }

// void	test_strtrim(void)
// {
// 	// ft_strtrim("++===-+-hello=x=-++", "+-=");
// 	printf("\nbacbhelloabcac: %s\n\n", ft_strtrim("bacbhelloabcac", "abc"));
// 	printf("ft_strtrim	WIP!\n");
// }
// // void	test_split(void)
// // {
// // 	printf("ft_split	WIP!\n");
// // }

// void	test_itoa(void)
// {
// 	// Take an int
// 	// return a string representing that int
// 	// char *a;
// 	// a = ft_itoa(-234);
// 	// printf("%s\n", a);
// 	// assert(itoa(234) == ("234"));
// 	// assert(itoa(0) == ("0"));
// 	//Check max int
// 	printf("ft_itoa		WIP!\n");
// }

// void	test_strmapi(void)
// {
// 	printf("ft_strmapi	WIP!\n");
// }

// void	test_striteri(void)
// {
// 	printf("ft_striteri	WIP!\n");
// }

// void	test_putchar_fd(void)
// {
// 	printf("ft_putchar_fd	WIP!\n");
// }

// void	test_putstr_fd(void)
// {
// 	printf("ft_putstr_fd	WIP!\n");
// }

// void	test_putendl_fd(void)
// {
// 	printf("ft_putendl_fd	WIP!\n");
// }

// void	test_putnbr_fd(void)
// {
// 	printf("ft_putnbr_fd	WIP!\n");
// }

int	main(void)
{
	return (0);
}
	// test_isalpha();
	// test_isdigit();
	// test_isalnum();
	// test_isascii();
	// test_isprint();
	// test_strlen();
	// test_memset();
	// test_bzero();
	// test_memcpy();
	// test_memmove();
	// test_strlcpy();
	// test_strlcat();
	// test_tolower();
	// test_toupper();
	// test_strchr();
	// test_strrchr();
	// test_strncmp();
	// test_memchr();
	// // test_memcmp();
	// test_strnstr();
	// test_atoi();
	// test_calloc();
	// test_strdup();
	// test_substr();
	// test_strjoin();
	// test_strtrim();
	// // test_split();
	// test_itoa();
	// test_strmapi();
	// test_striteri();
	// test_putchar_fd();
	// test_putstr_fd();
	// test_putendl_fd();
	// test_putnbr_fd();
	// return (0);
// }
