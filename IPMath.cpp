/*
  IPMath.h - Arduino library for doing IP address math.
  Copyright (c) 2016 sen.  Licensed under Creative Commons BY-NC-SA.
*/

// include this library's description file
#include "IPMath.h"
	
// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

IPv4Address::IPv4Address(void) {
  // this 'fake constructor' allows creating an 'empty' IPv4Address type variable
  // later on, the 'real constructor' can be called to actually begin using it.
	addr = 0;
	mask = 0;
}

// Description: Creates a variable of type IPv4Address from a 32-bit number
// Syntax: IPAddress(address)
// Parameter: address - 32-bit IPv4 address
// Returns: Instance of IPv4Address
IPv4Address::IPv4Address(unsigned long myAddress) {
	addr = myAddress;
	mask = 0xFFFFFFFF; // /32
}

// Description: Creates a variable of type IPv4Address from a 32-bit number, including a 32-bit netmask
// Syntax: IPAddress(address, netmask)
// Parameter: address - 32-bit IPv4 address
// Parameter: netmask - 32-bit IPv4 netmask
// Returns: Instance of IPv4Address
IPv4Address::IPv4Address(unsigned long myAddress, unsigned long myNetmask) {
	addr = myAddress;
	mask = swapBytes(myNetmask);
}

// Description: Creates a variable of type IPv4Address from a 32-bit number, including a CIDR netmask
// Syntax: IPAddress(address, netmask)
// Parameter: address - 32-bit IPv4 address
// Parameter: cidrmask - IPv4 CIDR netmask
// Returns: Instance of IPv4Address
IPv4Address::IPv4Address(unsigned long myAddress, byte myCidrNetmask) {
	addr = myAddress;
	mask = 0xffffffff ^ (1 << 32 - myCidrNetmask) - 1;
}

// Description: Creates a variable of type IPv4Address from four bytes
// Syntax: IPAddress(byte1, byte2, byte3, byte4)
// Parameter: byteX - One byte of an IPv4 address
// Returns: Instance of IPv4Address
IPv4Address::IPv4Address(byte byteA, byte byteB, byte byteC, byte byteD) {
	addr = byteD | byteC << 8 | byteB << 16 | byteA << 24;
	mask = 0xFFFFFFFF; // /32
}

// Description: Creates a variable of type IPv4Address from four bytes, including a 4-byte netmask
// Syntax: IPAddress(byte1, byte2, byte3, byte4, mask1, mask2, mask3, mask4)
// Parameter: byteX - One byte of an IPv4 address
// Parameter: maskX - One byte of an IPv4 netmask
// Returns: Instance of IPv4Address
IPv4Address::IPv4Address(byte byteA, byte byteB, byte byteC, byte byteD, byte maskA, byte maskB, byte maskC, byte maskD) {
	addr = byteD | byteC << 8 | byteB << 16 | byteA << 24;
	mask = maskD | maskC << 8 | maskB << 16 | maskA << 24;
}

// Description: Creates a variable of type IPv4Address from four bytes, including a CIDR netmask
// Syntax: IPAddress(byte1, byte2, byte3, byte4, cidrmask)
// Parameter: byteX - One byte of an IPv4 address
// Parameter: cidrmask - IPv4 CIDR netmask
// Returns: Instance of IPv4Address
IPv4Address::IPv4Address(byte byteA, byte byteB, byte byteC, byte byteD, byte myCidrNetmask) {
	addr = byteD | byteC << 8 | byteB << 16 | byteA << 24;
	mask = 0xffffffff ^ (1 << 32 - myCidrNetmask) - 1;
}

// -----

// Description: Turn a 32-bit IP address into four bytes
// Syntax: IPv4Address.ipToBytes(addr, *bytes)
// Parameter: addr - 32-bit IP address
// Parameter: bytes - Pointer to 4-byte array
// Returns: None
void IPv4Address::ipToBytes(unsigned long addr, byte *addressBytes) {
	addressBytes[3] = addr         & 0xFF;
	addressBytes[2] = (addr >> 8)  & 0xFF;
	addressBytes[1] = (addr >> 16) & 0xFF;
	addressBytes[0] = (addr >> 24) & 0xFF;
}

// Description: Turn a 32-bit IP address into a dotted quad string
// Syntax: IPv4Address.ipToString(addr, *string)
// Parameter: addr - 32-bit IP address
// Parameter: string - Pointer to (at least) 16-character array
// Returns: None
void IPv4Address::ipToString(unsigned long addr, char *string) {
	byte addressBytes[4];
	
	addressBytes[3] = addr         & 0xFF;
	addressBytes[2] = (addr >> 8)  & 0xFF;
	addressBytes[1] = (addr >> 16) & 0xFF;
	addressBytes[0] = (addr >> 24) & 0xFF;
	sprintf(string, "%d.%d.%d.%d", addressBytes[0], addressBytes[1], addressBytes[2], addressBytes[3]);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

// Description: Return our address as one 32-bit word
// Syntax: IPv4Address.ipAddress()
// Parameter: None
// Returns: 32-bit word
unsigned long IPv4Address::ipAddress(void) {
	return addr;
}

// Description: Return our netmask as one 32-bit word
// Syntax: IPv4Address.ipNetmask()
// Parameter: None
// Returns: 32-bit word
unsigned long IPv4Address::ipNetmask(void) {
	return mask;
}

// Description: Return our wildcard netmask as one 32-bit word
// Syntax: IPv4Address.ipWildcardMask()
// Parameter: None
// Returns: 32-bit word
unsigned long IPv4Address::ipWildcardMask(void) {
	return ~mask;
}

// Description: Return our network IP as one 32-bit word
// Syntax: IPv4Address.ipNetwork()
// Parameter: None
// Returns: 32-bit word
unsigned long IPv4Address::ipNetwork(void) {
	return addr & mask;
}

// Description: Return our broadcast IP as one 32-bit word
// Syntax: IPv4Address.ipBroadcast()
// Parameter: None
// Returns: 32-bit word
unsigned long IPv4Address::ipBroadcast(void) {
	return ipNetwork() | ~mask;
}

// Description: Return the first usable host IP
// Syntax: IPv4Address.ipFirstHost()
// Parameter: None
// Returns: 32-bit word
unsigned long IPv4Address::ipFirstHost(void) {
	return ipNetwork() + 1;
}

// Description: Return the last usable host IP
// Syntax: IPv4Address.ipLastHost()
// Parameter: None
// Returns: 32-bit word
unsigned long IPv4Address::ipLastHost(void) {
	return ipBroadcast() - 1;
}

// Description: Return the number of IPs in our block
// Syntax: IPv4Address.nbrOfIPs()
// Parameter: None
// Returns: Number of IPs, as a 32-bit word
unsigned long IPv4Address::nbrOfIPs(void) {
	return ~(ipNetmask()-1);
}

// Description: Return the number of hosts in our block
// Syntax: IPv4Address.nbrOfHosts()
// Parameter: None
// Returns: Number of hosts, as a 32-bit word
unsigned long IPv4Address::nbrOfHosts(void) {
	return nbrOfIPs() - 2;
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

unsigned long IPv4Address::swapBytes(unsigned long num) {
	return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
}

// Documentation ///////////////////////////////////////////////////////////////

