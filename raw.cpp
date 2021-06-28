#include "rawFunc.cpp"

namespace Minecraft
{
  rawFunc<uint32_t *, 0x03166818> getInstance;
} // namespace Minecraft

void code()
{
  *((uint32_t **)0x20000000) = Minecraft::getInstance();
}