#include <iostream>
#include <string>

inline uint8_t ReadNetworkUInt8(std::istream& istr)
{
    uint8_t i;
    istr.read((char*)&i, sizeof(uint8_t));
    return i;
}

inline uint16_t ReadNetworkUInt16(std::istream& istr)
{
    #if BIG_ENDIAN
        uint16_t i;
        istr.read((char*)&i, sizeof(uint16_t));
        return (i >> 8) | (i << 8);
    #else
        uint16_t i;
        istr.read((char*)&i, sizeof(uint16_t));
        return i;
    #endif
}

inline uint32_t ReadNetworkUInt32(std::istream& istr)
{
    #if BIG_ENDIAN
        uint32_t i;
        istr.read((char*)&i, sizeof(uint32_t));
        return (ui >> 24) |
            ((ui<<8) & 0x00FF0000) |
            ((ui>>8) & 0x0000FF00) |
            (ui << 24);
    #else
        uint32_t i;
        istr.read((char*)&i, sizeof(uint32_t));
        return i;
    #endif
}

inline std::string ReadNetworkString(std::istream& istr)
{
    uint32_t len = ReadNetworkUInt32(istr);
    std::string str(len, '\0');
    istr.read(&str[0], len);
    return str;
}

inline void WriteNetworkUInt8(std::ostream& ostr, uint8_t i)
{
    ostr.write((char*)&i, sizeof(uint8_t));
}

inline void WriteNetworkUInt16(std::ostream& ostr, uint16_t i)
{
    #if BIG_ENDIAN
        uint16_t oi = (i >> 8) | (i << 8);
        ostr.write((char*)&oi, sizeof(uint16_t));
    #else
        ostr.write((char*)&i, sizeof(uint16_t));
    #endif
}

inline void WriteNetworkUInt32(std::ostream& ostr, uint32_t i)
{
    #if BIG_ENDIAN
        int32_t oi = (i >> 24) |
            ((i<<8) & 0x00FF0000) |
            ((i>>8) & 0x0000FF00) |
            (i << 24);
        ostr.write((char*)&oi, sizeof(uint32_t));
    #else
        ostr.write((char*)&i, sizeof(uint32_t));
    #endif
}

inline void WriteNetworkString(std::ostream& ostr, std::string str)
{
    int32_t len = str.length();
    WriteNetworkUInt32(ostr, len);
    ostr.write(str.c_str(), len);
}
