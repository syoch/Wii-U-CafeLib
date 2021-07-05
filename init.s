.section .init
.global init
init:
  stwu    1,-8(1)
  mflr    0

  li 8, rodata_size
  srwi 8, 8, 2
  mtctr 8

  bl 4
  mflr 3
  addi 9, 3, text_end - . - 4

  lis 8, 0x1FFF
  ori 8, 8, 0xFFFC

  loop:
    lwzu 7, 4(9)
    stwu 7, 4(8)
    bdnz loop

  bl code
  addi    1,1,8
  mtlr    0
  blr