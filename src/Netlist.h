
#include <vector>
#include <string>
#include "type.h"
#include "Net.h"
#include "Pin.h"
#include "MOS.h"

class netlist
{
public:
    struct InitNet
    {
        std::string                 name;
        IndexType                   id = 1000000;
    };

    struct InitMos
    {
        MosType                     type;
        std::vector<int>            netIdArray;
        std::string                 name;
    };

    struct InitDataObj
    {
        std::vector<InitNet>        netArray;
        std::vector<InitMos>        mosArray;
    };

private:
    std::vector<Net>                netVec;
    std::vector<Pin>                pinVec;
    std::vector<MOS>                mosVec;
};