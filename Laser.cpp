#include "Leser.h"

Leser::Leser() {}
Leser::~Leser() {}

void Leser::Initalize(Model* model,const WorldTransform& PlayerworldTransform_) { 
	model_ = std::make_unique<Model>();
	model_.reset(model);
	worldTransform_.scale_.x = 0.5f;
	worldTransform_.scale_.y = 1.5f;
	worldTransform_.scale_.z = 0.5f;
	worldTransform_.translation_ = PlayerworldTransform_.translation_;
	worldTransform_.Initialize();
}

void Leser::Update() { 
	//worldTransform_.translation_.y -= 0.5f;
	worldTransform_.UpdateMatrix();
}

void Leser::Draw(const ViewProjection& ViewProjection_) { 
	model_.get()->Draw(worldTransform_,ViewProjection_);
}

