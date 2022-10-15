
#include <string>
#include <vector>
#include "type.h"

class MOS
{
public:

private:
    std::string         name;
    MosType             type;
    int                 id;
    int                 d;  /*drain pin id*/
    int                 g;  /*drain pin id*/
    int                 s;  /*drain pin id*/
    int                 b;  /*drain pin id*/
};