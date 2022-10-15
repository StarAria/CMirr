#ifndef __TYPE_H__
#define __TYPE_H__

#include <cstdint>
#include "global/global.h"

PROJECT_NAMESPACE_BEGIN

using IndexType     = std::uint32_t;
using IntType       = std::int32_t;
using RealType      = double;
using Byte          = std::uint8_t;

constexpr IndexType     INDEX_TYPE_MAX          = 1000000000;
constexpr IntType       INT_TYPE_MAX            = 1000000000;
constexpr IntType       INT_TYPE_MIN            = -1000000000;
constexpr RealType      REAL_TYPE_MAX           = 1e100;
constexpr RealType      REAL_TYPE_MIN           = -1e100;
constexpr RealType      REAL_TYPE_TOL           = 1e-6; 

enum class InstType : Byte
{
    RES, /*!< Resistor */
    PMOS, /*!< PMos */
    NMOS, /*!< NMos */
    CAP, /*!< Capacitor */
    OTHER /*!< Other */
};

enum class PinType : Byte
{
    SOURCE,
    DRAIN,
    GATE,
    BULK
};    

enum class MosType: Byte
{
    DIFF, /*!< D/G/S diff */
    DIODE, /*!< G/D connected */  
    CAP, /*!< G/S connected */
    DUMMY /*!< D/S connected */
};


    
PROJECT_NAMESPACE_END

#endif
