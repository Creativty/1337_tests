#ifndef DATA_H
 #define DATA_H
 
 int	ft_atoi_test(void);
int	ft_bzero_test(void);
int	ft_calloc_test(void);
int	ft_isalnum_test(void);
int	ft_isalpha_test(void);
int	ft_isascii_test(void);
int	ft_isdigit_test(void);
int	ft_isprint_test(void);
int	ft_itoa_test(void);
int	ft_lstmap_bonus_test(void);
int	ft_memchr_test(void);
int	ft_memcmp_test(void);
int	ft_memmove_test(void);
int	ft_memset_test(void);
int	ft_split_test(void);
int	ft_strdup_test(void);
int	ft_strlen_test(void);
int	ft_substr_test(void);
int	ft_tolower_test(void);
int	ft_toupper_test(void);
 static const char	*testNames[43] = {
 	"ft_atoi",
	"ft_bzero",
	"ft_calloc",
	"ft_isalnum",
	"ft_isalpha",
	"ft_isascii",
	"ft_isdigit",
	"ft_isprint",
	"ft_itoa",
	"ft_lstadd_back_bonus",
	"ft_lstadd_front_bonus",
	"ft_lstclear_bonus",
	"ft_lstdelone_bonus",
	"ft_lstiter_bonus",
	"ft_lstlast_bonus",
	"ft_lstmap_bonus",
	"ft_lstnew_bonus",
	"ft_lstsize_bonus",
	"ft_memchr",
	"ft_memcmp",
	"ft_memcpy",
	"ft_memmove",
	"ft_memset",
	"ft_putchar_fd",
	"ft_putendl_fd",
	"ft_putnbr_fd",
	"ft_putstr_fd",
	"ft_split",
	"ft_strchr",
	"ft_strdup",
	"ft_striteri",
	"ft_strjoin",
	"ft_strlcat",
	"ft_strlcpy",
	"ft_strlen",
	"ft_strmapi",
	"ft_strncmp",
	"ft_strnstr",
	"ft_strrchr",
	"ft_strtrim",
	"ft_substr",
	"ft_tolower",
	"ft_toupper",
 };
 static const int	testCount = 43;
 static int (*const testFuncs[])(void) = {
 	ft_atoi_test,
	ft_bzero_test,
	ft_calloc_test,
	ft_isalnum_test,
	ft_isalpha_test,
	ft_isascii_test,
	ft_isdigit_test,
	ft_isprint_test,
	ft_itoa_test,
	ft_lstmap_bonus_test,
	ft_memchr_test,
	ft_memcmp_test,
	ft_memmove_test,
	ft_memset_test,
	ft_split_test,
	ft_strdup_test,
	ft_strlen_test,
	ft_substr_test,
	ft_tolower_test,
	ft_toupper_test,
 };
 typedef enum {
 	TEST_GROUP_ATOI,
	TEST_GROUP_BZERO,
	TEST_GROUP_CALLOC,
	TEST_GROUP_ISALNUM,
	TEST_GROUP_ISALPHA,
	TEST_GROUP_ISASCII,
	TEST_GROUP_ISDIGIT,
	TEST_GROUP_ISPRINT,
	TEST_GROUP_ITOA,
	TEST_GROUP_LSTMAP_BONUS,
	TEST_GROUP_MEMCHR,
	TEST_GROUP_MEMCMP,
	TEST_GROUP_MEMMOVE,
	TEST_GROUP_MEMSET,
	TEST_GROUP_SPLIT,
	TEST_GROUP_STRDUP,
	TEST_GROUP_STRLEN,
	TEST_GROUP_SUBSTR,
	TEST_GROUP_TOLOWER,
	TEST_GROUP_TOUPPER,
 	TEST_GROUP_NIL,
 }	TestGroup;
 #endif
