#include <IPMath.h>

void setup() {
  char addrString[17];
  
  Serial.begin(115200);
  
  IPv4Address ipaddr = IPv4Address(192, 168, 65, 1, 23);
  Serial.println("Ready.");
  
  Serial.print("IP Address (hex): ");
  Serial.println(ipaddr.ipAddress(), HEX);

  ipaddr.ipToString(ipaddr.ipAddress(), addrString);
  Serial.print("IP Address (dotted quad): ");
  Serial.println(addrString);

  ipaddr.ipToString(ipaddr.ipNetmask(), addrString);
  Serial.print("Netmask: ");
  Serial.println(addrString);

  ipaddr.ipToString(ipaddr.ipWildcardMask(), addrString);
  Serial.print("Wildcard Mask: ");
  Serial.println(addrString);

  ipaddr.ipToString(ipaddr.ipNetwork(), addrString);
  Serial.print("Network: ");
  Serial.println(addrString);

  ipaddr.ipToString(ipaddr.ipBroadcast(), addrString);
  Serial.print("Broadcast: ");
  Serial.println(addrString);

  Serial.print("Number of IPs: ");
  Serial.println(ipaddr.nbrOfIPs(), DEC);

  Serial.print("Number of hosts: ");
  Serial.println(ipaddr.nbrOfHosts(), DEC);

  Serial.print("Host Range: ");
  ipaddr.ipToString(ipaddr.ipFirstHost(), addrString);
  Serial.print(addrString);
  Serial.print(" - ");
  ipaddr.ipToString(ipaddr.ipLastHost(), addrString);
  Serial.println(addrString);
}

void loop() {
}
