case 0x09:
if(size < 1) return -1;
printf("add hl,bc\n");
return 1;


case 0x19:
if(size < 1) return -1;
printf("add hl,de\n");
return 1;


case 0x29:
if(size < 1) return -1;
printf("add hl,hl\n");
return 1;


case 0x39:
if(size < 1) return -1;
printf("add hl,sp\n");
return 1;


case 0xED:
if(size < 2) return -1;
switch(data[1]) {
case 0x72:
if(size < 2) return -1;
printf("sbc hl,sp\n");
return 2;
case 0x62:
if(size < 2) return -1;
printf("sbc hl,hl\n");
return 2;
case 0x52:
if(size < 2) return -1;
printf("sbc hl,de\n");
return 2;
case 0x42:
if(size < 2) return -1;
printf("sbc hl,bc\n");
return 2;
case 0x7A:
if(size < 2) return -1;
printf("adc hl,sp\n");
return 2;
case 0x6A:
if(size < 2) return -1;
printf("adc hl,hl\n");
return 2;
case 0x5A:
if(size < 2) return -1;
printf("adc hl,de\n");
return 2;
case 0x4A:
if(size < 2) return -1;
printf("adc hl,bc\n");
return 2;
default:
return -1;
}


case 0xDD:
if(size < 2) return -1;
switch(data[1]) {
case 0x2B:
if(size < 2) return -1;
printf("dec ix\n");
return 2;
case 0x23:
if(size < 2) return -1;
printf("inc ix\n");
return 2;
case 0x39:
if(size < 2) return -1;
printf("add ix,sp\n");
return 2;
case 0x29:
if(size < 2) return -1;
printf("add ix,ix\n");
return 2;
case 0x19:
if(size < 2) return -1;
printf("add ix,de\n");
return 2;
case 0x09:
if(size < 2) return -1;
printf("add ix,bc\n");
return 2;
default:
return -1;
}


case 0xFD:
if(size < 2) return -1;
switch(data[1]) {
case 0x2B:
if(size < 2) return -1;
printf("dec iy\n");
return 2;
case 0x23:
if(size < 2) return -1;
printf("inc iy\n");
return 2;
case 0x39:
if(size < 2) return -1;
printf("add iy,sp\n");
return 2;
case 0x29:
if(size < 2) return -1;
printf("add iy,iy\n");
return 2;
case 0x19:
if(size < 2) return -1;
printf("add iy,de\n");
return 2;
case 0x09:
if(size < 2) return -1;
printf("add iy,bc\n");
return 2;
default:
return -1;
}


case 0x03:
if(size < 1) return -1;
printf("inc bc\n");
return 1;


case 0x13:
if(size < 1) return -1;
printf("inc de\n");
return 1;


case 0x23:
if(size < 1) return -1;
printf("inc hl\n");
return 1;


case 0x33:
if(size < 1) return -1;
printf("inc sp\n");
return 1;


case 0x0B:
if(size < 1) return -1;
printf("dec bc\n");
return 1;


case 0x1B:
if(size < 1) return -1;
printf("dec de\n");
return 1;


case 0x2B:
if(size < 1) return -1;
printf("dec hl\n");
return 1;


case 0x3B:
if(size < 1) return -1;
printf("dec sp\n");
return 1;


