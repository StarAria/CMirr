
enum class MosType : bool
{
    PMOS = true,
    NMOS = false
};

enum class PinType : uint8_t
{
    DRAIN,
    GATE,
    SOURCE,
    BULK
};