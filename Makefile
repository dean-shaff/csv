CC=g++
CFLAGS=-std=c++11
INCLUDES=include/csv.hpp

CSV_OBJ=csv.o
STATIC_LIB=libcsv.a
BUILD_DIR=build

TEST_WRITE=test_write
TEST_READ=test_read

# .PHONY: directories

all: directories $(CSV_OBJ) $(STATIC_LIB)

$(CSV_OBJ): $(INCLUDES)
	$(CC) $(CFLAGS) -c $^ -o $(BUILD_DIR)/$@

$(STATIC_LIB): $(CSV_OBJ)
	ar -cvq $(BUILD_DIR)/$@ $(BUILD_DIR)/$^

directories:
	mkdir -p $(BUILD_DIR)

test: $(TEST_WRITE) $(TEST_READ)

$(TEST_READ): test/$(TEST_READ).cpp
	$(CC) $(CFLAGS) -o test/$@ $^

$(TEST_WRITE): test/$(TEST_WRITE).cpp
	$(CC) $(CFLAGS) -o test/$@ $^

clean:
	rm $(CSV_OBJ) $(STATIC_LIB)
