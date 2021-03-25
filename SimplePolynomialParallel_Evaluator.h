#pragma once
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <random>
#include <ranges>
#include <deque>
#include <regex>

#include "AddSimilarMonomi.h"
#include "ProblemGen.h"
/// <summary>
/// ---------> DECODE THE BIG STRING
/// </summary>
/// <param name="expression"></param>
/// <returns></returns>
auto parseCompleteString(std::string expression)->std::vector<std::string> {
	//expressions parser : vector of expressions
	std::stringstream streamObj;
	std::vector<std::string> expressionVector;
	for (auto& c : expression) {
		if (c != ';') {
			streamObj << c;
		}
		else {
			expressionVector.push_back(streamObj.str());
			streamObj.str("");
		}
	}
	for (auto& cc : expressionVector) {
		std::cout << cc << std::endl;
	}
	return expressionVector;
}

/// <summary>
/// ---------> COLLECT CABLES AND RESOLVE
/// </summary>
/// <param name="_Right"></param>
/// <returns></returns>
auto resolution(std::string expression)->std::string {
	std::vector<std::string> expressionVector = parseCompleteString(expression);
	for (auto& cc : expressionVector) {
		parse_inMonomi(cc);
	}
	return "";
}