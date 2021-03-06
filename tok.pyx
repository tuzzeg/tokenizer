from tok cimport Scanner, Token, Scanner_init, next
cimport tok

WORD = tok.WORD
WORD_F = tok.WORD_F
NUM = tok.NUM
SPEC = tok.SPEC
URL = tok.URL
OTHER = tok.OTHER

def tokenize(_s):
  cdef char* s = _s
  cdef Scanner scanner
  Scanner_init(&scanner, s)

  cdef Token token
  cdef bytes tok
  while 0 < next(&scanner, &token):
    tok = token.start[:token.len]
    yield (token.type, tok)
