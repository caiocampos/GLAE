WORKDIR = %cd%

CC = gcc.exe
AR = ar.exe
WINDRES = windres.exe

INC = -Iinclude
CFLAGS = -Wfatal-errors -Wextra -Wall
LIBDIR = -Llib

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -fexpensive-optimizations -Os -O3
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj
OUT_RELEASE = lib\\libglae.a

OBJ_RELEASE = $(OBJDIR_RELEASE)\\src\\extra.o $(OBJDIR_RELEASE)\\src\\forma.o $(OBJDIR_RELEASE)\\src\\janela.o $(OBJDIR_RELEASE)\\src\\tinycthread.o

all: release

clean: clean_release

before_release: 
	cmd /c if not exist lib md lib
	cmd /c if not exist $(OBJDIR_RELEASE)\\src md $(OBJDIR_RELEASE)\\src

release: before_release out_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(AR) rcs $(OUT_RELEASE) $(OBJ_RELEASE)

$(OBJDIR_RELEASE)\\src\\extra.o: src\\extra.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\extra.c -o $(OBJDIR_RELEASE)\\src\\extra.o

$(OBJDIR_RELEASE)\\src\\forma.o: src\\forma.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\forma.c -o $(OBJDIR_RELEASE)\\src\\forma.o

$(OBJDIR_RELEASE)\\src\\janela.o: src\\janela.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\janela.c -o $(OBJDIR_RELEASE)\\src\\janela.o

$(OBJDIR_RELEASE)\\src\\tinycthread.o: src\\tinycthread.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\tinycthread.c -o $(OBJDIR_RELEASE)\\src\\tinycthread.o

clean_release: 
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd lib
	cmd /c rd $(OBJDIR_RELEASE)\\src

.PHONY: before_release clean_release