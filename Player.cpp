#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initalize() { 
	model_ = std::make_unique<Model>();
	model_.reset(Model::Create());

	worldTransform_.Initialize();
}

void Player::Update() { 
	worldTransform_.UpdateMatrix();
}

void Player::Draw(const ViewProjection& ViewProjection_) { 
	model_.get()->Draw(worldTransform_, ViewProjection_);
}
