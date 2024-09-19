
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


int main(int argc, char **argv) {
  int ip[] = {0x4502007c,
              0xd4554000,
              0x31063f4e,
              0x9df0d736,
              0xc0a80007};

  printf("Flags: %x\n", getFlags(ip));

}

