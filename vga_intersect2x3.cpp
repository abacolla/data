
/* Albino Bacolla
 MDACC
 Molecular & Cellular Oncology
 6767 Bertner Avenue
 Houston TX 77033
 abacolla@mdanderson.org
 May 2020
 vga_intersect2x3.cpp -- intersect file1 with 2 cols with file2 with 3 cols using col1
*/

#include <iostream>
#include "vga_intersect2x3.hpp"
#include <string>

int main(int argc, char* argv[]) {

  if (argc != 4) {
    std::cout << "\nSynopsis: intersect file1 with 2 cols with file 2 with 3 cols using col1\n"
              << "Usage: vga_intersect2x3 file1 file2 file3\n"
	      << "Note: file1 = 2-cols with field 1 in common; file2 = 3-cols with field 1 in common; file3 = output\n"
	      << "Example: vga_intersect2x3 file1 file2 file3\n\n";

	return 0;
  }

    GetIntersect<std::string> obj;
    obj.readFiles(argv[1], argv[2]);
    obj.sizeVec();
    obj.matchVec(argv[3]);

  return 0;
}

