cdef extern from "tokenizer.h":
  ctypedef struct Scanner:
    pass

  ctypedef struct Token:
    unsigned int type
    char* start
    Py_ssize_t len

  void Scanner_init(Scanner* scanner, char* s)
  int next(Scanner* scanner, Token* token)
