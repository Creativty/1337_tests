/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:30:00 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 15:45:23 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdio.h>
#	include <string.h>
#	include <stdlib.h>
#	include "../log.h"
#	include "./libft.h"

struct SplitTest {
	const char *src;
	char		c;
	size_t	len;
};

static char *exp[][128] = {
	{ "Hello,", "world" },
	{ "Hello", " world" },
	{ "Hello", " world" },
	{ 0 },
	{ "Hello", " world" },
	{ "Hello", " world" },
	{ "a", "b", "c", "d", "e" },
};

int	ft_split_test(void)
{
	int	failures;
	failures = 0;

	struct SplitTest tests[] = {
		{ "Hello, world", ' ', 2 },
		{ "Hello, world", ',', 2 },
		{ ",Hello, world,", ',', 2 },
		{ "", ',', 0 },
		{ "Hello, world,", ',', 2 },
		{ ",Hello, world", ',', 2 },
		{ "a,b,c,d,e", ',', 5 },
	};

	for (int i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); ++i)
	{
		struct SplitTest test = tests[i];
		int	j = 0;
		int success = 1;
		char **out = ft_split(test.src, test.c);
		while (out[j])
		{
			if (j >= (int)test.len)
			{
				printf(COLOR_RED"ft_split[%d][%d]"COLOR_RESET"\t::\tindices out of bounds\n", i, j);
				success = 0;
			} 
			else if (strcmp(out[j], exp[i][j]) != 0)
			{
				printf(COLOR_RED"ft_split[%d][%d]"COLOR_RESET"\t::\tuser: \"%s\"\texpected: \"%s\"\n", i, j, out[j], exp[i][j]);
				success = 0;
			}
			j++;
		}
		if (out[j] != NULL)
			success = 0;
		if (!success)
		{
			log_error("test %d: unexpected failure", i);
			failures++;
		}
		if (out)
			free(out);
	}

	return (failures);
}
