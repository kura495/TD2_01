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
	void OnCollition();
	bool GetIsAlive() { return IsAlive; }

private:

	//kamataEngine
	Model* model_;
	WorldTransform worldTransform_;

	//
	int AliveCount = 240;
	bool IsAlive = true;
};
