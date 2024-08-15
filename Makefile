CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=-L./lib -lutils

SRC=src
INC=-Iinclude

SOURCES=$(wildcard src/*.c)
OBJECTS=$(SOURCES:.c=.o)

TARGET=life_exe 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean 
	rm -f $(TARGET)

re: fclean all 

.PHONY: all clean fclean re
