#include "code.hpp"
#include "libs/mc.hpp"

__attribute__((always_inline)) void code() {
  auto mc = Minecraft::getInstance();

  shared_ptr<void *> str;
  shared_ptr<void *> packet;
  shared_ptr<LocalPlayer> player;

  mc->GetPlayerByPlayerIndex(1, &player);
  giveCommand_preparePacket(&packet, &player, 1, 64 * 5 * 9, 3, &str);
  mc->getConnection(0)->send(&packet);
}