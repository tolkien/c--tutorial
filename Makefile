CXX = clang++
CXXFLAGS += -std=c++11

all:

clean:
	@rm -f *~ a.out
	@find . -type f -perm -a+x -exec rm -f {} \;
