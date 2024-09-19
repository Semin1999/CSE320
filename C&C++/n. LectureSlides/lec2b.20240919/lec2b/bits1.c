
#include <stdio.h>

// 0                   1                   2                   3         
//    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1    
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   
//   |Version|  IHL  |Type of Service|          Total Length         |   
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   
//   |         Identification        |Flags|      Fragment Offset    |   
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   
//   |  Time to Live |    Protocol   |         Header Checksum       |   
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   
//   |                       Source Address                          |   
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   
//   |                    Destination Address                        |   
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   
//   |                    Options                    |    Padding    |   
//   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   
//                                                                       
//                    Example Internet Datagram Header                   


int getFlags(int *ipHeader) {
  int *wordPtr = ipHeader;
  wordPtr += 1;
  int mask = 0x0000e000;
  int flagsOffset = 13;

  return (*wordPtr & mask) >> flagsOffset;
}

void setFlags(int *ipHeader, int flags) {
  int *wordPtr = ipHeader;
  wordPtr += 1;
  int flagsOffset = 13;
  int mask = 0x0000e000;
  int invMask = ~mask;     // Not ! but rather ~
  *wordPtr &= invMask;
  *wordPtr |= ((flags &0x07) << flagsOffset);


}

int getProtocol(int *ipHeader) {
  int *wordPtr = ipHeader;
  wordPtr += 2;
  int mask = 0x00ff0000;
  int protocolOffset = 16;

  return (*wordPtr & mask) >> protocolOffset;
}

void setProtocol (int *ipHeader, int protocol) {
  int *wordPtr = ipHeader;
  wordPtr += 2;
  int mask = 0x00ff0000;
  int invMask = ~mask;
  int protocolOffset = 16;

  *wordPtr &= invMask;
  *wordPtr |= ((protocol & 0xff) << protocolOffset);

}


int main(int argc, char **argv) {
  int ip[] = {0x4502007c,
              0xd4554000,
              0x31063f4e,
              0x9df0d736,
              0xc0a80007};

  printf("Flags: %x\n", getFlags(ip));

  printf("Protocol: %x\n", getProtocol(ip));

  printf("IP Header before resetting field\n");
  for (int idx = 0; idx < 5; idx++) {
    printf("ip[%d]: %08x\n", idx, ip[idx]);
  }

  setFlags (ip, 0x01);
  setProtocol (ip, 0x11); // UDP

  printf("IP Header after resetting field\n");
  for (int idx = 0; idx < 5; idx++) {
    printf("ip[%d]: %08x\n", idx, ip[idx]);
  }

}

