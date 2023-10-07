#pragma once

//kamataEngine
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"

class Leser {
public:
	Leser();
	~Leser();

	void Initalize(Model* model, const WorldTransform& PlayerworldTransform_);
	void Update();
	void Draw(const ViewProjection& ViewProjection_);

private:
	std::unique_ptr<Model> model_;
	WorldTransform worldTransform_;
};
