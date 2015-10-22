TARGET = ./test/all

TEST_DIR = ./test
GTEST_DIR = ./vendor/googletest

SOURCES = $(shell find $(TEST_DIR) -name '*.cc')
DEPENDS = $(SOURCES:.cc=.d)
OBJECTS = $(SOURCES:.cc=.o)

CPPFLAGS = -MMD -MP -I. -I$(GTEST_DIR) -I$(GTEST_DIR)/include
CXXFLAGS = -Wall -std=c++11 -O2
LDFLAGS = -lpthread

.PHONY: test clean

$(TARGET): $(OBJECTS) $(GTEST_DIR)/src/gtest-all.o $(GTEST_DIR)/src/gtest_main.o
	$(CXX) $(LDLIBS) $^ -o $@

test: $(TARGET)
	$(TARGET)

clean:
	$(RM) $(TARGET) $(shell find . -name '*.d' -o -name '*.o')

-include $(DEPENDS)
