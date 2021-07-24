#include "code/code.hpp"
#include "libs/mc.hpp"
class Entity;

rawFunc<void *, 0x021cd500, void *, shared_ptr<void>, int, int> addEntityPacket;
rawFunc<void *, 0x0287f8b8, Entity *, Level *> Sheep;
__attribute__((always_inline)) inline void code() {
  auto mc = Minecraft::getInstance();

  int *a;
  decltype(a) b;
  asm volatile("_code_entity_:");
  b = new int;
  asm volatile("mr %0, %1" : "=r"(a), "+r"(b));
  asm volatile("_code_entity_2:");
  b = new int;
  asm volatile("mr %0, %1" : "=r"(a), "+r"(b));
  // shared_ptr<void> entity;
  // Sheep(nullptr, mc->lvl);

  // asm volatile("_code_packet_:");
  // shared_ptr<void> packet;
  // packet.ptr = addEntityPacket(nullptr, entity, 0, 0);
  //
  // asm volatile("_code_send_:");
  // mc->getConnection(0)->send(&packet);
}