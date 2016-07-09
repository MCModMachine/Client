#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 3.5)
#Name your project here
project(mcubed-client)

# Dependencies

find_package(Qt5Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

#include_directories(${Qt5Test_INCLUDE_DIRS})

# Our project

set(MCUBED_SOURCES
    cli.cpp
    ClientCLI.hpp
    ClientCLI.cpp
    Project.hpp
    Project.cpp
	ProjectVersion.hpp
	ProjectVersion.cpp
	CraftJSONParser.hpp
	CraftJSONParser.cpp
	ProjectResolver.hpp
	ProjectResolver.cpp
	ProjectRepository.hpp
	ProjectRepository.cpp
	MemoryProjectRepository.hpp
	MemoryProjectRepository.cpp
	ResolvedProject.hpp
	ResolvedProject.cpp
)
add_executable(mcubed ${MCUBED_SOURCES})

# Testing

enable_testing()

add_executable(testresolver test/testresolver.cpp ${MCUBED_SOURCES})
add_test(NAME testresolver COMMAND testresolver WORKING_DIRECTORY tmp/resolver)
target_compile_features(testresolver PRIVATE cxx_generalized_initializers)
target_link_libraries(testresolver Qt5::Test)
