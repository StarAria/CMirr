
#include "MirrExt/CMirrExt.h"

PROJECT_NAMESPACE_BEGIN

void CMirrExt::CMirrExt(Netlist & Netlist)
    :netlist(Netlist)
{
    CMirrGroup tmp;
    diodeList.clear();
    groupList.clear();
    detectDiodes();
    for(IndexType diode : groupList)
    {
        tmp = detectMirror(diode)
        if(tmp.mirrorMosArray.size())
            groupList.push_back(tmp)
    }
    return;
}

IndexType CMirrExt::findPinNet(PinType type, IndexType mos)
{
    for(IndexType pid : netlist.inst(mos).pinIdArray())
    {
        if(netlist.pinIdArray(pid).type() == type)
            return netlist.pinIdArray(pid).netId();
    }
}

void CMirrExt::detectDiodes()
{
    for(IndexType mos : netlist.numInst())
    {
        if(findPinNet(PinType::GATE, mos) == findPinNet(PinType::DRAIN, mos))
            diodeList.push_back(mos.id());
    }
    return;
}

CMirrGroup CMirrExt::detectMirror(IndexType diode)
{
    IndexType diodeGateNet = findPinNet(PinType::GATE, diode), tmpMos;
    CMirrGroup group;
    group.diodeMos = diode
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
    fout << "{" << endl;
    for(CMirrGroup group : groupList)
    {
        for(IndexType mirrorMos : mirrorMosArray)
        {
            if(firstLine)
                firstLine = false;
            else
                fout << ", " << endl;
            fout << "\t{" << netlist.inst(group.diodeMos).name() << ", " << netlist.inst(mirrorMos).name() << "}";
        }
    }
    fout << endl;
    fout << "}" << endl;
    fout.close();
    return;
}

PROJECT_NAMESPACE_END