
#include <string>
#include "parser/simpNetlist.h"
#include "MirrExt/CMirrExt.h"

int main(int argc, char* argv[])
{
    using namespace PROJECT_NAMESPACE;
    Netlist netlist;
    simpNetlist parser = simpNetlist(netlist);
    std::string inFile(argv[1]);
    parser.read(inFile);
    CMirrExt instCurrent(netlist);
    instCurrent.printResult();

    return 0;
}