case 0x07:
if(size < 1) return -1;
printf("rlca \n");
return 1;


case 0x17:
if(size < 1) return -1;
printf("rla \n");
return 1;


case 0x0F:
if(size < 1) return -1;
printf("rrca \n");
return 1;


case 0x1F:
if(size < 1) return -1;
printf("rra \n");
return 1;


case 0xCB:
if(size < 2) return -1;
switch(data[1]) {
case 0x3E:
if(size < 2) return -1;
printf("srl (hl)\n");
return 2;
case 0x3D:
if(size < 2) return -1;
printf("srl l\n");
return 2;
case 0x3C:
if(size < 2) return -1;
printf("srl h\n");
return 2;
case 0x3B:
if(size < 2) return -1;
printf("srl e\n");
return 2;
case 0x3A:
if(size < 2) return -1;
printf("srl d\n");
return 2;
case 0x39:
if(size < 2) return -1;
printf("srl c\n");
return 2;
case 0x38:
if(size < 2) return -1;
printf("srl b\n");
return 2;
case 0x3F:
if(size < 2) return -1;
printf("srl a\n");
return 2;
case 0x2E:
if(size < 2) return -1;
printf("sra (hl)\n");
return 2;
case 0x2D:
if(size < 2) return -1;
printf("sra l\n");
return 2;
case 0x2C:
if(size < 2) return -1;
printf("sra h\n");
return 2;
case 0x2B:
if(size < 2) return -1;
printf("sra e\n");
return 2;
case 0x2A:
if(size < 2) return -1;
printf("sra d\n");
return 2;
case 0x29:
if(size < 2) return -1;
printf("sra c\n");
return 2;
case 0x28:
if(size < 2) return -1;
printf("sra b\n");
return 2;
case 0x2F:
if(size < 2) return -1;
printf("sra a\n");
return 2;
case 0x26:
if(size < 2) return -1;
printf("sla (hl)\n");
return 2;
case 0x25:
if(size < 2) return -1;
printf("sla l\n");
return 2;
case 0x24:
if(size < 2) return -1;
printf("sla h\n");
return 2;
case 0x23:
if(size < 2) return -1;
printf("sla e\n");
return 2;
case 0x22:
if(size < 2) return -1;
printf("sla d\n");
return 2;
case 0x21:
if(size < 2) return -1;
printf("sla c\n");
return 2;
case 0x20:
if(size < 2) return -1;
printf("sla b\n");
return 2;
case 0x27:
if(size < 2) return -1;
printf("sla a\n");
return 2;
case 0x1E:
if(size < 2) return -1;
printf("rr (hl)\n");
return 2;
case 0x1D:
if(size < 2) return -1;
printf("rr l\n");
return 2;
case 0x1C:
if(size < 2) return -1;
printf("rr h\n");
return 2;
case 0x1B:
if(size < 2) return -1;
printf("rr e\n");
return 2;
case 0x1A:
if(size < 2) return -1;
printf("rr d\n");
return 2;
case 0x19:
if(size < 2) return -1;
printf("rr c\n");
return 2;
case 0x18:
if(size < 2) return -1;
printf("rr b\n");
return 2;
case 0x1F:
if(size < 2) return -1;
printf("rr a\n");
return 2;
case 0x0E:
if(size < 2) return -1;
printf("rrc (hl)\n");
return 2;
case 0x0D:
if(size < 2) return -1;
printf("rrc l\n");
return 2;
case 0x0C:
if(size < 2) return -1;
printf("rrc h\n");
return 2;
case 0x0B:
if(size < 2) return -1;
printf("rrc e\n");
return 2;
case 0x0A:
if(size < 2) return -1;
printf("rrc d\n");
return 2;
case 0x09:
if(size < 2) return -1;
printf("rrc c\n");
return 2;
case 0x08:
if(size < 2) return -1;
printf("rrc b\n");
return 2;
case 0x0F:
if(size < 2) return -1;
printf("rrc a\n");
return 2;
case 0x16:
if(size < 2) return -1;
printf("rl (hl)\n");
return 2;
case 0x15:
if(size < 2) return -1;
printf("rl l\n");
return 2;
case 0x14:
if(size < 2) return -1;
printf("rl h\n");
return 2;
case 0x13:
if(size < 2) return -1;
printf("rl e\n");
return 2;
case 0x12:
if(size < 2) return -1;
printf("rl d\n");
return 2;
case 0x11:
if(size < 2) return -1;
printf("rl c\n");
return 2;
case 0x10:
if(size < 2) return -1;
printf("rl b\n");
return 2;
case 0x17:
if(size < 2) return -1;
printf("rl a\n");
return 2;
case 0x06:
if(size < 2) return -1;
printf("rlc (hl)\n");
return 2;
case 0x05:
if(size < 2) return -1;
printf("rlc l\n");
return 2;
case 0x04:
if(size < 2) return -1;
printf("rlc h\n");
return 2;
case 0x03:
if(size < 2) return -1;
printf("rlc e\n");
return 2;
case 0x02:
if(size < 2) return -1;
printf("rlc d\n");
return 2;
case 0x01:
if(size < 2) return -1;
printf("rlc c\n");
return 2;
case 0x00:
if(size < 2) return -1;
printf("rlc b\n");
return 2;
case 0x07:
if(size < 2) return -1;
printf("rlc a\n");
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
case 0x3E:
printf("srl (ix+%d)\n", d);
return 4;
case 0x2E:
printf("sra (ix+%d)\n", d);
return 4;
case 0x26:
printf("sla (ix+%d)\n", d);
return 4;
case 0x1E:
printf("rr (ix+%d)\n", d);
return 4;
case 0x0E:
printf("rrc (ix+%d)\n", d);
return 4;
case 0x16:
printf("rl (ix+%d)\n", d);
return 4;
case 0x06:
printf("rlc (ix+%d)\n", d);
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
case 0x3E:
printf("srl (iy+%d)\n", d);
return 4;
case 0x2E:
printf("sra (iy+%d)\n", d);
return 4;
case 0x26:
printf("sla (iy+%d)\n", d);
return 4;
case 0x1E:
printf("rr (iy+%d)\n", d);
return 4;
case 0x0E:
printf("rrc (iy+%d)\n", d);
return 4;
case 0x16:
printf("rl (iy+%d)\n", d);
return 4;
case 0x06:
printf("rlc (iy+%d)\n", d);
return 4;
  }

default:
return -1;
}


case 0xED:
if(size < 2) return -1;
switch(data[1]) {
case 0x67:
if(size < 2) return -1;
printf("rrd \n");
return 2;
case 0x6F:
if(size < 2) return -1;
printf("rld \n");
return 2;
default:
return -1;
}


