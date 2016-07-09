#pragma once

#include "Project.hpp"

/**
 * This class is responsible for parsing craft.json files into Project classes.
 */
class CraftJSONParser {
public:
	/**
	 * Parse a single craft.json file, returning the Project specified in that
	 * file.
	 */
	Project ParseSingleJSON(string spec);
};