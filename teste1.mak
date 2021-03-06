WORKDIR = %cd%

CC = gcc.exe
LD = g++.exe

INC = -Iinclude
CFLAGS = -fexpensive-optimizations -Os -O3 -Wfatal-errors -Wextra -Wall
LIBDIR = -Llib
LIB = -ltcc -lglfw3dll -lopengl32 freetype\\objs\\freetype.a
LDFLAGS = -s

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
OUT_DEBUG = bin\\Debug\\projetotcc.exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS)
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS)
OBJDIR_RELEASE = obj\\Release
OUT_RELEASE = bin\\Release\\projetotcc.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\teste1.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\teste1.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG) md $(OBJDIR_DEBUG)

debug: before_debug out_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)\\teste1.o: teste1.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c teste1.c -o $(OBJDIR_DEBUG)\\teste1.o

clean_debug: 
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)

before_release: 
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE) md $(OBJDIR_RELEASE)

release: before_release out_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)\\teste1.o: teste1.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c teste1.c -o $(OBJDIR_RELEASE)\\teste1.o

clean_release: 
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)

.PHONY: before_debug clean_debug before_release clean_release