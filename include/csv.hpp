
#ifndef CSV_H
#define CSV_H

#include <stdio.h>
#include <map>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

namespace csv {

  template<typename T>
  void str_to_number (string str, T &val) {
    if (typeid(T) == typeid(int)) {
      val = stoi(str);
    } else if (typeid(T) == typeid(long)) {
      val = stol(str);
    } else if (typeid(T) == typeid(long long)) {
      val = stoll(str);
    } else if (typeid(T) == typeid(float)) {
      val = stof(str);
    } else if (typeid(T) == typeid(double)) {
      val = stod(str);
    } else {
      cout << typeid(T).name() << " not currently supported" << endl;
    }
  }

  template <typename T>
  void write_arr_to_file (ofstream& f, T *arr, int arr_size) {
  	if (f.is_open()){
  		for (int i=0; i<arr_size-1; i++){
  			f << to_string(arr[i]);
  			f << ",";
  		}
  		f << to_string(arr[arr_size-1]);
  	} else {
  		printf("file not open!\n");
  	}
  }

  template <typename T>
  void write_row (ofstream& f, T *arr, int arr_size) {
    write_arr_to_file(f, arr, arr_size);
    f << '\n';
  }

  template <typename T>
  void write_to_csv (const char * file_name, T * arr, int arr_size) {
  	ofstream f;
  	f.open(file_name);
  	csv::write_arr_to_file<T>(f, arr, arr_size);
  	f.close();
  }

  template <typename T, typename A>
  void write_to_csv (const char * file_name, vector<T, A> vec) {
  	csv::write_to_csv<T>(file_name, &vec[0], vec.size());
  }

  template <typename T, typename A>
  void write_to_csv (const char * file_name, vector<vector<T, A>> vec) {
  	ofstream f;
  	f.open(file_name);
  	for (int i=0; i<vec.size(); i++) {
  		csv::write_arr_to_file<T>(f, &vec[i][0], vec[i].size());
  		f << "\n";
  	}
  	f.close();
  }

  template <typename T>
  bool read_row (ifstream& f, vector<T> &vec) {
    T temp_var;
    string temp_str;
    string line;
    if (getline(f, line)) {
      for (int i=0; i<line.size(); i++) {
        if (line.at(i) == ',') {
          csv::str_to_number<T>(temp_str, temp_var);
          // we don't need to copy the value of `temp_var`
          // because push_back does it for us!
          vec.push_back(temp_var);
          temp_str.clear();
        } else {
          temp_str.push_back(line.at(i));
        }
      }
      return true;
    } else {
      return false;
    }
  }


  template<typename T>
  void read_from_csv (const char * file_name, vector<vector<T>> &vec) {
  	ifstream f;
  	f.open(file_name);
    vector<T> line_vec;
  	while (csv::read_row<T>(f, line_vec)) {
      vec.push_back(line_vec);
      line_vec.clear();
  	}
  	f.close();
  }
}

#endif
