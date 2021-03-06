/************************************************************
yyamsusz.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yymsetunputsize(yymlexer_t YYFAR *yy, int size)
#else
YYEXPFUNC(YYBOOL) YYCDECL yymsetunputsize(yy, size)
yymlexer_t YYFAR *yy;
int size;
#endif
{
	yyassert(yy != NULL);
	yyassert(size >= 0);
	if (yy->yymunput_size != size) {
		int YYFAR *unputbufptr;

		size_t unputbufcharsize;

		if (size < yy->yymunputindex) {
			return YYFALSE;
		}

		if (yy->yymunput_max != 0) {
			if (size > yy->yymunput_max) {
				return YYFALSE;
			}
		}

		unputbufcharsize = size * sizeof(int);
		if ((int) (unputbufcharsize / sizeof(int)) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yy->yymsunput_size) {
			unputbufptr = yy->yymsunputbufptr;
		}
		else {
			unputbufptr = (int YYFAR *) malloc(unputbufcharsize);
			if (unputbufptr == NULL) {
				return YYFALSE;
			}
		}

		/* copy */
		if (unputbufptr != yy->yymunputbufptr) {
			size_t charsize = yy->yymunput_size * sizeof(int);
			memcpy(unputbufptr, yy->yymunputbufptr, yymin(unputbufcharsize, charsize));
		}

		/* free */
		if (yy->yymunputbufptr != yy->yymsunputbufptr) {
			free(yy->yymunputbufptr);
		}

		/* assign */
		yy->yymunputbufptr = unputbufptr;
		yy->yymunput_size = size;
	}
	return YYTRUE;
}

_YL_END
