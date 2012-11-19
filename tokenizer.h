#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

typedef struct {
  char* s;
  char* pos;
  size_t len;
} Scaner;

typedef struct {
  unsigned int type;
  char* start;
  size_t len;
} Token;

// Read input string, set found token in token struc and return count of consumed tokens (0 if end of string reached).
int next(
  /* IN, OUT */ Scaner* scaner,
  /*     OUT */ Token* token);

void Scaner_init(
  /* IN, OUT */ Scaner* scaner,
  /* IN      */ char* _s);


#endif
