#ifndef _NETWORKCONN_H_
#define _NETWORKCONN_H_

#include "connectioninterface.h"
#include <string>
#include <iostream>

class NetworkConnection : public ConnectionInterface 
{
	private:
        std::string address;
	    int port;
	    bool connected;
	
	    void openConnection()
        {
		    connected = true;
		    std::cout << "Connected" << std::endl;
	    }
	
	    void closeConnection()
        {
		    connected = false;
		    address = "";
		    port = -1;
		    std::cout << "Disconnecting" << std::endl;
	    }

    public:
        void open(std::string address, int port) override
        {
                if(!isConnected())
                {
                    this->address = address;
                    this->port = port;
                    openConnection();
                }
                else
                    std::cout << "Already connected!" << std::endl;
        }
	
        void close() override
        {
            if(!isConnected())
                std::cout << "You are not connected yet!" << std::endl;
            else
                closeConnection();
        }
        
        std::string getAddress() const
        {
            return address;
        }
        
        int getPort()
        {
            return port;
        }
        
        bool isConnected()
        {
            return connected;
        }
};

#endif // _NETWORKCONN_H_