/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:47:01 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 16:50:32 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LOG_H
#define TEST_LOG_H
#include <stdio.h>

#define ANSI_ESC "\x1b"
#define COLOR_RESET ANSI_ESC"[0m"
#define COLOR_RED ANSI_ESC"[38;5;1m"
#define COLOR_GREEN ANSI_ESC"[38;5;2m"
#define COLOR_YELLOW ANSI_ESC"[38;5;3m"
#define COLOR_BLUE ANSI_ESC"[38;5;4m"

#define MSG_ERR COLOR_RED"ERROR"COLOR_RESET
#define MSG_OK COLOR_GREEN"OK"COLOR_RESET
#define MSG_WARN COLOR_YELLOW"WARNING"COLOR_RESET
#define MSG_INFO COLOR_BLUE"INFO"COLOR_RESET

#define log_error(X, ...) fprintf(stderr, MSG_ERR" :: "X"\n", ##__VA_ARGS__)
#define log_success(X, ...) fprintf(stdout, MSG_OK" :: "X"\n", ##__VA_ARGS__)
#define log_warning(X, ...) fprintf(stdout, MSG_WARN" :: "X"\n", ##__VA_ARGS__)
#define log_info(X, ...) fprintf(stdout, MSG_INFO" :: "X"\n", ##__VA_ARGS__)
#define log_separator() fprintf(stdout, "================================================================\n");

#define SYMBOL_HBAR ((char)175)
#define SYMBOL_VBAR ((char)124)

#define INDENT_HBAR "――――"
#endif

