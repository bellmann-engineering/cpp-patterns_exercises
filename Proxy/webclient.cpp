#include "firewall.h"

int main()
{
    Firewall firewall; 
        
    firewall.open("google.com", 80);
    firewall.close();
    
    //should not open the connection
    firewall.open("google.com", 21);	
}