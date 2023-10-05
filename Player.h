#pragma once
//
#include <optional>
//kamataEngine
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"

enum class Behavior {
	kRoot,//通常
	kJump,//ジャンプ(単押し)
	kDrop,//落下攻撃(長押し)
};

class Player {
public:
	Player();
	~Player();

	void Initalize();
	void Update();
	void Draw(const ViewProjection& ViewProjection_);

private:

	void BehaviorRootUpdate();
	void BehaviorJumpUpdate();
	void BehaviorDropUpdate();

	//kamataEngine
	std::unique_ptr<Model> model_ = nullptr;
	WorldTransform worldTransform_;

	//
	Behavior behavior_ = Behavior::kRoot;
	std::optional<Behavior> behaviorRequest_ = std::nullopt;

};
