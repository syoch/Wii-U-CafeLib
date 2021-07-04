.section .init
.global init
init:
  stwu    1,-8(1)
  mflr    0

  bl      getPC
  addi 3, 3, -0x0c+rodata_start
  ; r3 = init

  lis 9, 0x2000 
  
  lwz 10,0(3)
  stw 10,0(9)

  addi    1,1,8
  mtlr    0
  blr

.global getPC
getPC:
    mflr 3
    blr