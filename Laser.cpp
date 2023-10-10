#include "Leser.h"

Leser::Leser() {}
Leser::~Leser() {}

void Leser::Initalize(Model* model,const WorldTransform& PlayerworldTransform_) { 
	model_ = model;
	worldTransform_.scale_.x = 0.5f;
	worldTransform_.scale_.y = 1.5f;
	worldTransform_.scale_.z = 0.5f;
	worldTransform_.translation_ = PlayerworldTransform_.translation_;
	worldTransform_.Initialize();
}

void Leser::Update() { 
	worldTransform_.translation_.y -= 2.0f;
	worldTransform_.UpdateMatrix();
	AliveCount--;
	if (AliveCount <= 0) {
		IsAlive = false;
	}

}

void Leser::Draw(const ViewProjection& ViewProjection_) { 
	model_->Draw(worldTransform_,ViewProjection_);
}

void Leser::OnCollision() { 
	IsAlive = false;

}

