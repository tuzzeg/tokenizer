import tokenizer
import unittest

def toks(s):
  return ' '.join(['%d[%s]' % (typ, tok) for typ, tok in tokenizer.tokenize(s)])

class TokenizerTest(unittest.TestCase):
  def test_simple(self):
    self.assertEquals('', toks(''))
    self.assertEquals('1[wOrd]', toks('wOrd'))
    self.assertEquals('2[012]', toks('012'))
    self.assertEquals('259[ ]', toks(' '))
    self.assertEquals('259[   ]', toks('   '))
    self.assertEquals('515[,.]', toks(',.'))
    self.assertEquals('3[!@] 259[ ] 3[@]', toks('!@ @'))

    self.assertEquals('1[A] 259[ ] 4[bit.ly/xxCFd0] 259[ ] 1[link]', toks('A bit.ly/xxCFd0 link'))
    self.assertEquals('3[!@] 259[ ] 3[@]', toks('!@ @'))

    self.assertEquals('1[A] 259[ ] 1[simple] 259[ ] 1[test]', toks('A simple test'))
    self.assertEquals('1[A] 259[ ] 1[simple] 259[ ] 1[test] 515[.]', toks('A simple test.'))

  def test_obfuscated(self):
    self.assertEquals('257[f$%k]', toks('f$%k'))
    self.assertEquals('1[s] 515[?]', toks('s?'))
    self.assertEquals('257[ro$$ney]', toks('ro$$ney'))

if __name__ == '__main__':
  unittest.main()
