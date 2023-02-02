src=$(wildcard ./*.cpp)
obj=$(patsubst %.cpp, %.o,$(src))
app:$(obj)
	$(CXX) $^ -o $@

%.o:%.cpp
	$(CXX) -c $< -o $@

.PHONY:clean
clean:
	rm *.o
  
