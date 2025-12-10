#include <ostream>

class BaseServerMessage
{
    public:
        virtual ~BaseServerMessage() {}
        virtual void Write(std::ostream& ostr) = 0;
};
