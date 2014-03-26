case 0xEB:
if(size < 1) return -1;
printf("ex de,hl\n");
return 1;


case 0x08:
if(size < 1) return -1;
printf("ex af,af'\n");
return 1;


case 0xD9:
if(size < 1) return -1;
printf("exx \n");
return 1;


case 0xE3:
if(size < 1) return -1;
printf("ex (sp),hl\n");
return 1;


case 0xDD:
if(size < 2) return -1;
printf("ex (sp),ix\n");
return 2;


case 0xFD:
if(size < 2) return -1;
printf("ex (sp),iy\n");
return 2;


case 0xED:
if(size < 2) return -1;
switch(data[1]) {
case 0xB9:
if(size < 2) return -1;
printf("cpdr \n");
return 2;
case 0xA9:
if(size < 2) return -1;
printf("cpd \n");
return 2;
case 0xB1:
if(size < 2) return -1;
printf("cpir \n");
return 2;
case 0xA1:
if(size < 2) return -1;
printf("cpi \n");
return 2;
case 0xB8:
if(size < 2) return -1;
printf("lddr \n");
return 2;
case 0xA8:
if(size < 2) return -1;
printf("ldd \n");
return 2;
case 0xB0:
if(size < 2) return -1;
printf("ldir \n");
return 2;
case 0xA0:
if(size < 2) return -1;
printf("ldi \n");
return 2;
default:
return -1;
}


