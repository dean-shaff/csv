#include <stdio.h>
#include <vector>
#include "include/csv"

int main () {
  const char * file_name = "test_read.csv";
  std::vector<int> res = csv::read_from_csv(file_name);
  for (int i=0; i<res.size(); i++) {
    std::printf("idx: %i: %i", i, res[i]);
  }
}
