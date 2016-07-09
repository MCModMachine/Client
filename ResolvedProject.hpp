#pragma once

#include <string>

using std::string;

class ResolvedProject {
public:
	int PackageCount();
	string VersionNameFor(string packageIdentifier);
};