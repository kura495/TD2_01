#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initalize() { 
	model_ = std::make_unique<Model>();
	model_.reset(Model::Create());

	worldTransform_.Initialize();

	input = Input::GetInstance();
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
	worldTransform_.translation_.x += moveXaxisSpeed; 

	//スペースを押すとジャンプする
	if ((input->PushKey(DIK_SPACE))) {
		behaviorRequest_ = Behavior::kJump;
	}
}

void Player::BehaviorJumpInitalize() { 
	behavior_ = Behavior::kJump;
	Jumpforce = 1.0f;
}

void Player::BehaviorJumpUpdate() { 
	
	worldTransform_.translation_.y += Jumpforce;
	Jumpforce -= gravity;
	if (input->PushKey(DIK_SPACE)) {
		Jumpforce = 1.0f;
	}
}

void Player::BehaviorDropInitalize() {

}

void Player::BehaviorDropUpdate() {

}


