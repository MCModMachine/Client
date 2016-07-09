#pragma once

#include <string>
#include <vector>

#include "ProjectVersion.hpp"

using std::string;
using std::vector;

/**
 * A project (mod, pack, etc). This class encompasses every version of a
 * project, so the vast majority of properties are stored per-version. Note that
 * this class does not include all fields from the craft.json spec, but only the
 * ones that we are currently using.
 */
class Project {
	string identifier;
	vector<ProjectVersion> versions;

public:
	Project(string identifier, vector<ProjectVersion> versions):
		identifier(identifier), versions(versions) {}
};