case 0x01:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld bc,0x%04X\n", nn);
return 3;


case 0x11:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld de,0x%04X\n", nn);
return 3;


case 0x21:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld hl,0x%04X\n", nn);
return 3;


case 0x31:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld sp,0x%04X\n", nn);
return 3;


case 0xDD:
if(size < 2) return -1;
switch(data[1]) {
case 0xE1:
if(size < 2) return -1;
printf("pop ix\n");
return 2;
case 0xE5:
if(size < 2) return -1;
printf("push ix\n");
return 2;
case 0xF9:
if(size < 2) return -1;
printf("ld sp,ix\n");
return 2;
case 0x22:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld (0x%04X),ix\n", nn);
return 4;
case 0x2A:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld ix,(0x%04X)\n", nn);
return 4;
case 0x21:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld ix,0x%04X\n", nn);
return 4;
default:
return -1;
}


case 0xFD:
if(size < 2) return -1;
switch(data[1]) {
case 0xE1:
if(size < 2) return -1;
printf("pop iy\n");
return 2;
case 0xE5:
if(size < 2) return -1;
printf("push iy\n");
return 2;
case 0xF9:
if(size < 2) return -1;
printf("ld sp,iy\n");
return 2;
case 0x22:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld (0x%04X),iy\n", nn);
return 4;
case 0x2A:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld iy,(0x%04X)\n", nn);
return 4;
case 0x21:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld iy,0x%04X\n", nn);
return 4;
default:
return -1;
}


case 0x2A:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld hl,(0x%04X)\n", nn);
return 3;


case 0xED:
if(size < 2) return -1;
switch(data[1]) {
case 0x73:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld (0x%04X),sp\n", nn);
return 4;
case 0x63:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld (0x%04X),hl\n", nn);
return 4;
case 0x53:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld (0x%04X),de\n", nn);
return 4;
case 0x43:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld (0x%04X),bc\n", nn);
return 4;
case 0x7B:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld sp,(0x%04X)\n", nn);
return 4;
case 0x6B:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld hl,(0x%04X)\n", nn);
return 4;
case 0x5B:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld de,(0x%04X)\n", nn);
return 4;
case 0x4B:
if(size < 4) return -1;
nn = data[2] | data[3] << 8;
printf("ld bc,(0x%04X)\n", nn);
return 4;
default:
return -1;
}


case 0x22:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld (0x%04X),hl\n", nn);
return 3;


case 0xF9:
if(size < 1) return -1;
printf("ld sp,hl\n");
return 1;


case 0xC5:
if(size < 1) return -1;
printf("push bc\n");
return 1;


case 0xD5:
if(size < 1) return -1;
printf("push de\n");
return 1;


case 0xE5:
if(size < 1) return -1;
printf("push hl\n");
return 1;


case 0xF5:
if(size < 1) return -1;
printf("push af\n");
return 1;


case 0xC1:
if(size < 1) return -1;
printf("pop bc\n");
return 1;


case 0xD1:
if(size < 1) return -1;
printf("pop de\n");
return 1;


case 0xE1:
if(size < 1) return -1;
printf("pop hl\n");
return 1;


case 0xF1:
if(size < 1) return -1;
printf("pop af\n");
return 1;


