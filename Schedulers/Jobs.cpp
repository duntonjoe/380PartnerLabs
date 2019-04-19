#include <stdio.h>
#include <vector>

// Struct that represents all the data of the job
typedef struct {
  int time;
  int duration;
  int priority;
  int tag;
} job;

// Class structure
class Jobs {
  private:
    std::vector<job> jobList;
  public:
    Jobs();
    std::vector<job> getJobs();
};

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
