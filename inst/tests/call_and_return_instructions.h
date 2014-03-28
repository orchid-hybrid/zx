case 0xCD:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call 0x%04X\n", nn);
return 3;


case 0xC4:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call nz,0x%04X\n", nn);
return 3;


case 0xCC:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call z,0x%04X\n", nn);
return 3;


case 0xD4:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call nc,0x%04X\n", nn);
return 3;


case 0xDC:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call c,0x%04X\n", nn);
return 3;


case 0xE4:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call po,0x%04X\n", nn);
return 3;


case 0xEC:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call pe,0x%04X\n", nn);
return 3;


case 0xF4:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call p,0x%04X\n", nn);
return 3;


case 0xFC:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("call m,0x%04X\n", nn);
return 3;


case 0xC9:
if(size < 1) return -1;
printf("ret \n");
return 1;


case 0xC0:
if(size < 1) return -1;
printf("ret nz\n");
return 1;


case 0xC8:
if(size < 1) return -1;
printf("ret z\n");
return 1;


case 0xD0:
if(size < 1) return -1;
printf("ret nc\n");
return 1;


case 0xD8:
if(size < 1) return -1;
printf("ret c\n");
return 1;


case 0xE0:
if(size < 1) return -1;
printf("ret po\n");
return 1;


case 0xE8:
if(size < 1) return -1;
printf("ret pe\n");
return 1;


case 0xF0:
if(size < 1) return -1;
printf("ret p\n");
return 1;


case 0xF8:
if(size < 1) return -1;
printf("ret m\n");
return 1;


case 0xED:
if(size < 2) return -1;
switch(data[1]) {
case 0x45:
if(size < 2) return -1;
printf("retn \n");
return 2;
case 0x4D:
if(size < 2) return -1;
printf("reti \n");
return 2;
default:
return -1;
}


case 0xC7:
if(size < 1) return -1;
printf("rst 0\n");
return 1;


case 0xCF:
if(size < 1) return -1;
printf("rst 8\n");
return 1;


case 0xD7:
if(size < 1) return -1;
printf("rst 16\n");
return 1;


case 0xDF:
if(size < 1) return -1;
printf("rst 24\n");
return 1;


case 0xE7:
if(size < 1) return -1;
printf("rst 32\n");
return 1;


case 0xEF:
if(size < 1) return -1;
printf("rst 40\n");
return 1;


case 0xF7:
if(size < 1) return -1;
printf("rst 48\n");
return 1;


case 0xFF:
if(size < 1) return -1;
printf("rst 56\n");
return 1;


