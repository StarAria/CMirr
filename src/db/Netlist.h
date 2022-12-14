#ifndef __NETLIST_H__
#define __NETLIST_H__

#include <vector>
#include <string>
#include "global/type.h"
#include "db/Net.h"
#include "db/Pin.h"
#include "db/Mos.h"

PROJECT_NAMESPACE_BEGIN
class Netlist
{
public:
    struct InitNet
    {
        std::string                 name;
        IndexType                   id = INDEX_TYPE_MAX;
    };
    struct InitInst
    {
        InstType                    type = InstType::OTHER;
        std::vector<IndexType>      netIdArray;
        std::string                 name; 
        RealType                    wid = 0, len = 0, nf = 1;
    };
    struct InitDataObj
    {
        std::vector<InitNet>        netArray;
        std::vector<InitInst>       instArray;
    };

public:
    explicit Netlist() = default;
    
    void                            init(InitDataObj &obj);

    IndexType                       addNet(const std::string name, IndexType netIdx);

    IndexType                       addInst(const std::string name, InstType type, RealType wid, RealType len, RealType nf);

    void                            addInstPin(IndexType instIdx, IndexType netIdx, PinType pinType);

    void                            print_all() const;

    bool                            isMos(InstType instType) const;
    bool                            isPasvDev(InstType instType) const;
    MosType                         mosType(IndexType mosId) const;

    IndexType                       instNetId(IndexType instId, PinType pinType) const;
    IndexType                       instPinId(IndexType instId, PinType pinType) const;

    IndexType                       srcNetId(IndexType mosId) const     { return instNetId(mosId, PinType::SOURCE); }
    IndexType                       drainNetId(IndexType mosId) const   { return instNetId(mosId, PinType::DRAIN); }
    IndexType                       gateNetId(IndexType mosId) const    { return instNetId(mosId, PinType::GATE); }

    PinType                         getPinTypeInstPinConn(IndexType instId, IndexType pinId) const;
    PinType                         getPinTypeInstNetConn(IndexType instId, IndexType netId) const;

    void                            getInstNetConn(std::vector<IndexType> & instArray, IndexType netId) const;
    void                            getInstPinConn(std::vector<IndexType> & instArray, IndexType pinId) const;

    void                            rmvInstHasPin(std::vector<IndexType> & instArray, IndexType pinId) const;

    void                            fltrInstPinConnPinType(std::vector<IndexType> & instArray, IndexType pinId, PinType connPinType) const;
    void                            fltrInstNetConnPinType(std::vector<IndexType> & instArray, IndexType netId, PinType connPinType) const;
    void                            fltrInstMosType(std::vector<IndexType> & instArray, MosType mosType) const;
    void                            fltrInstType(std::vector<IndexType> & instArray, InstType type) const;
   
    const Pin &                     pin(IndexType id) const             { return _pinArray.at(id); }
    const Net &                     net(IndexType id) const             { return _netArray.at(id); }
    const Mos &                    inst(IndexType id) const            { return _instArray.at(id); }
    IndexType                       numPin() const                      { return _pinArray.size(); }
    IndexType                       numNet() const                      { return _netArray.size(); }
    IndexType                       numInst() const                     { return _instArray.size(); }
    IndexType                       instId(int arrayid)                 { return _instArray[arrayid].id();}

    void                            addPin(Pin & pin)                   { _pinArray.push_back(pin); }
    void                            addNet(Net & net)                   { _netArray.push_back(net); }
    void                            addInst(Mos & inst)                { _instArray.push_back(inst); }

private:    
    std::vector<Net>                _netArray;
    std::vector<Pin>                _pinArray;
    std::vector<Mos>               _instArray;
};

PROJECT_NAMESPACE_END

#endif
