CC=g++
CFLAGS= -std=c++11
INCLUDES= -I include/
write_obj=test/test_write.cpp
read_obj=test/test_read.cpp
csv_obj=src/csv.cpp

test_read: $(read_obj)
	$(CC) $(CFLAGS) -o $@ $^

test_write: $(write_obj)
	$(CC) $(CFLAGS) -o $@ $^
