#ifndef JOBS_H
#define JOBS_H

#include <vector>


struct job {
	int time;
	int duration;
	int priority;
	int tag;
};



class Jobs
{
 	private:
		std::vector<job> jobList;
	public:
		Jobs();
		std::vector<job> getJobs();
};

#endif
