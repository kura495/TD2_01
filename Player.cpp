#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initalize() { 
	model_.get()->Create();

	worldTransform_.Initialize();
}

void Player::Update() { worldTransform_. }

void Player::Draw() {

}
