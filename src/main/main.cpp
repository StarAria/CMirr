
#include <string>
#include "parser/simpNetlist.h"
// #include "CMirrDetect.h"

int main(int argc, char* argv[])
{
    using namespace PROJECT_NAMESPACE;
    Netlist netlist;
    simpNetlist parser = simpNetlist(netlist);
    std::string inFile(argv[1]);
    parser.read(inFile); //initialize netlist with parser
    CMirrDetect instCurrent(netlist);
    instCurrent.printResult();

    return 0;
}