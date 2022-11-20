TARGET := food
SRC := src
INC := inc
BIN := bin
TEXT := txt

SOURCE := $(wildcard $(SRC)/*.cpp)
OBJECT := $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.cpp=.o)))

CXX := g++
CXXFLAGS := -Wall -g -I$(INC)

$(BIN)/$(TARGET) : $(OBJECT)
	$(CXX) -o $@ $^

$(BIN)/%.o : $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
       
	rm -f $(OBJECT) $(BIN)/$(TARGET)


help :
       
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"

