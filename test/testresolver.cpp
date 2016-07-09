#include <QtTest/QtTest>
#include <vector>

#include "CraftJSONParser.hpp"
#include "Project.hpp"
#include "MemoryProjectRepository.hpp"
#include "ProjectResolver.hpp"
#include "ResolvedProject.hpp"

using std::string;
using std::vector;

class TestResolver: public QObject {
	Q_OBJECT
	private slots:
	void simpleDependency();
};

void TestResolver::simpleDependency() {
    string modSpec = "{specVersion: 1, identifier: 'testmod', type: 'mod', version: '1.0'}";
    string packSpec ="{\"specVersion\": 1, \"identifier\": \"testpack\", \"type\": \"modpack\", \"version\": \"1.0\", \"dependencies\": [{\"project\": \"testmod\", \"version\": \"1.0\"}]}";
    CraftJSONParser parser;
    Project mod = parser.ParseSingleJSON(modSpec);
    Project pack = parser.ParseSingleJSON(packSpec);
	vector<Project> projects {mod,pack};
	MemoryProjectRepository repository((projects));
	string name = "testmodpack";
	ProjectResolver resolver(repository, name, unique_ptr<ResolvedProject>());

	ResolvedProject resolved = resolver.Resolve();
	QCOMPARE(resolved.PackageCount(), 2);
	QCOMPARE(resolved.VersionNameFor("testmod"), string("1.0"));
	QCOMPARE(resolved.VersionNameFor("testpack"), string("1.0"));
}

QTEST_MAIN(TestResolver)
#include "testresolver.moc"