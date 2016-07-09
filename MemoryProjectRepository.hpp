#pragma once

#include <vector>

#include "Project.hpp"
#include "ProjectRepository.hpp"

class MemoryProjectRepository: public ProjectRepository {
public:
	MemoryProjectRepository(vector<Project>);
};