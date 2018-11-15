#include <stdio.h>
#include <map>
#include <function>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <string>
#include "../include/csv.hpp"

using namespace std;



template<typename T>
void check_typeid () {



  map<type_index, string> type_to_str = {
    {typeid(int), "int"},
    {typeid(float), "float"},
    {typeid(double), "double"}
  };
  string type_name = type_to_str[typeid(T)];
  printf("%s\n", type_name.c_str());
}


int main () {
  const char * file_name = "test_read.csv";
  vector<vector<string>> res;
  csv::read_from_csv(file_name, res);
  vector<vector<string>> res1 = csv::read_from_csv(file_name);
  // printf("res.size(): %i\n", res.size());
  // if (res.size() > 0) {
  //   printf("res[0].size(): %i\n", res[0].size());
  // }
  for (int i=0; i<res.size(); i++) {
    for (int j=0; j<res[i].size(); j++) {
      printf("%s ", res[i][j].c_str());
    }
    printf("\n");
  }
  check_typeid<int>();
}
