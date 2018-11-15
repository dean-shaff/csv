#include <stdio.h>
#include <vector>
#include "../include/csv.hpp"

using namespace std;

int main () {
  const char * file_name = "test_read.csv";
  vector<vector<string>> res;
  csv::read_from_csv(file_name, res);
  vector<vector<string>> res1 = csv::read_from_csv(file_name);
  printf("res.size(): %i\n", res.size());
  if (res.size() > 0) {
    printf("res[0].size(): %i\n", res[0].size());
  }
  for (int i=0; i<res.size(); i++) {
    for (int j=0; j<res[i].size(); j++) {
      printf("%s ", res[i][j].c_str());
    }
    printf("\n");
  }
}
