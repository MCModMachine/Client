/* cli.cpp
	Contributors:
		Tommy Miller
		Gaelan Steele
	Copyright:
		TBD
*/

#include <iostream>
#include "ClientCLI.hpp"

using std::cout;
using std::endl;

int main() {
	cout << "Client Starting..." << endl;
	ClientCLI cli;
	return cli.Start(); //returns the CLI's exit code.
}
