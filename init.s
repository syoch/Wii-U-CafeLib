.section .init

.global GetTextEnd
GetTextEnd:
  mflr    0

  bl 4
  mflr 3
  addi 3, 3, text_end - . - 4

  mtlr    0
  blr