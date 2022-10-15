#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>
#include "parser/simpNetlist.h"
#include "global/type.h"

PROJECT_NAMESPACE_BEGIN

bool simpNetlist::read(const std::string &fileName)
{
    Netlist::InitDataObj obj;
    std::ifstream inFile(fileName.c_str());
    if (!inFile.is_open())
    {
        std::printf("Cannot open file: %s \n", fileName.c_str());
        return false;
    }

    std::string line;
	while(std::getline(inFile, line))
	{
        // M4   2 3 9 9 PMOS
        std::istringstream ss(line);
        std::vector<std::string> words;
        std::string word;
        while(ss >> word) {
            words.push_back(word);
        }
        if (words.size()==0)
            continue;
        
        Netlist::InitInst inst;
        // name
        inst.name = words.at(0);
        // type
        InstType instType;
        if (words.at(5) == "PMOS")
            instType = InstType::PMOS;
        else if (words.at(5) == "NMOS")
            instType = InstType::NMOS;
        else
            std::cerr << "Unknown inst type:" << words.at(5).c_str() << std::endl;
        inst.type = instType;
        // pin net
        std::vector<std::string> instPins = {words.at(1), words.at(2), words.at(3), words.at(4)};
        for (std::string instPin : instPins) {
            std::vector<std::string>::iterator fit = find(_vNetNames.begin(), _vNetNames.end(), instPin);
            IndexType netIdx;
            if (fit == _vNetNames.end()) {
                netIdx = _vNetNames.size();
                _vNetNames.emplace_back(instPin);
                // add net
                Netlist::InitNet net;
                net.id = netIdx;
                net.name = instPin;
                obj.netArray.push_back(net);
            }
            else {
                netIdx = fit - _vNetNames.begin();
                // std::cout << "TRACE netIdx=" << netIdx << " instPin=" << instPin.c_str() << std::endl;
            }
            // add pin
            inst.netIdArray.push_back(netIdx);
        }
        // inst
        obj.instArray.push_back(inst);
	}
    // std::cout<<"_vNetNames:";
    // for(std::string x : _vNetNames) {
    //     std::cout << x << "||";
    // }
    // std::cout << std::endl;

    std::vector<Net>                _netArray;
    std::vector<Pin>                _pinArray;
    std::vector<Mos>               _instArray;

    _netlistDB.init(obj);
    return true;
}

PROJECT_NAMESPACE_END
