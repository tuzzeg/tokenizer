#include <string.h>

#include "tokenizer.h"

void Scanner_init(Scanner* scaner, char* s) {
  scaner->s = s;
  scaner->pos = s;
  scaner->len = strlen(s);
}

void Token_set(Token* token, char* start, char* end, unsigned int type) {
  token->start = start;
  token->len = end - start;
  token->type = type;
}

int next(
  /* IN, OUT */ Scanner* scaner,
  /*     OUT */ Token* token)
{
  if (scaner-> len <= scaner->pos - scaner->s)
    return 0;

  char *end = scaner->s + scaner->len;
  // char *q = 0;

#define YYCTYPE         char
#define YYCURSOR        (scaner->pos)
#define YYLIMIT         end
#define YYMARKER        q
#define YYFILL(n)
        
  char* start = scaner->pos;

/*!re2c
  re2c:indent:top = 2;
  [a-zA-Z]+    { Token_set(token, start, scaner->pos, 1); return 1; }
  [0-9]+       { Token_set(token, start, scaner->pos, 2); return 1; }
  [.,;:]+      { Token_set(token, start, scaner->pos, 3); return 1; }
  [^]          { Token_set(token, start, scaner->pos, 4); return 1; }
*/
}
