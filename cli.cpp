/* cli.cpp
	Contributors:
		Tommy Miller
		Gaelan
	Copyright:
		TBD
*/

#include <iostream>
#include "ClientApp.h"

using std::cout;
using std::endl;

int main() {
	cout << "Client Starting..." << endl;
	ClientApp cli;
	return cli.Start(); //returns the CLI's exit code.
}
