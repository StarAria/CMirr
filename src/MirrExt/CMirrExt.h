
#include "db/Netlist.h"
#include <string>
#include <vector>
#include <fstream>

PROJECT_NAMESPACE_BEGIN

struct CMirrGroup
{
    IndexType                   diodeMos;
    std::vector<IndexType>      mirrorMosArray;
}

class CMirrExt
{
public:
    CMirrExt() = default;
    CMirrExt(Netlist & Netlist);

    IndexType findPinNet(PinType type, IndexType mos);
    void detectDiodes();
    CMirrGroup detectMirror(IndexType diode);
    void printResult();

private:

    Netlist &                   netlist;
    std::vector<IndexType>      diodeList;
    std::vector<CMirrGroup>     groupList;

};

PROJECT_NAMESPACE_END