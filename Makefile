CC = clang++
CFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -lSDL2 -lstdc++fs

SRC = main.cpp #hello.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = createCProject

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
