#include <stdio.h>
#include <vector>

// Constructor boi
Jobs::Jobs() {
  job added;
  while(scanf("%d,%d,%d,%d", &added.time, &added.duration, &added.priority, &added.tag) == 4)
    jobList.push_back(added);
}

// Returns the vector of jobs
std::vector<job> Jobs::getJobs(){
  return jobList;
}
