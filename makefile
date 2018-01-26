# Compiler
CC := g++
DEBUG := -g

SRCDIR := src
OBJDIR := obj

TARGET := game

STD := -std=c++17
WARNINGS := -pedantic -Wall -Werror
OPTIMIZE := -march=native -O3
LIBS := SDL2

SDL_COMP := $(shell sdl2-config --cflags)
SDL_LINK := $(shell sdl2-config --libs)

SOURCES := $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

CFLAGS := $(STD++) $(DEBUG_FLAGS) $(WARNINGS) $(SDL_COMP) $(LIBS)
LFLAGS := $(STD++) $(WARNINGS) $(SDL_LINK) $(LIBS)

all: $(TARGET)
	@ echo "Done"

$(TARGET): $(OBJECTS)
	@ echo "Linking $< ..."
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $< ..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo cleaning
	find . -name \*.o -type f -delete
	- rm $(TARGET)
