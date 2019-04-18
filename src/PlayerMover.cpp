#include "PlayerMover.h"
#include "Player.h"

using namespace game;

PlayerMover::PlayerMover(const Player& player) :
EntityBehavior("PlayerMover", player.getName())
{
}

void PlayerMover::awake()
{

}

void PlayerMover::update()
{

}