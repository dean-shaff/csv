#include <stdio.h>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <string>
#include "../include/csv.hpp"

using namespace std;

int main () {
  const char * file_name = "test_read.csv";
  vector<vector<float>> res;
  csv::read_from_csv<float>(file_name, res);
  for (int i=0; i<res.size(); i++) {
    for (int j=0; j<res[i].size(); j++) {
      printf("%.1f ", res[i][j]);
    }
    printf("\n");
  }
}
