case 0xCB:
if(size < 2) return -1;
switch(data[1]) {
case 0xBE:
if(size < 2) return -1;
printf("res 7,(hl)\n");
return 2;
case 0xB6:
if(size < 2) return -1;
printf("res 6,(hl)\n");
return 2;
case 0xAE:
if(size < 2) return -1;
printf("res 5,(hl)\n");
return 2;
case 0xA6:
if(size < 2) return -1;
printf("res 4,(hl)\n");
return 2;
case 0x9E:
if(size < 2) return -1;
printf("res 3,(hl)\n");
return 2;
case 0x96:
if(size < 2) return -1;
printf("res 2,(hl)\n");
return 2;
case 0x8E:
if(size < 2) return -1;
printf("res 1,(hl)\n");
return 2;
case 0x86:
if(size < 2) return -1;
printf("res 0,(hl)\n");
return 2;
case 0xBD:
if(size < 2) return -1;
printf("res 7,l\n");
return 2;
case 0xB5:
if(size < 2) return -1;
printf("res 6,l\n");
return 2;
case 0xAD:
if(size < 2) return -1;
printf("res 5,l\n");
return 2;
case 0xA5:
if(size < 2) return -1;
printf("res 4,l\n");
return 2;
case 0x9D:
if(size < 2) return -1;
printf("res 3,l\n");
return 2;
case 0x95:
if(size < 2) return -1;
printf("res 2,l\n");
return 2;
case 0x8D:
if(size < 2) return -1;
printf("res 1,l\n");
return 2;
case 0x85:
if(size < 2) return -1;
printf("res 0,l\n");
return 2;
case 0xBC:
if(size < 2) return -1;
printf("res 7,h\n");
return 2;
case 0xB4:
if(size < 2) return -1;
printf("res 6,h\n");
return 2;
case 0xAC:
if(size < 2) return -1;
printf("res 5,h\n");
return 2;
case 0xA4:
if(size < 2) return -1;
printf("res 4,h\n");
return 2;
case 0x9C:
if(size < 2) return -1;
printf("res 3,h\n");
return 2;
case 0x94:
if(size < 2) return -1;
printf("res 2,h\n");
return 2;
case 0x8C:
if(size < 2) return -1;
printf("res 1,h\n");
return 2;
case 0x84:
if(size < 2) return -1;
printf("res 0,h\n");
return 2;
case 0xBB:
if(size < 2) return -1;
printf("res 7,e\n");
return 2;
case 0xB3:
if(size < 2) return -1;
printf("res 6,e\n");
return 2;
case 0xAB:
if(size < 2) return -1;
printf("res 5,e\n");
return 2;
case 0xA3:
if(size < 2) return -1;
printf("res 4,e\n");
return 2;
case 0x9B:
if(size < 2) return -1;
printf("res 3,e\n");
return 2;
case 0x93:
if(size < 2) return -1;
printf("res 2,e\n");
return 2;
case 0x8B:
if(size < 2) return -1;
printf("res 1,e\n");
return 2;
case 0x83:
if(size < 2) return -1;
printf("res 0,e\n");
return 2;
case 0xBA:
if(size < 2) return -1;
printf("res 7,d\n");
return 2;
case 0xB2:
if(size < 2) return -1;
printf("res 6,d\n");
return 2;
case 0xAA:
if(size < 2) return -1;
printf("res 5,d\n");
return 2;
case 0xA2:
if(size < 2) return -1;
printf("res 4,d\n");
return 2;
case 0x9A:
if(size < 2) return -1;
printf("res 3,d\n");
return 2;
case 0x92:
if(size < 2) return -1;
printf("res 2,d\n");
return 2;
case 0x8A:
if(size < 2) return -1;
printf("res 1,d\n");
return 2;
case 0x82:
if(size < 2) return -1;
printf("res 0,d\n");
return 2;
case 0xB9:
if(size < 2) return -1;
printf("res 7,c\n");
return 2;
case 0xB1:
if(size < 2) return -1;
printf("res 6,c\n");
return 2;
case 0xA9:
if(size < 2) return -1;
printf("res 5,c\n");
return 2;
case 0xA1:
if(size < 2) return -1;
printf("res 4,c\n");
return 2;
case 0x99:
if(size < 2) return -1;
printf("res 3,c\n");
return 2;
case 0x91:
if(size < 2) return -1;
printf("res 2,c\n");
return 2;
case 0x89:
if(size < 2) return -1;
printf("res 1,c\n");
return 2;
case 0x81:
if(size < 2) return -1;
printf("res 0,c\n");
return 2;
case 0xB8:
if(size < 2) return -1;
printf("res 7,b\n");
return 2;
case 0xB0:
if(size < 2) return -1;
printf("res 6,b\n");
return 2;
case 0xA8:
if(size < 2) return -1;
printf("res 5,b\n");
return 2;
case 0xA0:
if(size < 2) return -1;
printf("res 4,b\n");
return 2;
case 0x98:
if(size < 2) return -1;
printf("res 3,b\n");
return 2;
case 0x90:
if(size < 2) return -1;
printf("res 2,b\n");
return 2;
case 0x88:
if(size < 2) return -1;
printf("res 1,b\n");
return 2;
case 0x80:
if(size < 2) return -1;
printf("res 0,b\n");
return 2;
case 0xBF:
if(size < 2) return -1;
printf("res 7,a\n");
return 2;
case 0xB7:
if(size < 2) return -1;
printf("res 6,a\n");
return 2;
case 0xAF:
if(size < 2) return -1;
printf("res 5,a\n");
return 2;
case 0xA7:
if(size < 2) return -1;
printf("res 4,a\n");
return 2;
case 0x9F:
if(size < 2) return -1;
printf("res 3,a\n");
return 2;
case 0x97:
if(size < 2) return -1;
printf("res 2,a\n");
return 2;
case 0x8F:
if(size < 2) return -1;
printf("res 1,a\n");
return 2;
case 0x87:
if(size < 2) return -1;
printf("res 0,a\n");
return 2;
case 0xFE:
if(size < 2) return -1;
printf("set 7,(hl)\n");
return 2;
case 0xF6:
if(size < 2) return -1;
printf("set 6,(hl)\n");
return 2;
case 0xEE:
if(size < 2) return -1;
printf("set 5,(hl)\n");
return 2;
case 0xE6:
if(size < 2) return -1;
printf("set 4,(hl)\n");
return 2;
case 0xDE:
if(size < 2) return -1;
printf("set 3,(hl)\n");
return 2;
case 0xD6:
if(size < 2) return -1;
printf("set 2,(hl)\n");
return 2;
case 0xCE:
if(size < 2) return -1;
printf("set 1,(hl)\n");
return 2;
case 0xC6:
if(size < 2) return -1;
printf("set 0,(hl)\n");
return 2;
case 0xFD:
if(size < 2) return -1;
printf("set 7,l\n");
return 2;
case 0xF5:
if(size < 2) return -1;
printf("set 6,l\n");
return 2;
case 0xED:
if(size < 2) return -1;
printf("set 5,l\n");
return 2;
case 0xE5:
if(size < 2) return -1;
printf("set 4,l\n");
return 2;
case 0xDD:
if(size < 2) return -1;
printf("set 3,l\n");
return 2;
case 0xD5:
if(size < 2) return -1;
printf("set 2,l\n");
return 2;
case 0xCD:
if(size < 2) return -1;
printf("set 1,l\n");
return 2;
case 0xC5:
if(size < 2) return -1;
printf("set 0,l\n");
return 2;
case 0xFC:
if(size < 2) return -1;
printf("set 7,h\n");
return 2;
case 0xF4:
if(size < 2) return -1;
printf("set 6,h\n");
return 2;
case 0xEC:
if(size < 2) return -1;
printf("set 5,h\n");
return 2;
case 0xE4:
if(size < 2) return -1;
printf("set 4,h\n");
return 2;
case 0xDC:
if(size < 2) return -1;
printf("set 3,h\n");
return 2;
case 0xD4:
if(size < 2) return -1;
printf("set 2,h\n");
return 2;
case 0xCC:
if(size < 2) return -1;
printf("set 1,h\n");
return 2;
case 0xC4:
if(size < 2) return -1;
printf("set 0,h\n");
return 2;
case 0xFB:
if(size < 2) return -1;
printf("set 7,e\n");
return 2;
case 0xF3:
if(size < 2) return -1;
printf("set 6,e\n");
return 2;
case 0xEB:
if(size < 2) return -1;
printf("set 5,e\n");
return 2;
case 0xE3:
if(size < 2) return -1;
printf("set 4,e\n");
return 2;
case 0xDB:
if(size < 2) return -1;
printf("set 3,e\n");
return 2;
case 0xD3:
if(size < 2) return -1;
printf("set 2,e\n");
return 2;
case 0xCB:
if(size < 2) return -1;
printf("set 1,e\n");
return 2;
case 0xC3:
if(size < 2) return -1;
printf("set 0,e\n");
return 2;
case 0xFA:
if(size < 2) return -1;
printf("set 7,d\n");
return 2;
case 0xF2:
if(size < 2) return -1;
printf("set 6,d\n");
return 2;
case 0xEA:
if(size < 2) return -1;
printf("set 5,d\n");
return 2;
case 0xE2:
if(size < 2) return -1;
printf("set 4,d\n");
return 2;
case 0xDA:
if(size < 2) return -1;
printf("set 3,d\n");
return 2;
case 0xD2:
if(size < 2) return -1;
printf("set 2,d\n");
return 2;
case 0xCA:
if(size < 2) return -1;
printf("set 1,d\n");
return 2;
case 0xC2:
if(size < 2) return -1;
printf("set 0,d\n");
return 2;
case 0xF9:
if(size < 2) return -1;
printf("set 7,c\n");
return 2;
case 0xF1:
if(size < 2) return -1;
printf("set 6,c\n");
return 2;
case 0xE9:
if(size < 2) return -1;
printf("set 5,c\n");
return 2;
case 0xE1:
if(size < 2) return -1;
printf("set 4,c\n");
return 2;
case 0xD9:
if(size < 2) return -1;
printf("set 3,c\n");
return 2;
case 0xD1:
if(size < 2) return -1;
printf("set 2,c\n");
return 2;
case 0xC9:
if(size < 2) return -1;
printf("set 1,c\n");
return 2;
case 0xC1:
if(size < 2) return -1;
printf("set 0,c\n");
return 2;
case 0xF8:
if(size < 2) return -1;
printf("set 7,b\n");
return 2;
case 0xF0:
if(size < 2) return -1;
printf("set 6,b\n");
return 2;
case 0xE8:
if(size < 2) return -1;
printf("set 5,b\n");
return 2;
case 0xE0:
if(size < 2) return -1;
printf("set 4,b\n");
return 2;
case 0xD8:
if(size < 2) return -1;
printf("set 3,b\n");
return 2;
case 0xD0:
if(size < 2) return -1;
printf("set 2,b\n");
return 2;
case 0xC8:
if(size < 2) return -1;
printf("set 1,b\n");
return 2;
case 0xC0:
if(size < 2) return -1;
printf("set 0,b\n");
return 2;
case 0xFF:
if(size < 2) return -1;
printf("set 7,a\n");
return 2;
case 0xF7:
if(size < 2) return -1;
printf("set 6,a\n");
return 2;
case 0xEF:
if(size < 2) return -1;
printf("set 5,a\n");
return 2;
case 0xE7:
if(size < 2) return -1;
printf("set 4,a\n");
return 2;
case 0xDF:
if(size < 2) return -1;
printf("set 3,a\n");
return 2;
case 0xD7:
if(size < 2) return -1;
printf("set 2,a\n");
return 2;
case 0xCF:
if(size < 2) return -1;
printf("set 1,a\n");
return 2;
case 0xC7:
if(size < 2) return -1;
printf("set 0,a\n");
return 2;
case 0x7E:
if(size < 2) return -1;
printf("bit 7,(hl)\n");
return 2;
case 0x76:
if(size < 2) return -1;
printf("bit 6,(hl)\n");
return 2;
case 0x6E:
if(size < 2) return -1;
printf("bit 5,(hl)\n");
return 2;
case 0x66:
if(size < 2) return -1;
printf("bit 4,(hl)\n");
return 2;
case 0x5E:
if(size < 2) return -1;
printf("bit 3,(hl)\n");
return 2;
case 0x56:
if(size < 2) return -1;
printf("bit 2,(hl)\n");
return 2;
case 0x4E:
if(size < 2) return -1;
printf("bit 1,(hl)\n");
return 2;
case 0x46:
if(size < 2) return -1;
printf("bit 0,(hl)\n");
return 2;
case 0x7D:
if(size < 2) return -1;
printf("bit 7,l\n");
return 2;
case 0x75:
if(size < 2) return -1;
printf("bit 6,l\n");
return 2;
case 0x6D:
if(size < 2) return -1;
printf("bit 5,l\n");
return 2;
case 0x65:
if(size < 2) return -1;
printf("bit 4,l\n");
return 2;
case 0x5D:
if(size < 2) return -1;
printf("bit 3,l\n");
return 2;
case 0x55:
if(size < 2) return -1;
printf("bit 2,l\n");
return 2;
case 0x4D:
if(size < 2) return -1;
printf("bit 1,l\n");
return 2;
case 0x45:
if(size < 2) return -1;
printf("bit 0,l\n");
return 2;
case 0x7C:
if(size < 2) return -1;
printf("bit 7,h\n");
return 2;
case 0x74:
if(size < 2) return -1;
printf("bit 6,h\n");
return 2;
case 0x6C:
if(size < 2) return -1;
printf("bit 5,h\n");
return 2;
case 0x64:
if(size < 2) return -1;
printf("bit 4,h\n");
return 2;
case 0x5C:
if(size < 2) return -1;
printf("bit 3,h\n");
return 2;
case 0x54:
if(size < 2) return -1;
printf("bit 2,h\n");
return 2;
case 0x4C:
if(size < 2) return -1;
printf("bit 1,h\n");
return 2;
case 0x44:
if(size < 2) return -1;
printf("bit 0,h\n");
return 2;
case 0x7B:
if(size < 2) return -1;
printf("bit 7,e\n");
return 2;
case 0x73:
if(size < 2) return -1;
printf("bit 6,e\n");
return 2;
case 0x6B:
if(size < 2) return -1;
printf("bit 5,e\n");
return 2;
case 0x63:
if(size < 2) return -1;
printf("bit 4,e\n");
return 2;
case 0x5B:
if(size < 2) return -1;
printf("bit 3,e\n");
return 2;
case 0x53:
if(size < 2) return -1;
printf("bit 2,e\n");
return 2;
case 0x4B:
if(size < 2) return -1;
printf("bit 1,e\n");
return 2;
case 0x43:
if(size < 2) return -1;
printf("bit 0,e\n");
return 2;
case 0x7A:
if(size < 2) return -1;
printf("bit 7,d\n");
return 2;
case 0x72:
if(size < 2) return -1;
printf("bit 6,d\n");
return 2;
case 0x6A:
if(size < 2) return -1;
printf("bit 5,d\n");
return 2;
case 0x62:
if(size < 2) return -1;
printf("bit 4,d\n");
return 2;
case 0x5A:
if(size < 2) return -1;
printf("bit 3,d\n");
return 2;
case 0x52:
if(size < 2) return -1;
printf("bit 2,d\n");
return 2;
case 0x4A:
if(size < 2) return -1;
printf("bit 1,d\n");
return 2;
case 0x42:
if(size < 2) return -1;
printf("bit 0,d\n");
return 2;
case 0x79:
if(size < 2) return -1;
printf("bit 7,c\n");
return 2;
case 0x71:
if(size < 2) return -1;
printf("bit 6,c\n");
return 2;
case 0x69:
if(size < 2) return -1;
printf("bit 5,c\n");
return 2;
case 0x61:
if(size < 2) return -1;
printf("bit 4,c\n");
return 2;
case 0x59:
if(size < 2) return -1;
printf("bit 3,c\n");
return 2;
case 0x51:
if(size < 2) return -1;
printf("bit 2,c\n");
return 2;
case 0x49:
if(size < 2) return -1;
printf("bit 1,c\n");
return 2;
case 0x41:
if(size < 2) return -1;
printf("bit 0,c\n");
return 2;
case 0x78:
if(size < 2) return -1;
printf("bit 7,b\n");
return 2;
case 0x70:
if(size < 2) return -1;
printf("bit 6,b\n");
return 2;
case 0x68:
if(size < 2) return -1;
printf("bit 5,b\n");
return 2;
case 0x60:
if(size < 2) return -1;
printf("bit 4,b\n");
return 2;
case 0x58:
if(size < 2) return -1;
printf("bit 3,b\n");
return 2;
case 0x50:
if(size < 2) return -1;
printf("bit 2,b\n");
return 2;
case 0x48:
if(size < 2) return -1;
printf("bit 1,b\n");
return 2;
case 0x40:
if(size < 2) return -1;
printf("bit 0,b\n");
return 2;
case 0x7F:
if(size < 2) return -1;
printf("bit 7,a\n");
return 2;
case 0x77:
if(size < 2) return -1;
printf("bit 6,a\n");
return 2;
case 0x6F:
if(size < 2) return -1;
printf("bit 5,a\n");
return 2;
case 0x67:
if(size < 2) return -1;
printf("bit 4,a\n");
return 2;
case 0x5F:
if(size < 2) return -1;
printf("bit 3,a\n");
return 2;
case 0x57:
if(size < 2) return -1;
printf("bit 2,a\n");
return 2;
case 0x4F:
if(size < 2) return -1;
printf("bit 1,a\n");
return 2;
case 0x47:
if(size < 2) return -1;
printf("bit 0,a\n");
return 2;
default:
return -1;
}


case 0xDD:
if(size < 2) return -1;
switch(data[1]) {
case 0xCB: // CB bitwise operators
  if(size < 4) return -1;
  d = ((signed char*)data)[2];
  switch(data[3]) {
case 0xBE:
printf("res 7,(ix+%d)\n", d);
return 4;
case 0xB6:
printf("res 6,(ix+%d)\n", d);
return 4;
case 0xAE:
printf("res 5,(ix+%d)\n", d);
return 4;
case 0xA6:
printf("res 4,(ix+%d)\n", d);
return 4;
case 0x9E:
printf("res 3,(ix+%d)\n", d);
return 4;
case 0x96:
printf("res 2,(ix+%d)\n", d);
return 4;
case 0x8E:
printf("res 1,(ix+%d)\n", d);
return 4;
case 0x86:
printf("res 0,(ix+%d)\n", d);
return 4;
case 0xFE:
printf("set 7,(ix+%d)\n", d);
return 4;
case 0xF6:
printf("set 6,(ix+%d)\n", d);
return 4;
case 0xEE:
printf("set 5,(ix+%d)\n", d);
return 4;
case 0xE6:
printf("set 4,(ix+%d)\n", d);
return 4;
case 0xDE:
printf("set 3,(ix+%d)\n", d);
return 4;
case 0xD6:
printf("set 2,(ix+%d)\n", d);
return 4;
case 0xCE:
printf("set 1,(ix+%d)\n", d);
return 4;
case 0xC6:
printf("set 0,(ix+%d)\n", d);
return 4;
case 0x7E:
printf("bit 7,(ix+%d)\n", d);
return 4;
case 0x76:
printf("bit 6,(ix+%d)\n", d);
return 4;
case 0x6E:
printf("bit 5,(ix+%d)\n", d);
return 4;
case 0x66:
printf("bit 4,(ix+%d)\n", d);
return 4;
case 0x5E:
printf("bit 3,(ix+%d)\n", d);
return 4;
case 0x56:
printf("bit 2,(ix+%d)\n", d);
return 4;
case 0x4E:
printf("bit 1,(ix+%d)\n", d);
return 4;
case 0x46:
printf("bit 0,(ix+%d)\n", d);
return 4;
  }

default:
return -1;
}


case 0xFD:
if(size < 2) return -1;
switch(data[1]) {
case 0xCB: // CB bitwise operators
  if(size < 4) return -1;
  d = ((signed char*)data)[2];
  switch(data[3]) {
case 0xBE:
printf("res 7,(iy+%d)\n", d);
return 4;
case 0xB6:
printf("res 6,(iy+%d)\n", d);
return 4;
case 0xAE:
printf("res 5,(iy+%d)\n", d);
return 4;
case 0xA6:
printf("res 4,(iy+%d)\n", d);
return 4;
case 0x9E:
printf("res 3,(iy+%d)\n", d);
return 4;
case 0x96:
printf("res 2,(iy+%d)\n", d);
return 4;
case 0x8E:
printf("res 1,(iy+%d)\n", d);
return 4;
case 0x86:
printf("res 0,(iy+%d)\n", d);
return 4;
case 0xFE:
printf("set 7,(iy+%d)\n", d);
return 4;
case 0xF6:
printf("set 6,(iy+%d)\n", d);
return 4;
case 0xEE:
printf("set 5,(iy+%d)\n", d);
return 4;
case 0xE6:
printf("set 4,(iy+%d)\n", d);
return 4;
case 0xDE:
printf("set 3,(iy+%d)\n", d);
return 4;
case 0xD6:
printf("set 2,(iy+%d)\n", d);
return 4;
case 0xCE:
printf("set 1,(iy+%d)\n", d);
return 4;
case 0xC6:
printf("set 0,(iy+%d)\n", d);
return 4;
case 0x7E:
printf("bit 7,(iy+%d)\n", d);
return 4;
case 0x76:
printf("bit 6,(iy+%d)\n", d);
return 4;
case 0x6E:
printf("bit 5,(iy+%d)\n", d);
return 4;
case 0x66:
printf("bit 4,(iy+%d)\n", d);
return 4;
case 0x5E:
printf("bit 3,(iy+%d)\n", d);
return 4;
case 0x56:
printf("bit 2,(iy+%d)\n", d);
return 4;
case 0x4E:
printf("bit 1,(iy+%d)\n", d);
return 4;
case 0x46:
printf("bit 0,(iy+%d)\n", d);
return 4;
  }

default:
return -1;
}


