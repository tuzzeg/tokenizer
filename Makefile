all: tokenizer

tokenizer.c: tokenizer.re
	re2c -o $@ $<

tokenizer: tokenizer.c
	gcc $< -o $@
