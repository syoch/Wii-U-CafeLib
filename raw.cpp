#include "code.hpp"
#include "libs/mc.hpp"

void code() {
  shared_ptr<void *> str;
  shared_ptr<void *> packet;
  shared_ptr<LocalPlayer> player;

  mc->GetPlayerByPlayerIndex(1, &player);
  giveCommand_preparePacket(&packet, &player, 1, 64 * 5 * 9, 3, &str);
  mc->getConnection(0)->send(&packet);
}