
#include "MirrExt/CMirrExt.h"

PROJECT_NAMESPACE_BEGIN

CMirrExt::CMirrExt(Netlist & netlist)
    :netlist(netlist)
{
    CMirrGroup tmp;
    diodeList.clear();
    groupList.clear();
    detectDiodes();
    for(IndexType diode : diodeList)
    {
        tmp = detectMirror(diode);
        if(tmp.mirrorMosArray.size())
            groupList.push_back(tmp);
    }
    return;
}

IndexType CMirrExt::findPinNet(PinType type, IndexType mos)
{
    for(IndexType pid : netlist.inst(mos).pinIdArray())
    {
        if(netlist.pin(pid).type() == type)
            return netlist.pin(pid).netId();
    }
}

void CMirrExt::detectDiodes()
{
    for(IndexType index = 0; index < netlist.numInst(); index++)
    {
        if(findPinNet(PinType::GATE, netlist.instId(index)) == findPinNet(PinType::DRAIN, netlist.instId(index)))
            diodeList.push_back(netlist.instId(index));
    }
    return;
}

CMirrGroup CMirrExt::detectMirror(IndexType diode)
{
    IndexType diodeGateNet = findPinNet(PinType::GATE, diode), tmpMos;
    CMirrGroup group;
    group.diodeMos = diode;
    for(IndexType pid : netlist.net(diodeGateNet).pinIdArray())
    {
        if(netlist.pin(pid).type() == PinType::GATE)
        {
            tmpMos = netlist.pin(pid).instId();
            if(findPinNet(PinType::GATE, tmpMos) != findPinNet(PinType::DRAIN, tmpMos) &&
                findPinNet(PinType::SOURCE, diode) != findPinNet(PinType::SOURCE, tmpMos) &&
                netlist.inst(diode).type() == netlist.inst(tmpMos).type())
                group.mirrorMosArray.push_back(tmpMos);
        }
    }
    return group;
}

void CMirrExt::printResult()
{
    std::string file("CurrentMirror.txt");
    std::ofstream fout(file.c_str());
    bool firstLine = true;
    fout << "{" << std::endl;
    for(CMirrGroup group : groupList)
    {
        for(IndexType mirrorMos : group.mirrorMosArray)
        {
            if(firstLine)
                firstLine = false;
            else
                fout << ", " << std::endl;
            fout << "\t{" << netlist.inst(group.diodeMos).name() << ", " << netlist.inst(mirrorMos).name() << "}";
        }
    }
    fout << std::endl;
    fout << "}" << std::endl;
    fout.close();
    return;
}

PROJECT_NAMESPACE_END