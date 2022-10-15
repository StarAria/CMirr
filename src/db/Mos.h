#ifndef __MOS_H__
#define __MOS_H__

#include <string>
#include <vector>
#include "global/type.h"

PROJECT_NAMESPACE_BEGIN

class Mos
{
public:
    explicit Mos() = default;
    explicit Mos(const std::string &name, InstType type, IndexType id) 
        : _name(name), _type(type), _id(id) 
    {}
    explicit Mos(const std::string &name, InstType type, IndexType id, RealType wid, RealType len, RealType nf) 
        : _name(name), _type(type), _id(id), _wid(wid), _len(len), _nf(nf)
    {}

    const std::string &             name() const                        { return _name; }
    InstType                        type() const                        { return _type; } 
    IndexType                       id() const                          { return _id; }
    const std::vector<IndexType> &  pinIdArray() const                  { return _pinIdArray; }
    RealType                        wid() const                         { return _wid; }
    RealType                        len() const                         { return _len; }
    RealType                        nf() const                          { return _nf; }

    // Setters
    void                            addPinId(IndexType pinId)           { _pinIdArray.push_back(pinId); }
    void                            setWid(RealType wid)                { _wid = wid; }
    void                            setLen(RealType len)                { _len = len; }
    void                            setNf(RealType nf)                  { _nf = nf; }

private:
    std::string                     _name;
    InstType                        _type;
    IndexType                       _id;
    std::vector<IndexType>          _pinIdArray;                        
    RealType                        _wid;
    RealType                        _len;
    RealType                        _nf;
};


PROJECT_NAMESPACE_END

#endif
