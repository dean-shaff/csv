#include <stdio.h>
#include <vector>
#include <typeinfo>
#include "../include/csv.hpp"

using namespace std;

vector<double> init_1d_vec (double fill_val = 1.0) {
  vector<double> data(10);
  fill(data.begin(), data.end(), fill_val);
  return data;
}

vector<vector<double>> init_2d_vec () {
  vector<vector<double>> data(10);
  for (int i=0; i<data.size(); i++) {
    data[i] = init_1d_vec();
  }
  return data;
}

int main () {
  const char * file_name = "test_write.csv";
  const char * file_name_2d = "test_write_2d.csv";
  vector<double> data = init_1d_vec();
  vector<vector<double>> data_2d = init_2d_vec();
  csv::write_to_csv<double>(file_name, data);
  csv::write_to_csv<double>(file_name_2d, data_2d);
  return 0;
}
