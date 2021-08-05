#include "code/code.hpp"
#include "libs/mc.hpp"

class ClientboundBlockDestructionPacket : public Packet {
 public:
  ClientboundBlockDestructionPacket() { ctor(this); }
  ClientboundBlockDestructionPacket(int a, BlockPos const &pos, int progress) {
    ctor_pos(this, a, pos, progress);
  }

  uint32_t unk__1;
  uint32_t unk__2;
  uint32_t id;
  BlockPos pos;
  uint32_t progress;
  uint32_t unk__3;

  static rawFunc<void *, 0x021e17e8, ClientboundBlockDestructionPacket *> ctor;
  static rawFunc<void *, 0x021e18d4, ClientboundBlockDestructionPacket *, int,
                 BlockPos const &, int>
      ctor_pos;
};

inline void main() {
  ClientPacketListener *listener = Minecraft::getInstance()->getConnection(0);

  // if (r > 5) {
  //     mc_boost::shared_ptr<mc::Packet>
  //     packet1(mc::ServerboundMovePlayerPosPacket::__ct(
  //         nullptr, pos.x, pos.y + 1, 0.0f, pos.z, true, true));
  //     listener->send(packet1);
  // }
  shared_ptr<Packet> packet2(mc::ServerboundPlayerActionPacket::__ct(
      nullptr, mc::ServerboundPlayerActionPacket::Action::startDestroyBlock,
      pos, *(mc::Direction **)0x109C46A4, 0));

  listener->send(packet2);
  return 0;
  // auto packet = ClientboundBlockDestructionPacket::ctor_pos(
  //     nullptr, 0, *BlockPos::ctor_(0, 396, 65, -318), 0);
  // Minecraft::getInstance()->getConnection(0)->send(packet);
}
/*
extern "C" void
startup() {
  auto mc = Minecraft::getInstance();

  shared_ptr<void *> str;
  shared_ptr<void *> packet;

  shared_ptr<LocalPlayer> player;
  mc->GetPlayerByPlayerIndex(1, &player);

  giveCommand_preparePacket(&packet, &player, 1, 64 * 5 * 9, 3, &str);

  mc->getConnection(0)->send(&packet);
}
*/