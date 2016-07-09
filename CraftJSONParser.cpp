//
//  CraftJSONParser.cpp
//  mcubed-client
//
//  Created by Gaelan Bright Steele on 7/3/16.
//
//

#include "QtCore/QtCore"

#include "CraftJSONParser.hpp"
#include "Project.hpp"
#include "ProjectVersion.hpp"


Project CraftJSONParser::ParseSingleJSON(string specString) {
	QByteArray specBytes(specString.data());
	QJsonDocument spec = QJsonDocument::fromJson(specBytes);
	QJsonObject obj = spec.object();
	string identifier = obj["identifier"].toString().toStdString();
	ProjectVersion version;
	vector<ProjectVersion> versions {version};
	return Project(identifier, versions);
}