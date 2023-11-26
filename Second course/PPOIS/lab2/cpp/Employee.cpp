/**
 * @file Employee.cpp
 * @brief File containing the implementation of the Employee class.
 * @author Verkovich E.V.
 * @date November 26, 2023
 */

#include "Employee.h"
 /**
  * @brief Constructor of the Employee class.
  *
  * The constructor initializes an Employee object with a given name, position, and salary.
  *
  * @param name The employee's name.
  * @param position The employee's position.
  * @param salary The employee's salary.
  */
Employee::Employee(const string& name, const string& position, const double& salary) :
	name_(name), position_(position), salary_(salary), busy_(0) {}
/**
 * @brief Get the employee's name.
 *
 * @return String containing the employee's name.
 */
string Employee::getName() const {
	return name_;
}
/**
 * @brief Set the employee's name.
 *
 * @param name The employee's name.
 */
void Employee::setName(const string& name) {
	name_ = name;
}

/**
 * @brief Get the employee's position.
 *
 * @return String containing the employee's position.
 */
string Employee::getPosition() const {
	return position_;
}

/**
 * @brief Set the employee's position.
 *
 * @param position The employee's position.
 */
void Employee::setPosition(const string& position) {
	position_ = position;
}
/**
 * @brief Get the employee's salary.
 *
 * @return The employee's salary.
 */
double Employee::getSalary() const {
	return salary_;
}
/**
 * @brief Set the employee's salary.
 *
 * @param salary The employee's salary.
 */
void Employee::setSalary(const double& salary) {
	salary_ = salary;
}
/**
 * @brief Get the employee's busy status.
 *
 * @return The employee's busy status.
 */
bool Employee::getBusy()const {
	return busy_;
}
/**
 * @brief Set the employee's busy status.
 *
 * @param busy The employee's busy status.
 */
void Employee::setBusy(const int& busy) {
	busy_ = busy;
}

/**
 * @brief Get all orders associated with the employee.
 *
 * @return A vector containing all orders associated with the employee.
 */
vector<Order>& Employee::getOrders() {
	return orders;
}
