# Makefile para compilar o código dos escalonadores de processos

CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm
SRC_DIR = src

# Lista dos arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Lista dos arquivos objeto gerados
OBJS = $(SRCS:.c=.o)

# Nome do executável
EXECUTABLE = escalonador_de_processos

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXECUTABLE) $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BIN_DIR)/$(EXECUTABLE)

.PHONY: all clean