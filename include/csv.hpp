
#ifndef CSV_H
#define CSV_H

#include <vector>
#include <fstream>

using namespace std;

namespace csv {

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

  template <typename T, typename A>
  vector<T, A> read_from_csv (const char * file_name) {
  	vector<T, A> vec;
  	ifstream f;
  	f.open(file_name);
  	char current_char ;
  	while (! f.eof()) {
  		f >> current_char;
  	}
  	f.close();
  	return vec;
  }
}

#endif
