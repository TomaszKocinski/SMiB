#pragma once
#include<vector>
#include<map>

typedef std::vector<int> QueueVector;
typedef std::vector<std::vector<int>> ChannelsVector;
typedef std::multimap<double, int> TimesVector;
typedef std::vector<int> PerTimeUnitVector;

class Report
{
	int T;
	QueueVector queue;
	ChannelsVector channels;
	TimesVector times;
	TimesVector dismissedTimes;
public:
	Report(int);
	~Report();

	void addTime(std::pair<double, int>, bool = false);
	void addQueueValue(int);
	void addChannelsValues(std::vector<int>);

	void saveData(std::ostream&) const;
	void saveDismissed(std::ostream&) const;
	void saveDismissedPerTimeUnit(std::ostream&) const;
	void saveCallsPerTimeUnit(std::ostream&, std::ostream&) const;
};
