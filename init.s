.section .init
.global init
  stwu    1,-8(1)
  mflr    0

  bl      getPC  
  
  lis     9,8192
  stw     3,0(9)
  
  addi    1,1,8
  mtlr    0
  blr

.global getPC
getPC:
    mflr 3
    blr