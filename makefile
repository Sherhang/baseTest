CXX = g++ -std=c++11
src = $(wildcard *.cpp)
head = $(wildcard *.h)
obj = $(src:%.cpp=%.o) #get all .h with the same name of .cpp 
target = $(patsubst %.cpp, %, $(src)) #similar with the above，use this mostly 

INCS = 
LIBS =  -lpthread -ldl

CFLAGS += -g 

all:$(target)

$(target):%:%.cpp   	#用模式规则对每个独立的目标进行编译
	$(CXX) $(INCS) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp  head
	$(CXX) $(INCS) $(CFLAGS) -c $^ -o $@ $(LIBS)

.PHONY:all clean
clean:
	@echo "clean all .o and exe: "
	rm -rf  $(obj) $(target) log/
