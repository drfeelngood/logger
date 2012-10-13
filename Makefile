# Logger Makefile

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

CC=gcc
CFLAGS= -Wall -g
WARNINGS= -Wall -W -Wstrict-prototypes -Wwrite-strings
DEBUG?= -g -ggdb

MAJOR_VERSION := $(shell cat VERSION |cut -d\. -f1)
MINOR_VERSION := $(shell cat VERSION |cut -d\. -f2)

LIBNAME=liblogger
DYLIBSUFFIX=so
DYLIB_MINOR_NAME=$(LIBNAME).$(MAJOR_VERSION).$(MINOR_VERSION).$(DYLIBSUFFIX)
DYLIB_MAJOR_NAME=$(LIBNAME).$(MAJOR_VERSION).$(DYLIBSUFFIX)
DYLIBNAME=$(LIBNAME).$(DYLIBSUFFIX)
DYLIB_MAKE_CMD=$(CC) -shared -Wl,-soname,$(DYLIB_MINOR_NAME) -o $(DYLIBNAME) $(LDFLAGS)

ifeq ($(uname_S),Darwin)
	DYLIBSUFFIX=dylib
	DYLIB_MINOR_NAME=$(LIBNAME).$(MAJOR_VERSION).$(MINOR_VERSION).$(DYLIBSUFFIX)
	DYLIB_MAJOR_NAME=$(LIBNAME).$(MAJOR_VERSION).$(DYLIBSUFFIX)
	DYLIB_MAKE_CMD=$(CC) -shared -Wl,-install_name,$(DYLIB_MINOR_NAME) -o $(DYLIBNAME) $(LDFLAGS)
endif

SRC=logger.c
OBJ=$(SRC:.c=.o)

PREFIX?=/usr/local
INSTALL_LIB_PATH=$(PREFIX)/lib
INSTALL_INCLUDE_PATH=$(PREFIX)/include

INSTALL?= cp -a


all: $(DYLIBNAME)
    
$(DYLIBNAME): $(OBJ)
	$(DYLIB_MAKE_CMD) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

install: $(DYLIBNAME)
	mkdir -p $(INSTALL_INCLUDE_PATH) $(INSTALL_LIB_PATH)
	$(INSTALL) logger.h 	$(INSTALL_INCLUDE_PATH)
	$(INSTALL) $(DYLIBNAME) $(INSTALL_LIB_PATH)/$(DYLIB_MINOR_NAME)	
	cd $(INSTALL_LIB_PATH) && ln -sf $(DYLIB_MAJOR_NAME) $(DYLIB_MAJOR_NAME)
	cd $(INSTALL_LIB_PATH) && ln -sf $(DYLIB_MINOR_NAME) $(DYLIBNAME)

clean:
	rm -f $(DYLIBNAME) $(OBJ)
