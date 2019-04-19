#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "Jobs.cpp"

int main(int argc, char *argv[]) {
  Jobs list;
  int time = 0;
  for(job j : list.getJobs()){
    std::cout << time << ",+," << j.tag << std::endl << time << ",R," << j.tag << std::endl;
    time += j.time;
    std::cout << time << ",-," << j.tag << std::endl;
  }
  return EXIT_SUCCESS;
}
