case 0xDB:
if(size < 2) return -1;
n = data[1];
printf("in a,(0x%02X)\n", n);
return 2;


case 0xED:
if(size < 2) return -1;
switch(data[1]) {
case 0xBB:
if(size < 2) return -1;
printf("otdr \n");
return 2;
case 0xAB:
if(size < 2) return -1;
printf("outd \n");
return 2;
case 0xB3:
if(size < 2) return -1;
printf("otir \n");
return 2;
case 0xA3:
if(size < 2) return -1;
printf("outi \n");
return 2;
case 0x69:
if(size < 2) return -1;
printf("out (c),l\n");
return 2;
case 0x61:
if(size < 2) return -1;
printf("out (c),h\n");
return 2;
case 0x59:
if(size < 2) return -1;
printf("out (c),e\n");
return 2;
case 0x51:
if(size < 2) return -1;
printf("out (c),d\n");
return 2;
case 0x49:
if(size < 2) return -1;
printf("out (c),c\n");
return 2;
case 0x41:
if(size < 2) return -1;
printf("out (c),b\n");
return 2;
case 0x79:
if(size < 2) return -1;
printf("out (c),a\n");
return 2;
case 0xBA:
if(size < 2) return -1;
printf("indr \n");
return 2;
case 0xAA:
if(size < 2) return -1;
printf("ind \n");
return 2;
case 0xB2:
if(size < 2) return -1;
printf("inir \n");
return 2;
case 0xA2:
if(size < 2) return -1;
printf("ini \n");
return 2;
case 0x68:
if(size < 2) return -1;
printf("in l,(c)\n");
return 2;
case 0x60:
if(size < 2) return -1;
printf("in h,(c)\n");
return 2;
case 0x58:
if(size < 2) return -1;
printf("in e,(c)\n");
return 2;
case 0x50:
if(size < 2) return -1;
printf("in d,(c)\n");
return 2;
case 0x48:
if(size < 2) return -1;
printf("in c,(c)\n");
return 2;
case 0x40:
if(size < 2) return -1;
printf("in b,(c)\n");
return 2;
case 0x78:
if(size < 2) return -1;
printf("in a,(c)\n");
return 2;
default:
return -1;
}


case 0xD3:
if(size < 2) return -1;
n = data[1];
printf("out (0x%02X),a\n", n);
return 2;


