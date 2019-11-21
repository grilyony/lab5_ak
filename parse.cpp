#include <getopt.h>
#include <iostream>
#include <set>
#include <string>
#include <iterator>
using namespace std;


set<string> ProcessArgs(int argc, char** argv)
{	
	string expr;
	set <string> argsList;
	const char* const short_opts = "V:Cl::uh";
    const option long_opts[] = {
            {"version", required_argument, nullptr, 'V'},
            {"comment", no_argument, nullptr, 'C'},
            {"list", optional_argument, nullptr, 'l'},
            {"update", no_argument, nullptr, 'u'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
        case 'V':
			expr = "version of something is " + string(optarg);
            break;

        case 'C':
			expr = "Commented!";
            break;

        case 'l':
			if (optarg != NULL) {
				expr = "listing " + string(optarg) + " elements...";
			} else {
				expr = "listing ALL elements...";
			}
            break;

        case 'u':
            expr = "update was successfully called!";
            break;

        case 'h': // -h or --help
			expr = "--version <n>:       Set the version of something to n\n"
            	   "--comment:           Comments to the screen\n"
            	   "--list <val>:        Lists n elements if given, ALL otherwise\n"
            	   "--update:            Calls update function\n"
            	   "--help:              Show help\n";
			break;
        case '?':
			expr = "unknown parameter " + string(optarg);
			break;
        }
		argsList.insert(expr);
    }
	return argsList;
}

int main(int argc, char **argv)
{
    set<string> result = ProcessArgs(argc, argv);
	set <string> :: iterator it;
	for (it = result.begin(); it != result.end(); ++it)
		cout << *it << "\n";
    return 0;
}
