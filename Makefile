WRKDIR = %cd%
MAKE = make

all: freetype_freetype tcc teste1

freetype_freetype:
	$(MAKE) -C freetype all -f Makefile

tcc:
	$(MAKE) all -f tcc.mak

teste1:
	$(MAKE) all -f teste1.mak

clean: clean_freetype_freetype clean_tcc clean_teste1

clean_freetype_freetype:
	$(MAKE) -C freetype clean -f Makefile

clean_tcc:
	$(MAKE) clean -f tcc.mak

clean_teste1:
	$(MAKE) clean -f teste1.mak

.PHONY: clean_freetype_freetype clean_tcc clean_teste1