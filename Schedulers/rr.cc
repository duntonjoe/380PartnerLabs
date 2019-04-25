#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "Jobs.h"

int main(int argc, char *argv[]) {
  Jobs list;
  int time = 0;
  int maxtime;
  std::cin >> maxtime;
  auto collection = list.getJobs();
  while(collection.size() > 0){
    auto j = collection[0];
    if (j.time <= maxtime) {
      std::cout << time << ",+," << j.tag << std::endl << time << ",R," << j.tag << std::endl;
      time += j.time;
      std::cout << time << ",-," << j.tag << std::endl;
    }
    else {
      std::cout << time << ",R," << j.tag << std::endl;;
      time += maxtime;
      j.time -= maxtime;
      collection.push_back(j);
    }
    collection.erase(collection.begin());
  }
  return EXIT_SUCCESS;
}
