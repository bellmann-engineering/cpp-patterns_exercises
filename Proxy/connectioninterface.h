#ifndef _CONNINTERFACE_H_
#define _CONNINTERFACE_H_

class ConnectionInterface
{
    public:
        virtual void open(std::string, int) = 0;
        virtual void close() = 0;
};

#endif // _CONNINTERFACE_H_