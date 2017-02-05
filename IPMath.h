/*
  IPMath.h - Arduino library for doing IP address math.
  Copyright (c) 2016 sen.  Licensed under Creative Commons BY-NC-SA.
*/

// ensure this library description is only included once
#ifndef IPMath_h
#define IPMath_h

#include <Arduino.h>

// library interface description
class IPv4Address {
  // user-accessible "public" interface
  public:
    IPv4Address(unsigned long);
    IPv4Address(unsigned long, unsigned long);
    IPv4Address(unsigned long, byte);
    
    IPv4Address(byte, byte, byte, byte);
    IPv4Address(byte, byte, byte, byte, byte, byte, byte, byte);
    IPv4Address(byte, byte, byte, byte, byte);

    void ipToBytes(unsigned long, byte*);
    void ipToString(unsigned long, char *);
    unsigned long ipAddress();
    unsigned long ipNetmask();
    unsigned long ipWildcardMask();
    unsigned long ipNetwork();
    unsigned long ipBroadcast();
    unsigned long ipFirstHost();
    unsigned long ipLastHost();
    unsigned long nbrOfIPs();
    unsigned long nbrOfHosts();
    
  // library-accessible "private" interface
  private:
    unsigned long addr;
    unsigned long mask;
    
    unsigned long swapBytes(unsigned long);
};

#endif
