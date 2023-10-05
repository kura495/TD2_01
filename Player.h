#pragma once

#include "Model.h"

#include "WorldTransform.h"
#include "ViewProjection.h"

class Player {
public:
	Player();
	~Player();

	void Initalize();
	void Update();
	void Draw(ViewProjection ViewProjection_);

private:
	std::unique_ptr<Model> model_ = nullptr;

	WorldTransform worldTransform_;
};
