#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char* s;
  char* pos;
  size_t len;
} Scaner;

typedef struct {
  char* start;
  char* end;
  unsigned int type;
} Token;

int next(
  /* IN, OUT */ Scaner* scaner,
  /*     OUT */ Token* token)
{
  if (scaner-> len <= scaner->pos - scaner->s)
    return 0;

  char *end = scaner->s + scaner->len;
  char *q = 0;

#define YYCTYPE         char
#define YYCURSOR        (scaner->pos)
#define YYLIMIT         end
#define YYMARKER        q
#define YYFILL(n)
        
  char* start = scaner->pos;

/*!re2c
  re2c:indent:top = 2;
  [a-zA-Z]+    { token->start = start; token->end = scaner->pos; token->type = 1; return 1; }
  [0-9]+       { token->start = start; token->end = scaner->pos; token->type = 2; return 1; }
  [.,;:]+      { token->start = start; token->end = scaner->pos; token->type = 3; return 1; }
  [^]          { token->start = start; token->end = scaner->pos; token->type = 5; return 1; }
*/
}

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    Scaner scaner;
    scaner.s = argv[1];
    scaner.pos = scaner.s;
    scaner.len = strlen(scaner.s);
    Token token;
    while (0 < next(&scaner, &token))
    {
      printf("Tok (%lu, %lu) %d\n", token.start-scaner.s, token.end - scaner.s, token.type);
    }
  }
  else
  {
    fprintf(stderr, "%s <expr>\n", argv[0]);
    return 1;
  }
}
