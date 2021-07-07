define colorecho
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

CC       = gcc
CFLAGS   = -Wall -Wextra -mtune=native -g -std=c17
LDFLAGS  = 

.SUFFIXES:
.SUFFIXES: .c .o

srcdir	 =src/
BinDir	 =./
TARGETS	 = 8859ToUtf org

.PHONY: all
all: $(TARGETS)

8859ToUtf: 8859ToUtf.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

org: org.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true
