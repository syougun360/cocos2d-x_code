#include "Player.h"
#include "PlayerMover.h"
#include "Random.h"
#include "PlayerChild.h"
#include "KeyEvent.h"
#include "TouchEvent.h"
#include "Screen.h"
#include "iTween.h"

using namespace game;

Player::Player(NodePtr node, std::string name) :
EntityHierarchy(node,name, Tags::Player, SortingLayer::Player)
{

}

void Player::awake()
{
	addChild(std::make_shared<PlayerChild>(this));

	label = std::make_unique<Label>(this, "ƒ^ƒCƒgƒ‹ Manager", FontAssets::getFont(Resources::FontID::MarkerFelt), 60);

	cocos2d::Size visibleSize = Screen::getVisibleSize();
	cocos2d::Vec2 origin = Screen::getVisibleOriginPosition();

	label->setTransform(Transform(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().y)));

}

void Player::start()
{
	auto spriteEmpty = std::make_unique<Sprite>(this, Rect(0, 0, 200, 200), Color3(100, 100, 100));
	auto tex = TextureAssets::getTexture(Resources::TextureID::HelloWorld);
	sprite = std::make_unique<Sprite>(this, tex);

	point = std::make_unique<Point>(this);
	triangle = std::make_unique<Triangle>(this, Vec2(300, 300), Vec2(500, 300), Vec2(500, 100));

	box = std::make_unique<Box>(this);

}


void Player::update()
{

	box->setTransform(Transform(Vec2(500, 300), Vec2(100, 100)));
	point->setTransform(Transform(Vec2(700, 200), Vec2(50, 50)));

	if (KeyEvent::isClick(KeyCode::KEY_M))
	{
		iTween::MoveTo(sprite->GetNode(), Vec2(Random::Range(0.0f, 500.0f), Random::Range(0.0f, 500.0f)), 1);
	}
	if (KeyEvent::isRelease(KeyCode::KEY_B))
	{
		label->setColor(Color4(255, 255, 0, 255));
	}

}
