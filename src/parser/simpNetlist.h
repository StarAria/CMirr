#ifndef __SIMPNETLIST_H__
#define __SIMPNETLIST_H__

#include "db/Netlist.h"

PROJECT_NAMESPACE_BEGIN
/*! @class simpNetlist
    @brief simpNetlist class
*/
class simpNetlist
{
public:
/*! @brief Default Constructor */
    explicit simpNetlist() = default;
/*! @brief Constructor with initialization */
    explicit simpNetlist(Netlist & netlist) : _netlistDB(netlist) {}

    void setNetlist(Netlist & netlist) { _netlistDB = netlist; }
    bool read(const std::string &filename);
     
private:
    Netlist & _netlistDB;
    std::vector<std::string> _vNetNames;
};


PROJECT_NAMESPACE_END

#endif
