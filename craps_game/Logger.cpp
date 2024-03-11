/*
 * Logger.cpp
 *
 *  Created on: 8 Mar 2024
 *      Author: woutn
 */

#include "Logger.h"
#include <iostream>
#include <mutex>

std::mutex locker;

void Logger::logText(const std::string &logtext) {
	std::lock_guard<std::mutex> guard(locker);
	std::cout << "Logger says: ";
	std::cout << logtext << std::endl;
}

Logger& Logger::getInstance() {
	static Logger instance;
	return instance;
}

void Logger::logText(const std::stringstream &logtext) {
//	std::cout << "Now using a string stream:)" << std::endl;
	logText(logtext.str());
}

Logger::Logger() {
	// TODO Auto-generated constructor stub

}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

