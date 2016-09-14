#pragma once
#include <vector>
#include <string>
#include <sstream>
using namespace std;

namespace LoggerTools
{
	/* Tool that converts anything into a string */
	template <typename T> string str(const T& t)
	{
		ostringstream os;
		os << t;
		return os.str();
	}
}

/* Logger: logs the output of the program (instead of just cout or printf) */
class Logger
{
public:
	/* Sets up the logger for use */
	static void init();
	/* Defines the name of the code it is currently in */
	static void setSpace(string space) { spaceStack.push_back(space); }
	/* Reverts to the name of the last section of code */
	static void back() { spaceStack.pop_back(); }
	/* Logs a message */
	template<typename T> static void log(T t);
	/* Logs then goes to a new line */
	template<typename T> static void logln(T t);
private:
	static string getSpace();
	/* Stack of spaces */
	static vector<string> spaceStack;
	static long lastTime;
};