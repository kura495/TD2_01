﻿#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initalize(const Vector3& position) { 
	leser_model = new Model();
 	leser_model = Model::Create();
	model_ = std::make_unique<Model>();
	model_.reset(Model::Create());
	worldTransform_.translation_ = position;
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
			break;
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
		break;
	case Behavior::kJump:
		BehaviorJumpUpdate();
		break;
	case Behavior::kDrop:
		BehaviorDropUpdate();
		break;
	}

	for (Leser* leser : lesers_) {
		leser->Update();
	}

	worldTransform_.UpdateMatrix();
}

void Player::Draw(const ViewProjection& ViewProjection_) { 
	model_.get()->Draw(worldTransform_, ViewProjection_);
	for (Leser* leser : lesers_) {
		leser->Draw(ViewProjection_);
	}
}

void Player::OnCollision() { 
	if (DropFlag) {
		return;
	} else {
		HP -= 1;
	}

}

void Player::BehaviorRootInitalize() { 
	behavior_ = Behavior::kRoot;
	DropFlag = false;
}

void Player::BehaviorRootUpdate() { 
	worldTransform_.translation_.y -= gravity; 
	worldTransform_.translation_.x += moveXaxisSpeed;
	lesers_.remove_if([](Leser* leser) {
		if (leser->GetIsAlive()) {
			delete leser;
			return true;
		}
		return false;
	});
	//スペースを押すとジャンプする
	if (input->PushKey(DIK_SPACE) != 0 && input->PushPrekey(DIK_SPACE) == 0) {
		behaviorRequest_ = Behavior::kJump;
	}
}

void Player::BehaviorJumpInitalize() { 
	behavior_ = Behavior::kJump;
	Jumpforce = 2.0f;
	moveXaxisSpeed *= -1;
	Leser* leser_ = new Leser();
	leser_->Initalize(leser_model, worldTransform_);
	lesers_.push_back(leser_);
	DropCount = 0;
	DropFlag = false;
}

void Player::BehaviorJumpUpdate() { 
	
	worldTransform_.translation_.y += Jumpforce;
	worldTransform_.translation_.x += moveXaxisSpeed; 
	if (Jumpforce > 0) {
		Jumpforce -= gravity;
	} else if(Jumpforce <= 0) {
		Jumpforce = -kXaxisSpeed;
	}
	
	DropCount++;
	if (input->PushKey(DIK_SPACE) != 0 && input->PushPrekey(DIK_SPACE) == 0) {
		behaviorRequest_ = Behavior::kJump;
	} 
	else if (
	    DropCount == kDropAnime && input->PushKey(DIK_SPACE) != 0 &&
	    input->PushPrekey(DIK_SPACE) != 0) {
		behaviorRequest_ = Behavior::kDrop;
	}
}

void Player::BehaviorDropInitalize() { 
	behavior_ = Behavior::kDrop;
}

void Player::BehaviorDropUpdate() { 
	worldTransform_.translation_.y += 0.03f;
	DropCount++;
	if (DropCount >= kDropAnime * 3 ) {
		Attack();
	}
	if (input->PushKey(DIK_SPACE) == 0) {
		behaviorRequest_ = Behavior::kRoot;
	}
}

void Player::BehaviorHitInitalize() { 
	behavior_ = Behavior::kHit;
	t = 0.0f;
}

void Player::BehaviorHitUpdate() { 
	t += 0.1f;
	worldTransform_.translation_.y = Lerp();
	if (t <= 1.0f) {
		behaviorRequest_ = Behavior::kRoot;
	}
}

void Player::Attack(){ 
	worldTransform_.translation_.y -= 2.0f;
	DropFlag = true;
}

float Player::Lerp(float a, float b, float t) { return a + t * (b - a);

}


