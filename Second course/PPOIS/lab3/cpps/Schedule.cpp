#include "Schedule.h"
#include "iostream"

using namespace std;

bool Schedule::isValidTime(TimeInterval fromTo) {
	if ((stoi(fromTo.from_.hours_) >= 0 && stoi(fromTo.from_.hours_) <= 23) &&
		(stoi(fromTo.from_.minutes_) >= 0 && stoi(fromTo.from_.hours_) <= 59) &&
		(stoi(fromTo.to_.hours_) >= 0 && stoi(fromTo.to_.hours_) <= 23) &&
		(stoi(fromTo.to_.minutes_) >= 0 && stoi(fromTo.to_.hours_) <= 59)
		) return true;
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

void Schedule::editSchedule(){
	string chooseDay;
	char cont;
	do {
		cout << "\nChoose a day of the week(1 - 7): ";
		while (true) {
			try {
				getline(cin, chooseDay);
				if (stoi(chooseDay) < 0 || stoi(chooseDay) > 7) {
					throw invalid_argument("There is no such day of the week. Input a day from 1 to 7");
				}
				break;
			}
			catch (invalid_argument& arg) {
				cout << "\n" << arg.what() << "\n";
			}
		}
		string hrs = "00";
		string mins = "00";
		TimeInterval interval{ {hrs,mins}, {hrs,mins} };

		cout << "\nInput start time(24h format):\n";
		while (true) {
			try{
				cout << "\nhours: ";
				getline(cin, hrs);
				cout << "\nminutes: ";
				getline(cin, mins);
				Time time{ hrs,mins };
				interval.from_ = time;
				if (!isValidTime(interval)) {
					throw invalid_argument("Invalid time input. Input time in 24h format(exmpl: 23:59)");
				}
				break;
			}
			catch (invalid_argument& arg) {
				cout << "\n" << arg.what() << "\n";
				}
		}

		cout << "\nInput end time(24h format):\n";
		while (true) {
			try {
				cout << "\nhours: ";
				getline(cin, hrs);
				cout << "\nminutes: ";
				getline(cin, mins);
				Time time{ hrs,mins };
				interval.to_ = time;
				if (!isValidTime(interval)) {
					throw invalid_argument("Invalid time input. Input time in 24h format(exmpl: 23:59)");
				}
				break;
			}
			catch (invalid_argument& arg) {
				cout << "\n" << arg.what() << "\n";
			}

		}

		schedule[stoi(chooseDay) - 1].second = interval;

		cout << "\nDo you want to proceed?(y/n)\n";
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
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