from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("tokenizer", ["tok.pyx", "tokenizer.c"])]

setup(
  name = 'Tokenizer',
  cmdclass = {'build_ext': build_ext},
  ext_modules = ext_modules
)
