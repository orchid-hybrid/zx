case 0x27:
if(size < 1) return -1;
printf("daa \n");
return 1;


case 0x2F:
if(size < 1) return -1;
printf("cpl \n");
return 1;


case 0xED:
if(size < 2) return -1;
switch(data[1]) {
case 0x5E:
if(size < 2) return -1;
printf("im 2\n");
return 2;
case 0x56:
if(size < 2) return -1;
printf("im 1\n");
return 2;
case 0x46:
if(size < 2) return -1;
printf("im 0\n");
return 2;
case 0x44:
if(size < 2) return -1;
printf("neg \n");
return 2;
default:
return -1;
}


case 0x3F:
if(size < 1) return -1;
printf("ccf \n");
return 1;


case 0x37:
if(size < 1) return -1;
printf("scf \n");
return 1;


case 0x00:
if(size < 1) return -1;
printf("nop \n");
return 1;


case 0x76:
if(size < 1) return -1;
printf("halt \n");
return 1;


case 0xF3:
if(size < 1) return -1;
printf("di \n");
return 1;


case 0xFB:
if(size < 1) return -1;
printf("ei \n");
return 1;


