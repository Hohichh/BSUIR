#pragma once
#include <vector>
#include <string>

using namespace std;


struct Time {
	string hours_;
	string minutes_;
};

struct TimeInterval {
	Time from_;
	Time to_;
};

class Schedule {
private:
	
	const size_t maxDay_ = 7;
	vector<pair<const string, TimeInterval>>schedule = {
		{ "Monday", { Time{"--","--"}, Time{"--","--"} } },
		{ "Tuesday", { Time{"--","--"}, Time{"--","--"} } },
		{ "Wednesday", { Time{"--","--"}, Time{"--","--"} } },
		{ "Thursday", { Time{"--","--"}, Time{"--","--"} } },
		{ "Friday", { Time{"--","--"}, Time{"--","--"} } },
		{ "Saturday", { Time{"--","--"}, Time{"--","--"} } },
		{ "Sunday", { Time{"--","--"}, Time{"--","--"} } }
	};

	bool isValidTime(TimeInterval fromTo);
	bool isValidTime(Time time);
	string inputDayOfWeek(const string& dayWeek);
	Time inputTime(const Time& time);

public:
	Schedule();
	vector<pair<const string, TimeInterval>> getSchedule() const;
	void setSchedule(vector<TimeInterval>& schedule);

	void editSchedule(const string& dayWeek, const Time& startTime, const Time& endTime);
	void showSchedule() const;

	void operator=(const Schedule& other);

	bool operator==(const Schedule& other) const;
};