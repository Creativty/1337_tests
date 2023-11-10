#include "../shared.h"

TestGroup	test_match_group(char *name)
{
	if (strcmp(name, "ft_atoi") == 0) return TEST_GROUP_ATOI;
	if (strcmp(name, "ft_bzero") == 0) return TEST_GROUP_BZERO;
	if (strcmp(name, "ft_calloc") == 0) return TEST_GROUP_CALLOC;
	if (strcmp(name, "ft_isalnum") == 0) return TEST_GROUP_ISALNUM;
	if (strcmp(name, "ft_isalpha") == 0) return TEST_GROUP_ISALPHA;
	if (strcmp(name, "ft_isascii") == 0) return TEST_GROUP_ISASCII;
	if (strcmp(name, "ft_isdigit") == 0) return TEST_GROUP_ISDIGIT;
	if (strcmp(name, "ft_isprint") == 0) return TEST_GROUP_ISPRINT;
	if (strcmp(name, "ft_itoa") == 0) return TEST_GROUP_ITOA;
	if (strcmp(name, "ft_lstmap_bonus") == 0) return TEST_GROUP_LSTMAP_BONUS;
	if (strcmp(name, "ft_memchr") == 0) return TEST_GROUP_MEMCHR;
	if (strcmp(name, "ft_memcmp") == 0) return TEST_GROUP_MEMCMP;
	if (strcmp(name, "ft_memmove") == 0) return TEST_GROUP_MEMMOVE;
	if (strcmp(name, "ft_memset") == 0) return TEST_GROUP_MEMSET;
	if (strcmp(name, "ft_split") == 0) return TEST_GROUP_SPLIT;
	if (strcmp(name, "ft_strdup") == 0) return TEST_GROUP_STRDUP;
	if (strcmp(name, "ft_strlen") == 0) return TEST_GROUP_STRLEN;
	if (strcmp(name, "ft_substr") == 0) return TEST_GROUP_SUBSTR;
	if (strcmp(name, "ft_tolower") == 0) return TEST_GROUP_TOLOWER;
	if (strcmp(name, "ft_toupper") == 0) return TEST_GROUP_TOUPPER;
 	return (TEST_GROUP_NIL);
 }

