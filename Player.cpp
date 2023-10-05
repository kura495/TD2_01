#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initalize() { 
	model_ = std::make_unique<Model>();
	model_.reset(Model::Create());

	worldTransform_.Initialize();
}

void Player::Update() { 

	if (behaviorRequest_) {
		behavior_ = behaviorRequest_.value();
		switch (behavior_) {
		case Behavior::kRoot:
		default:
			BehaviorRootInitalize();
		case Behavior::kJump:
			BehaviorJumpInitalize();
		break;
		case Behavior::kDrop:
			BehaviorDropInitalize();
		break;
		}
		behaviorRequest_ = std::nullopt;
	}

	switch (behavior_) {
	case Behavior::kRoot:
	default:
		BehaviorRootUpdate();
	case Behavior::kJump:
		BehaviorJumpUpdate();
		break;
	case Behavior::kDrop:
		BehaviorDropUpdate();
		break;
	}
	worldTransform_.UpdateMatrix();
}

void Player::Draw(const ViewProjection& ViewProjection_) { 
	model_.get()->Draw(worldTransform_, ViewProjection_);
}

void Player::BehaviorRootInitalize() {

}

void Player::BehaviorRootUpdate() { 
	worldTransform_.translation_.y -= gravity; 
}

void Player::BehaviorJumpInitalize() {

}

void Player::BehaviorJumpUpdate() {

}

void Player::BehaviorDropInitalize() {

}

void Player::BehaviorDropUpdate() {

}


