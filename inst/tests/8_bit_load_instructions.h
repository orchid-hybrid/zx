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
default:
return -1;
}


case 0xFD:
if(size < 2) return -1;
switch(data[1]) {
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


