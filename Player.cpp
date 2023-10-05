#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initalize() { 
	model_.get()->Create();

	worldTransform_.Initialize();
}

void Player::Update() { 
	worldTransform_.UpdateMatrix();
}

void Player::Draw(ViewProjection ViewProjection_) { 
	model_.get()->Draw(worldTransform_, ViewProjection_);
}
