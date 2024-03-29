/*
 * Copyright (c) 2017, Michel Martens <mail at soveran dot com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>

static int skip(void) {
	int c;

	while((c = getchar())) {
		switch (c) {
		case EOF:
			return 1;
		case '\n':
			putchar(c);
			return 0;
		default:
			putchar(c);
		}
	}

	return 0;
}

int main(int argc, char **argv) {
	int c;
	int l = 0;
	int f = -1;

	char *prefix;

	if (argc == 2) {
		prefix = argv[1];
	} else {
		prefix = "#";
	}

	while((c = getchar()) != EOF) {
		switch (c) {
		case '\n':
			putchar(c);
			l = 0;
			break;
		case ' ':
		case '\t':
			if (l == f) {
				l = 0;

				printf("%s ", prefix);
				putchar(c);

				if (skip()) return 0;
			} else {
				l++;
				putchar(c);
			}

			break;

		default:
			if (f == -1) { f = l; }

			l = 0;

			printf("%s ", prefix);
			putchar(c);

			if (skip()) return 0;
		}
	}

	return 0;
}
