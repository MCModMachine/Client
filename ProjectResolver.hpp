#pragma once

#import <memory>
#import <string>

#import "ProjectRepository.hpp"
#import "ResolvedProject.hpp"

using std::unique_ptr;
using std::string;

/**
 * A ProjectResolver is responsible for choosing the appropriate versions of
 * a project and all of its dependencies such that the game will work properly.
 */
class ProjectResolver {
public:
	/**
	 * Construct a new ProjectResolver.
	 * 
	 * @param repo A ProjectRepository containing all known project versions.
	 * @param identifier The identifier of the root project which should be
	 *   installed.
	 * @param previous If we are updating a previous set of versions, the
	 *   the previous set of versions. Otherwise, a null pointer.
	 */
	ProjectResolver(ProjectRepository repo,
					string identifier,
					unique_ptr<ResolvedProject> previous);

	ResolvedProject Resolve();
};