CXX=g++
TARGET=Factory #最后生成的文件名字
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))#依赖

CXXFLAGS= -c -Wall #编译规则

# @代表TARGET,^代表所有的OBJ
$(TARGET):$(OBJ)
	$(CXX) -o $@ $^
	


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	
.PHONY: clean
clean:
	rm -f *.o $(TARGET)