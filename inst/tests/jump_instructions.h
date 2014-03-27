case 0xC3:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp 0x%04X\n", nn);
return 3;


case 0xC2:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp nz,0x%04X\n", nn);
return 3;


case 0xCA:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp z,0x%04X\n", nn);
return 3;


case 0xD2:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp nc,0x%04X\n", nn);
return 3;


case 0xDA:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp c,0x%04X\n", nn);
return 3;


case 0xE2:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp po,0x%04X\n", nn);
return 3;


case 0xEA:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp pe,0x%04X\n", nn);
return 3;


case 0xF2:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp p,0x%04X\n", nn);
return 3;


case 0xFA:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("jp m,0x%04X\n", nn);
return 3;


case 0x18:
if(size < 2) return -1;
d = ((signed char*)data)[1];;
printf("jr +%d\n", d);
return 2;


case 0x38:
if(size < 2) return -1;
d = ((signed char*)data)[1];;
printf("jr c,+%d\n", d);
return 2;


case 0x30:
if(size < 2) return -1;
d = ((signed char*)data)[1];;
printf("jr nc,+%d\n", d);
return 2;


case 0x28:
if(size < 2) return -1;
d = ((signed char*)data)[1];;
printf("jr z,+%d\n", d);
return 2;


case 0x20:
if(size < 2) return -1;
d = ((signed char*)data)[1];;
printf("jr nz,+%d\n", d);
return 2;


case 0xE9:
if(size < 1) return -1;
printf("jp (hl)\n");
return 1;


case 0xDD:
if(size < 2) return -1;
printf("jp (ix)\n");
return 2;


case 0xFD:
if(size < 2) return -1;
printf("jp (iy)\n");
return 2;


case 0x10:
if(size < 2) return -1;
d = ((signed char*)data)[1];;
printf("djnz +%d\n", d);
return 2;


