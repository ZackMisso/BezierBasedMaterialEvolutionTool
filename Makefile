CC=clang++
CFlags+= -std=c++11

FRAMS = -framework OpenGL -framework IOKit -framework CoreVideo -lglfw3
LIBS = $(FRAMS)

PROD = MultMat

SRCS= $(shell ls *.cpp)
SRCS+= $(shell ls unitTests/*.cpp)

OBJS= $(patsubst %.cpp, %.o, $(SRCS))

all: $(PROD)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

$(PROD): $(OBJS)
	$(CC) -o $(PROD) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f *.o
	rm -f unitTextx/*.o
