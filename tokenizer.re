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
  if (scaner->len <= scaner->pos - scaner->s)
    return 0;

  // char *end = scaner->s + scaner->len;
  char *q = 0;

#define YYCTYPE         char
#define YYCURSOR        (scaner->pos)
#define YYLIMIT         end+2
#define YYMARKER        q
#define YYFILL(n)       { if (end+2 <= scaner->pos) return 0; }
        
  char* start = scaner->pos;

/*!re2c
  re2c:indent:top = 2;
  re2c:yyfill:enable = 0;
  
  /* common character classes */
  BLANK = [ \t];
  DIGIT = [0-9];
  ALPHA = [a-zA-Z];
  ALNUM = [a-zA-Z0-9];
  PRINT = [\040-\176];
  GRAPH = PRINT\BLANK;
  PUNCT = [!?.,;"'(){}<>\[\]`];

  /* basic tokens */
  WORD = ALPHA+;
  NUM  = DIGIT+;
  SPEC = (GRAPH\ALNUM)+;
  SPEC_SP = BLANK+;
  SPEC_PUNCT = PUNCT+;

  /* URLs */
  URL_NON_PAREN = GRAPH\[()<>];
  URL_BALANCED_PAREN = '('(URL_NON_PAREN+|('('URL_NON_PAREN+')'))*')';
  URL_PROTO = ALPHA(ALPHA|'-')+':';
  URL_DOMAIN_WWW = "www"DIGIT{0,3}'.';
  URL_DOMAIN_OTHER = (ALNUM|'.'|'-')+'.'ALPHA{2,4}'/';
  URL_DOMAIN = (URL_PROTO ('/'{1,3}|(ALNUM|'%'))) | URL_DOMAIN_WWW | URL_DOMAIN_OTHER;
  URL_END_CHAR = GRAPH\PUNCT;
  URL_AFTER_DOMAIN = (URL_NON_PAREN+|URL_BALANCED_PAREN)+(URL_BALANCED_PAREN|URL_END_CHAR);
  URL = URL_DOMAIN URL_AFTER_DOMAIN;

  /* words like f#@k */
  FSPEC = [!@#$%^&*?~];
  FWORD = ALPHA (FSPEC|ALPHA)* FSPEC (FSPEC|ALPHA)* ALPHA;

  /* final rules */
  WORD  { Token_set(token, start, scaner->pos, WORD); return 1; }
  FWORD { Token_set(token, start, scaner->pos, WORD_F); return 1; }
  NUM   { Token_set(token, start, scaner->pos, NUM); return 1; }
  URL   { Token_set(token, start, scaner->pos, URL); return 1; }
  SPEC_SP    { Token_set(token, start, scaner->pos, SPEC_SP); return 1; }
  SPEC_PUNCT { Token_set(token, start, scaner->pos, SPEC_PUNCT); return 1; }
  SPEC       { Token_set(token, start, scaner->pos, SPEC); return 1; }

  /* all other */
  [^]   { Token_set(token, start, scaner->pos, OTHER); return 1; }
*/
}
