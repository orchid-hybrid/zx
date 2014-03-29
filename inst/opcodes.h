case 0x7F:
if(size < 1) return -1;
printf("ld a,a\n");
return 1;


case 0x78:
if(size < 1) return -1;
printf("ld a,b\n");
return 1;


case 0x79:
if(size < 1) return -1;
printf("ld a,c\n");
return 1;


case 0x7A:
if(size < 1) return -1;
printf("ld a,d\n");
return 1;


case 0x7B:
if(size < 1) return -1;
printf("ld a,e\n");
return 1;


case 0x7C:
if(size < 1) return -1;
printf("ld a,h\n");
return 1;


case 0x7D:
if(size < 1) return -1;
printf("ld a,l\n");
return 1;


case 0x47:
if(size < 1) return -1;
printf("ld b,a\n");
return 1;


case 0x40:
if(size < 1) return -1;
printf("ld b,b\n");
return 1;


case 0x41:
if(size < 1) return -1;
printf("ld b,c\n");
return 1;


case 0x42:
if(size < 1) return -1;
printf("ld b,d\n");
return 1;


case 0x43:
if(size < 1) return -1;
printf("ld b,e\n");
return 1;


case 0x44:
if(size < 1) return -1;
printf("ld b,h\n");
return 1;


case 0x45:
if(size < 1) return -1;
printf("ld b,l\n");
return 1;


case 0x4F:
if(size < 1) return -1;
printf("ld c,a\n");
return 1;


case 0x48:
if(size < 1) return -1;
printf("ld c,b\n");
return 1;


case 0x49:
if(size < 1) return -1;
printf("ld c,c\n");
return 1;


case 0x4A:
if(size < 1) return -1;
printf("ld c,d\n");
return 1;


case 0x4B:
if(size < 1) return -1;
printf("ld c,e\n");
return 1;


case 0x4C:
if(size < 1) return -1;
printf("ld c,h\n");
return 1;


case 0x4D:
if(size < 1) return -1;
printf("ld c,l\n");
return 1;


case 0x57:
if(size < 1) return -1;
printf("ld d,a\n");
return 1;


case 0x50:
if(size < 1) return -1;
printf("ld d,b\n");
return 1;


case 0x51:
if(size < 1) return -1;
printf("ld d,c\n");
return 1;


case 0x52:
if(size < 1) return -1;
printf("ld d,d\n");
return 1;


case 0x53:
if(size < 1) return -1;
printf("ld d,e\n");
return 1;


case 0x54:
if(size < 1) return -1;
printf("ld d,h\n");
return 1;


case 0x55:
if(size < 1) return -1;
printf("ld d,l\n");
return 1;


case 0x5F:
if(size < 1) return -1;
printf("ld e,a\n");
return 1;


case 0x58:
if(size < 1) return -1;
printf("ld e,b\n");
return 1;


case 0x59:
if(size < 1) return -1;
printf("ld e,c\n");
return 1;


case 0x5A:
if(size < 1) return -1;
printf("ld e,d\n");
return 1;


case 0x5B:
if(size < 1) return -1;
printf("ld e,e\n");
return 1;


case 0x5C:
if(size < 1) return -1;
printf("ld e,h\n");
return 1;


case 0x5D:
if(size < 1) return -1;
printf("ld e,l\n");
return 1;


case 0x67:
if(size < 1) return -1;
printf("ld h,a\n");
return 1;


case 0x60:
if(size < 1) return -1;
printf("ld h,b\n");
return 1;


case 0x61:
if(size < 1) return -1;
printf("ld h,c\n");
return 1;


case 0x62:
if(size < 1) return -1;
printf("ld h,d\n");
return 1;


case 0x63:
if(size < 1) return -1;
printf("ld h,e\n");
return 1;


case 0x64:
if(size < 1) return -1;
printf("ld h,h\n");
return 1;


case 0x65:
if(size < 1) return -1;
printf("ld h,l\n");
return 1;


case 0x6F:
if(size < 1) return -1;
printf("ld l,a\n");
return 1;


case 0x68:
if(size < 1) return -1;
printf("ld l,b\n");
return 1;


case 0x69:
if(size < 1) return -1;
printf("ld l,c\n");
return 1;


case 0x6A:
if(size < 1) return -1;
printf("ld l,d\n");
return 1;


case 0x6B:
if(size < 1) return -1;
printf("ld l,e\n");
return 1;


case 0x6C:
if(size < 1) return -1;
printf("ld l,h\n");
return 1;


case 0x6D:
if(size < 1) return -1;
printf("ld l,l\n");
return 1;


case 0x3E:
if(size < 2) return -1;
n = data[1];
printf("ld a,0x%02X\n", n);
return 2;


case 0x06:
if(size < 2) return -1;
n = data[1];
printf("ld b,0x%02X\n", n);
return 2;


case 0x0E:
if(size < 2) return -1;
n = data[1];
printf("ld c,0x%02X\n", n);
return 2;


case 0x16:
if(size < 2) return -1;
n = data[1];
printf("ld d,0x%02X\n", n);
return 2;


case 0x1E:
if(size < 2) return -1;
n = data[1];
printf("ld e,0x%02X\n", n);
return 2;


case 0x26:
if(size < 2) return -1;
n = data[1];
printf("ld h,0x%02X\n", n);
return 2;


case 0x2E:
if(size < 2) return -1;
n = data[1];
printf("ld l,0x%02X\n", n);
return 2;


case 0x7E:
if(size < 1) return -1;
printf("ld a,(hl)\n");
return 1;


case 0x46:
if(size < 1) return -1;
printf("ld b,(hl)\n");
return 1;


case 0x4E:
if(size < 1) return -1;
printf("ld c,(hl)\n");
return 1;


case 0x56:
if(size < 1) return -1;
printf("ld d,(hl)\n");
return 1;


case 0x5E:
if(size < 1) return -1;
printf("ld e,(hl)\n");
return 1;


case 0x66:
if(size < 1) return -1;
printf("ld h,(hl)\n");
return 1;


case 0x6E:
if(size < 1) return -1;
printf("ld l,(hl)\n");
return 1;


case 0xDD:
if(size < 2) return -1;
switch(data[1]) {
case 0xE9:
if(size < 2) return -1;
printf("jp (ix)\n");
return 2;
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
case 0x35:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("dec (ix+%d)\n", d);
return 3;
case 0x34:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("inc (ix+%d)\n", d);
return 3;
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
case 0xE3:
if(size < 2) return -1;
printf("ex (sp),ix\n");
return 2;
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
case 0x36:
if(size < 4) return -1;
d = ((signed char*)data)[2];
n = data[3];
printf("ld (ix+%d),0x%02X\n", d, n);
return 4;
case 0x75:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (ix+%d),l\n", d);
return 3;
case 0x74:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (ix+%d),h\n", d);
return 3;
case 0x73:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (ix+%d),e\n", d);
return 3;
case 0x72:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (ix+%d),d\n", d);
return 3;
case 0x71:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (ix+%d),c\n", d);
return 3;
case 0x70:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (ix+%d),b\n", d);
return 3;
case 0x77:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (ix+%d),a\n", d);
return 3;
case 0x6E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld l,(ix+%d)\n", d);
return 3;
case 0x66:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld h,(ix+%d)\n", d);
return 3;
case 0x5E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld e,(ix+%d)\n", d);
return 3;
case 0x56:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld d,(ix+%d)\n", d);
return 3;
case 0x4E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld c,(ix+%d)\n", d);
return 3;
case 0x46:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld b,(ix+%d)\n", d);
return 3;
case 0x7E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld a,(ix+%d)\n", d);
return 3;
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
case 0xE9:
if(size < 2) return -1;
printf("jp (iy)\n");
return 2;
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
case 0x35:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("dec (iy+%d)\n", d);
return 3;
case 0x34:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("inc (iy+%d)\n", d);
return 3;
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
case 0xE3:
if(size < 2) return -1;
printf("ex (sp),iy\n");
return 2;
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
case 0x36:
if(size < 4) return -1;
d = ((signed char*)data)[2];
n = data[3];
printf("ld (iy+%d),0x%02X\n", d, n);
return 4;
case 0x75:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (iy+%d),l\n", d);
return 3;
case 0x74:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (iy+%d),h\n", d);
return 3;
case 0x73:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (iy+%d),e\n", d);
return 3;
case 0x72:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (iy+%d),d\n", d);
return 3;
case 0x71:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (iy+%d),c\n", d);
return 3;
case 0x70:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (iy+%d),b\n", d);
return 3;
case 0x77:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld (iy+%d),a\n", d);
return 3;
case 0x6E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld l,(iy+%d)\n", d);
return 3;
case 0x66:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld h,(iy+%d)\n", d);
return 3;
case 0x5E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld e,(iy+%d)\n", d);
return 3;
case 0x56:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld d,(iy+%d)\n", d);
return 3;
case 0x4E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld c,(iy+%d)\n", d);
return 3;
case 0x46:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld b,(iy+%d)\n", d);
return 3;
case 0x7E:
if(size < 3) return -1;
d = ((signed char*)data)[2];
printf("ld a,(iy+%d)\n", d);
return 3;
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


case 0x77:
if(size < 1) return -1;
printf("ld (hl),a\n");
return 1;


case 0x70:
if(size < 1) return -1;
printf("ld (hl),b\n");
return 1;


case 0x71:
if(size < 1) return -1;
printf("ld (hl),c\n");
return 1;


case 0x72:
if(size < 1) return -1;
printf("ld (hl),d\n");
return 1;


case 0x73:
if(size < 1) return -1;
printf("ld (hl),e\n");
return 1;


case 0x74:
if(size < 1) return -1;
printf("ld (hl),h\n");
return 1;


case 0x75:
if(size < 1) return -1;
printf("ld (hl),l\n");
return 1;


case 0x36:
if(size < 2) return -1;
n = data[1];
printf("ld (hl),0x%02X\n", n);
return 2;


case 0x0A:
if(size < 1) return -1;
printf("ld a,(bc)\n");
return 1;


case 0x1A:
if(size < 1) return -1;
printf("ld a,(de)\n");
return 1;


case 0x3A:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld a,(0x%04X)\n", nn);
return 3;


case 0x02:
if(size < 1) return -1;
printf("ld (bc),a\n");
return 1;


case 0x12:
if(size < 1) return -1;
printf("ld (de),a\n");
return 1;


case 0x32:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld (0x%04X),a\n", nn);
return 3;


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
case 0x45:
if(size < 2) return -1;
printf("retn \n");
return 2;
case 0x4D:
if(size < 2) return -1;
printf("reti \n");
return 2;
case 0x67:
if(size < 2) return -1;
printf("rrd \n");
return 2;
case 0x6F:
if(size < 2) return -1;
printf("rld \n");
return 2;
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
case 0x4F:
if(size < 2) return -1;
printf("ld r,a\n");
return 2;
case 0x47:
if(size < 2) return -1;
printf("ld i,a\n");
return 2;
case 0x5F:
if(size < 2) return -1;
printf("ld a,r\n");
return 2;
case 0x57:
if(size < 2) return -1;
printf("ld a,i\n");
return 2;
default:
return -1;
}


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


case 0x2A:
if(size < 3) return -1;
nn = data[1] | data[2] << 8;
printf("ld hl,(0x%04X)\n", nn);
return 3;


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


case 0x3C:
if(size < 1) return -1;
printf("inc a\n");
return 1;


case 0x04:
if(size < 1) return -1;
printf("inc b\n");
return 1;


case 0x0C:
if(size < 1) return -1;
printf("inc c\n");
return 1;


case 0x14:
if(size < 1) return -1;
printf("inc d\n");
return 1;


case 0x1C:
if(size < 1) return -1;
printf("inc e\n");
return 1;


case 0x24:
if(size < 1) return -1;
printf("inc h\n");
return 1;


case 0x2C:
if(size < 1) return -1;
printf("inc l\n");
return 1;


case 0x34:
if(size < 1) return -1;
printf("inc (hl)\n");
return 1;


case 0x3D:
if(size < 1) return -1;
printf("dec a\n");
return 1;


case 0x05:
if(size < 1) return -1;
printf("dec b\n");
return 1;


case 0x0D:
if(size < 1) return -1;
printf("dec c\n");
return 1;


case 0x15:
if(size < 1) return -1;
printf("dec d\n");
return 1;


case 0x1D:
if(size < 1) return -1;
printf("dec e\n");
return 1;


case 0x25:
if(size < 1) return -1;
printf("dec h\n");
return 1;


case 0x2D:
if(size < 1) return -1;
printf("dec l\n");
return 1;


case 0x35:
if(size < 1) return -1;
printf("dec (hl)\n");
return 1;


case 0x27:
if(size < 1) return -1;
printf("daa \n");
return 1;


case 0x2F:
if(size < 1) return -1;
printf("cpl \n");
return 1;


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


case 0x10:
if(size < 2) return -1;
d = ((signed char*)data)[1];;
printf("djnz +%d\n", d);
return 2;


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


case 0xDB:
if(size < 2) return -1;
n = data[1];
printf("in a,(0x%02X)\n", n);
return 2;


case 0xD3:
if(size < 2) return -1;
n = data[1];
printf("out (0x%02X),a\n", n);
return 2;


