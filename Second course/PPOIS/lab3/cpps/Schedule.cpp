#include "Schedule.h"
#include "iostream"

using namespace std;

bool Schedule::isValidTime(TimeInterval fromTo) {
	return ((stoi(fromTo.from_.hours_) >= 0 && stoi(fromTo.from_.hours_) <= 23) &&
		(stoi(fromTo.from_.minutes_) >= 0 && stoi(fromTo.from_.minutes_) <= 59) &&
		(stoi(fromTo.to_.hours_) >= 0 && stoi(fromTo.to_.hours_) <= 23) &&
		(stoi(fromTo.to_.minutes_) >= 0 && stoi(fromTo.to_.minutes_) <= 59)
		);
}

bool Schedule::isValidTime(Time time) {
	return ((stoi(time.hours_) >= 0 && stoi(time.hours_) <= 23) &&
		(stoi(time.minutes_) >= 0 && stoi(time.minutes_) <= 59) 
		);
}

Schedule::Schedule() = default;


vector<pair<const string, TimeInterval>> Schedule::getSchedule() const{
	return schedule;
}
void Schedule::setSchedule(vector<TimeInterval>& timeInterval){
	for (int i = 0; i < maxDay_; i++) {
		if (isValidTime(timeInterval[i])) {
			schedule[i].second = timeInterval[i];
		}
	}
}



void Schedule::editSchedule(const string& dayWeek, const Time& startTime, const Time& endTime) {
	string chooseDay;
	char cont;
		chooseDay = inputDayOfWeek(dayWeek);
		TimeInterval interval;
		interval.from_ = inputTime(startTime);
		interval.to_ = inputTime(endTime);

		schedule[stoi(chooseDay) - 1].second = interval;
}

void Schedule::showSchedule() const{
	for (int i = 0; i < schedule.size(); i++) {
		cout << "\n" << schedule[i].first << ". " << schedule[i].second.from_.hours_ << ":" <<
			schedule[i].second.from_.minutes_ << " -- " << schedule[i].second.to_.hours_ << ":" <<
			schedule[i].second.to_.minutes_ << "\n";
	}
}

void Schedule::operator=(const Schedule& other) {
	for (int i = 0; i < schedule.size(); i++) {
		schedule.at(i).second.from_.hours_ = other.schedule.at(i).second.from_.hours_;
		schedule.at(i).second.from_.minutes_ = other.schedule.at(i).second.from_.minutes_;
		schedule.at(i).second.to_.hours_ = other.schedule.at(i).second.to_.hours_;
		schedule.at(i).second.to_.minutes_ = other.schedule.at(i).second.to_.minutes_;

	}
}


bool Schedule::operator==(const Schedule& other) const{
	if (schedule.size() != other.schedule.size()) {
		return false;
	}

	for (size_t i = 0; i < schedule.size(); ++i) {
		if (schedule[i].first != other.schedule[i].first ||
			schedule[i].second.from_.hours_ != other.schedule[i].second.from_.hours_ ||
			schedule[i].second.from_.minutes_ != other.schedule[i].second.from_.minutes_ ||
			schedule[i].second.to_.hours_ != other.schedule[i].second.to_.hours_ ||
			schedule[i].second.to_.minutes_ != other.schedule[i].second.to_.minutes_) {
			return false;
		}
	}

	return true;
}


string Schedule::inputDayOfWeek(const string& dayWeek) {
	while (true) {
		try {
			if (stoi(dayWeek) < 0 || stoi(dayWeek) > 7) {
				throw invalid_argument("There is no such day of the week. Input a day from 1 to 7");
			}
			break;
		}
		catch (invalid_argument& arg) {
			cout << "\n" << arg.what() << "\n";
		}
	}
	return dayWeek;
}

Time Schedule::inputTime(const Time& time) {
	while (true) {
		try {
			if (!isValidTime(time)) {
				throw invalid_argument("Invalid time input. Input time in 24h format(exmpl: 23:59)");
			}
			return time;
		}
		catch (invalid_argument& arg) {
			cout << "\n" << arg.what() << "\n";
		}
	}
}