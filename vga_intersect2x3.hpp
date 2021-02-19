
/* Albino Bacolla
 MDACC
 Molecular & Cellular Oncology
 6767 Bertner Avenue
 Houston TX 77033
 abacolla@mdanderson.org
 May 2020
 vga_intersect2x3.hpp -- implementation of class GetIntersect
 */

#ifndef VGA_INTERSECT2x3_HPP
#define VGA_INTERSECT2x3_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

template<typename T>
struct read3C {
  T col1, col2, col3;
};

template<typename T>
class GetIntersect {
private:
  std::vector<std::pair<T, T>> vec1;
  std::vector<read3C<T>> vec2;

public:
  void readFiles(std::string const&, std::string const&);
  void sizeVec() const;
  void matchVec(std::string const&);
};

//////////////////////////////////

template<typename T>
void GetIntersect<T>::readFiles(std::string const& in1, std::string const& in2) {
  if (!vec1.empty()) {
    vec1.clear();
  }

  std::ifstream file1(in1);
  if (file1.is_open()) {
    T s1, s2;
    while (file1 >> s1 >> s2) {
      std::pair<T, T> p1(s1, s2);
      vec1.emplace_back(p1);
    }
  }
  else {
    std::cerr << "Could not open file " << in1 << '\n';
  }
  file1.close();

  if (!vec2.empty()) {
    vec2.clear();
  }

  std::ifstream file2(in2);
  if (file2.is_open()) {
    T s3, s4, s5;
    while (file2 >> s3 >> s4 >> s5) {
      read3C<T> cinp;
      cinp = {s3, s4, s5};
      vec2.emplace_back(cinp);
    }
  }
  else {
    std::cerr << "Could not open file " << in2 << '\n';
  }
  file2.close();
}

//////////////////////////////////

template<typename T>
void GetIntersect<T>::sizeVec() const {
  std::cout << "Size of file1 and file2 is: " << vec1.size() << '\t' << vec2.size() << '\n';
}

//////////////////////////////////

template<typename T>
void GetIntersect<T>::matchVec(std::string const& ou1) {
  std::ofstream file3 (ou1);
  if (file3.is_open()) {
    for (auto const& i : vec1) {
      for (auto const& j : vec2) {
        if (i.first == j.col1) {
          file3 << i.first << '\t' << i.second << '\t' << j.col1 << '\t' << j.col2 << '\t' << j.col3 << '\n';
        }
      }
    }
  }
  else {
    std::cerr << "Could not open file " << ou1 << '\n';
  }
  file3.close();
}

#endif // VGA_INTERSECT2x3_HPP
