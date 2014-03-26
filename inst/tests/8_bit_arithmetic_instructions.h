case 0x87:
if(size < 1) return -1;
printf("add a\n");
return 1;


case 0x80:
if(size < 1) return -1;
printf("add b\n");
return 1;


case 0x81:
if(size < 1) return -1;
printf("add c\n");
return 1;


case 0x82:
if(size < 1) return -1;
printf("add d\n");
return 1;


case 0x83:
if(size < 1) return -1;
printf("add e\n");
return 1;


case 0x84:
if(size < 1) return -1;
printf("add h\n");
return 1;


case 0x85:
if(size < 1) return -1;
printf("add l\n");
return 1;


case 0xC6:
if(size < 2) return -1;
n = data[1];
printf("add 0x%02X\n", n);
return 2;


case 0x86:
if(size < 1) return -1;
printf("add (hl)\n");
return 1;


case 0xDD:
if(size < 2) return -1;
switch(data[1]) {
case 0xBE:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("cp (ix+%d)\n", d);
return 3;
case 0xAE:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("xor (ix+%d)\n", d);
return 3;
case 0xB6:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("or (ix+%d)\n", d);
return 3;
case 0xA6:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("and (ix+%d)\n", d);
return 3;
case 0x9E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("sbc (ix+%d)\n", d);
return 3;
case 0x96:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("sub (ix+%d)\n", d);
return 3;
case 0x8E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("adc (ix+%d)\n", d);
return 3;
case 0x86:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("add (ix+%d)\n", d);
return 3;
default:
return -1;
}


case 0xFD:
if(size < 2) return -1;
switch(data[1]) {
case 0xBE:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("cp (iy+%d)\n", d);
return 3;
case 0xAE:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("xor (iy+%d)\n", d);
return 3;
case 0xB6:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("or (iy+%d)\n", d);
return 3;
case 0xA6:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("and (iy+%d)\n", d);
return 3;
case 0x9E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("sbc (iy+%d)\n", d);
return 3;
case 0x96:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("sub (iy+%d)\n", d);
return 3;
case 0x8E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("adc (iy+%d)\n", d);
return 3;
case 0x86:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("add (iy+%d)\n", d);
return 3;
default:
return -1;
}


case 0x8F:
if(size < 1) return -1;
printf("adc a\n");
return 1;


case 0x88:
if(size < 1) return -1;
printf("adc b\n");
return 1;


case 0x89:
if(size < 1) return -1;
printf("adc c\n");
return 1;


case 0x8A:
if(size < 1) return -1;
printf("adc d\n");
return 1;


case 0x8B:
if(size < 1) return -1;
printf("adc e\n");
return 1;


case 0x8C:
if(size < 1) return -1;
printf("adc h\n");
return 1;


case 0x8D:
if(size < 1) return -1;
printf("adc l\n");
return 1;


case 0xCE:
if(size < 2) return -1;
n = data[1];
printf("adc 0x%02X\n", n);
return 2;


case 0x8E:
if(size < 1) return -1;
printf("adc (hl)\n");
return 1;


case 0x97:
if(size < 1) return -1;
printf("sub a\n");
return 1;


case 0x90:
if(size < 1) return -1;
printf("sub b\n");
return 1;


case 0x91:
if(size < 1) return -1;
printf("sub c\n");
return 1;


case 0x92:
if(size < 1) return -1;
printf("sub d\n");
return 1;


case 0x93:
if(size < 1) return -1;
printf("sub e\n");
return 1;


case 0x94:
if(size < 1) return -1;
printf("sub h\n");
return 1;


case 0x95:
if(size < 1) return -1;
printf("sub l\n");
return 1;


case 0xD6:
if(size < 2) return -1;
n = data[1];
printf("sub 0x%02X\n", n);
return 2;


case 0x96:
if(size < 1) return -1;
printf("sub (hl)\n");
return 1;


case 0x9F:
if(size < 1) return -1;
printf("sbc a\n");
return 1;


case 0x98:
if(size < 1) return -1;
printf("sbc b\n");
return 1;


case 0x99:
if(size < 1) return -1;
printf("sbc c\n");
return 1;


case 0x9A:
if(size < 1) return -1;
printf("sbc d\n");
return 1;


case 0x9B:
if(size < 1) return -1;
printf("sbc e\n");
return 1;


case 0x9C:
if(size < 1) return -1;
printf("sbc h\n");
return 1;


case 0x9D:
if(size < 1) return -1;
printf("sbc l\n");
return 1;


case 0xDE:
if(size < 2) return -1;
n = data[1];
printf("sbc 0x%02X\n", n);
return 2;


case 0x9E:
if(size < 1) return -1;
printf("sbc (hl)\n");
return 1;


case 0xA7:
if(size < 1) return -1;
printf("and a\n");
return 1;


case 0xA0:
if(size < 1) return -1;
printf("and b\n");
return 1;


case 0xA1:
if(size < 1) return -1;
printf("and c\n");
return 1;


case 0xA2:
if(size < 1) return -1;
printf("and d\n");
return 1;


case 0xA3:
if(size < 1) return -1;
printf("and e\n");
return 1;


case 0xA4:
if(size < 1) return -1;
printf("and h\n");
return 1;


case 0xA5:
if(size < 1) return -1;
printf("and l\n");
return 1;


case 0xE6:
if(size < 2) return -1;
n = data[1];
printf("and 0x%02X\n", n);
return 2;


case 0xA6:
if(size < 1) return -1;
printf("and (hl)\n");
return 1;


case 0xB7:
if(size < 1) return -1;
printf("or a\n");
return 1;


case 0xB0:
if(size < 1) return -1;
printf("or b\n");
return 1;


case 0xB1:
if(size < 1) return -1;
printf("or c\n");
return 1;


case 0xB2:
if(size < 1) return -1;
printf("or d\n");
return 1;


case 0xB3:
if(size < 1) return -1;
printf("or e\n");
return 1;


case 0xB4:
if(size < 1) return -1;
printf("or h\n");
return 1;


case 0xB5:
if(size < 1) return -1;
printf("or l\n");
return 1;


case 0xF6:
if(size < 2) return -1;
n = data[1];
printf("or 0x%02X\n", n);
return 2;


case 0xB6:
if(size < 1) return -1;
printf("or (hl)\n");
return 1;


case 0xAF:
if(size < 1) return -1;
printf("xor a\n");
return 1;


case 0xA8:
if(size < 1) return -1;
printf("xor b\n");
return 1;


case 0xA9:
if(size < 1) return -1;
printf("xor c\n");
return 1;


case 0xAA:
if(size < 1) return -1;
printf("xor d\n");
return 1;


case 0xAB:
if(size < 1) return -1;
printf("xor e\n");
return 1;


case 0xAC:
if(size < 1) return -1;
printf("xor h\n");
return 1;


case 0xAD:
if(size < 1) return -1;
printf("xor l\n");
return 1;


case 0xEE:
if(size < 2) return -1;
n = data[1];
printf("xor 0x%02X\n", n);
return 2;


case 0xAE:
if(size < 1) return -1;
printf("xor (hl)\n");
return 1;


case 0xBF:
if(size < 1) return -1;
printf("cp a\n");
return 1;


case 0xB8:
if(size < 1) return -1;
printf("cp b\n");
return 1;


case 0xB9:
if(size < 1) return -1;
printf("cp c\n");
return 1;


case 0xBA:
if(size < 1) return -1;
printf("cp d\n");
return 1;


case 0xBB:
if(size < 1) return -1;
printf("cp e\n");
return 1;


case 0xBC:
if(size < 1) return -1;
printf("cp h\n");
return 1;


case 0xBD:
if(size < 1) return -1;
printf("cp l\n");
return 1;


case 0xFE:
if(size < 2) return -1;
n = data[1];
printf("cp 0x%02X\n", n);
return 2;


case 0xBE:
if(size < 1) return -1;
printf("cp (hl)\n");
return 1;


