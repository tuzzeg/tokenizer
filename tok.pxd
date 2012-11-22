cdef extern from "tokenizer.h":
  ctypedef enum TokenType:
    WORD   = 0x0001
    WORD_F = 0x0101

    NUM    = 0x0002

    SPEC       = 0x0003
    SPEC_SP    = 0x0103
    SPEC_PUNCT = 0x0203

    URL    = 0x0004

    OTHER  = 0x0005

  ctypedef struct Scanner:
    pass

  ctypedef struct Token:
    TokenType type
    char* start
    Py_ssize_t len

  void Scanner_init(Scanner* scanner, char* s)
  int next(Scanner* scanner, Token* token)
