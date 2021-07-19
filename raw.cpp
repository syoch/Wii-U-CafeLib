#include "code.hpp"
#include "libs/mc.hpp"

void code() {
  uint32_t* mem = (uint32_t*)(0x20000000);
  auto mc = (Minecraft*)(0x109CD8E4);
  mem[0] = (uint32_t)mc->getConnection(0);
}