#pragma once

#include "Model.h"

#include "WorldTransform.h"

class Player {
public:
	Player();
	~Player();

	void Initalize();
	void Update();
	void Draw();

private:
	std::unique_ptr<Model> model_ = nullptr;

	WorldTransform worldTransform_;
};
