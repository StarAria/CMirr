/*! @file db/Net.h
    @brief Net class.
    @author Mingjie LIu
    @date 11/24/2018
*/
#ifndef __NET_H__
#define __NET_H__

#include <string>
#include <vector>
#include "global/type.h"

PROJECT_NAMESPACE_BEGIN
class Net
{
public:
    explicit Net() = default;
    explicit Net(const std::string &name, IndexType id) 
        : _name(name), _id(id)
    {}    

    const std::string &             name() const        { return _name; }
    IndexType                       id() const          { return _id; }
    const std::vector<IndexType> &  pinIdArray() const  { return _pinIdArray; }
    
    void                        addPinId(IndexType pinId)   { _pinIdArray.push_back(pinId); } 
    
private:
    std::string                 _name;
    IndexType                   _id;
    std::vector<IndexType>      _pinIdArray;
};

PROJECT_NAMESPACE_END

#endif
