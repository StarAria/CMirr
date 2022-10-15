
#include <string>
#include "parser/InitNetlist.h" //Fixme
#include "CMirrDetect.h"

int main(int argc, char* argv[])
{
/*
netlist parser
*/
    CMirrDetect instCurrent(netlist);
    instCurrent.output();

    return 0;
}