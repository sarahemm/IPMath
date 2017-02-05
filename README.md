# IPMath
Arduino library to do IP math. Currently only support IPv4.

## IPAddress()

### Description
Creates a variable of type IPv4Address from a 32-bit number

### Syntax
IPAddress(*address*)

### Parameters
*address* - 32-bit IPv4 address

### Returns
Instance of IPv4Address

## IPAddress()

### Description
Creates a variable of type IPv4Address from a 32-bit number, including a 32-bit netmask

### Syntax
IPAddress(*address*, *netmask*)

### Parameters
*address* - 32-bit IPv4 address
*netmask* - 32-bit IPv4 netmask

### Returns
Instance of IPv4Address

## IPAddress()

### Description
Creates a variable of type IPv4Address from a 32-bit number, including a CIDR netmask

### Syntax
IPAddress(*address*, *netmask*)

### Parameters
*address* - 32-bit IPv4 address
*cidrmask* - IPv4 CIDR netmask

### Returns
Instance of IPv4Address

## IPAddress()

### Description
Creates a variable of type IPv4Address from four bytes

### Syntax
IPAddress(*byte1*, *byte2*, *byte3*, *byte4*)

### Parameters
*byteX* - One byte of an IPv4 address

### Returns
Instance of IPv4Address

## IPAddress()

### Description
Creates a variable of type IPv4Address from four bytes, including a 4-byte netmask

### Syntax
IPAddress(*byte1*, *byte2*, *byte3*, *byte4*, *mask1*, *mask2*, *mask3*, *mask4*)

### Parameters
*byteX* - One byte of an IPv4 address
*maskX* - One byte of an IPv4 netmask

### Returns
Instance of IPv4Address

## IPAddress()

### Description
Creates a variable of type IPv4Address from four bytes, including a CIDR netmask

### Syntax
IPAddress(*byte1*, *byte2*, *byte3*, *byte4*, *cidrmask*)

### Parameters
*byteX* - One byte of an IPv4 address
*cidrmask* - IPv4 CIDR netmask

### Returns
Instance of IPv4Address

## ipToBytes()

### Description
Turn a 32-bit IP address into four bytes

### Syntax
*IPv4Address*.ipToBytes(*addr*, **bytes*)

### Parameters
*addr* - 32-bit IP address
*bytes* - Pointer to 4-byte array

### Returns
None

## ipToString()

### Description
Turn a 32-bit IP address into a dotted quad string

### Syntax
*IPv4Address*.ipToString(*addr*, **string*)

### Parameters
*addr* - 32-bit IP address
*string* - Pointer to (at least) 16-character array

### Returns
None

## ipAddress()

### Description
Return our address as one 32-bit word

### Syntax
*IPv4Address*.ipAddress(**)

### Parameters
*None

### Returns
32-bit word

## ipNetmask()

### Description
Return our netmask as one 32-bit word

### Syntax
*IPv4Address*.ipNetmask(**)

### Parameters
*None

### Returns
32-bit word

## ipWildcardMask()

### Description
Return our wildcard netmask as one 32-bit word

### Syntax
*IPv4Address*.ipWildcardMask(**)

### Parameters
*None

### Returns
32-bit word

## ipNetwork()

### Description
Return our network IP as one 32-bit word

### Syntax
*IPv4Address*.ipNetwork(**)

### Parameters
*None

### Returns
32-bit word

## ipBroadcast()

### Description
Return our broadcast IP as one 32-bit word

### Syntax
*IPv4Address*.ipBroadcast(**)

### Parameters
*None

### Returns
32-bit word

## ipFirstHost()

### Description
Return the first usable host IP

### Syntax
*IPv4Address*.ipFirstHost(**)

### Parameters
*None

### Returns
32-bit word

## ipLastHost()

### Description
Return the last usable host IP

### Syntax
*IPv4Address*.ipLastHost(**)

### Parameters
*None

### Returns
32-bit word

## nbrOfIPs()

### Description
Return the number of IPs in our block

### Syntax
*IPv4Address*.nbrOfIPs(**)

### Parameters
*None

### Returns
Number of IPs, as a 32-bit word

## nbrOfHosts()

### Description
Return the number of hosts in our block

### Syntax
*IPv4Address*.nbrOfHosts(**)

### Parameters
*None

### Returns
Number of hosts, as a 32-bit word

