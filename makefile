# Compiler
CC := g++
# CC := clang

SRCDIR := src
OBJDIR := obj

TARGET := game.out

STD := -std=c++14
DEBUG := -g
WARNINGS = -pedantic -Wall -Wextra
OPTIMIZE = -march=native -O3
SDL_LIBS = -lSDL_image 

SDL_COMP = $(shell sdl2-config --cflags)
SDL_LINK = $(shell sdl2-config --libs)

SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.cpp=.o))

CFLAGS = $(STD) $(DEBUG) $(WARNINGS) $(SDL_COMP)
LFLAGS = $(STD) $(WARNINGS) $(SDL_LINK) $(SDL_LIBS)

all: $(TARGET)
	@echo "Done"

$(TARGET): $(OBJECTS)
	@echo "Linking $< ..."
	$(CC) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(SDL_LINK)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $< ..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo cleaning
	find . -name \*.o -type f -delete
	-rm $(TARGET)
