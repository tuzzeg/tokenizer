#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

typedef enum {
  WORD   = 0x0001,
  WORD_F = 0x0101,

  NUM    = 0x0002,

  SPEC   = 0x0003,

  URL    = 0x0004,

  OTHER  = 0x0005

} TokenType;


typedef struct {
  char* s;
  char* pos;
  size_t len;
} Scanner;

typedef struct {
  TokenType type;
  char* start;
  size_t len;
} Token;

// Read input string, set found token in token struc and return count of consumed tokens (0 if end of string reached).
int next(
  /* IN, OUT */ Scanner* scaner,
  /*     OUT */ Token* token);

void Scanner_init(
  /* IN, OUT */ Scanner* scaner,
  /* IN      */ char* _s);


#endif
