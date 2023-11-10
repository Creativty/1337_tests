/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:13:22 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/05 18:39:01 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>
#	include <string.h>
# include "../log.h"
#	include "./libft.h"

struct SubstrTest {
	const char *string;
	const char *expect;
	unsigned int	start;
	size_t				len;
};

int ft_substr_test(void)
{
	int	failures = 0;
	struct SubstrTest tests[] = {
		{ "Hello, world", "o, world", 4, 8 },
		{ "Hello, world", "llo, wor", 2, 8 },
		{ "Hello, world", "world", 7, 8 },
		{ "Hello, world", "Hel", 0, 3 },
		{ "Hello, world", "", 3, 0 },
	};

	for (int i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
	{
		struct SubstrTest	test = tests[i];
		char	*out = ft_substr(test.string, test.start, test.len);
		char	*exp = (char*)test.expect;
		if (strcmp(out, exp) != 0)
		{
			log_error("test %d: user: \"%s\", expected: \"%s\"", i, out, exp);
			failures++;
		}
		if (out)
			free(out);
	}
	
	return (failures);
}
