#pragma once
//
#include <optional>
//kamataEngine
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "Input.h"

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

	void BehaviorRootInitalize();
	void BehaviorRootUpdate();
	void BehaviorJumpInitalize();
	void BehaviorJumpUpdate();
	void BehaviorDropInitalize();
	void BehaviorDropUpdate();

	//kamataEngine
	std::unique_ptr<Model> model_ = nullptr;
	WorldTransform worldTransform_;
	Input* input = nullptr;
	//
	Behavior behavior_ = Behavior::kRoot;
	std::optional<Behavior> behaviorRequest_ = std::nullopt;

	float gravity = 0.98f;
	float moveXaxisSpeed = 1.0f;
	float Jumpforce = 2.0f;

	//Inputにpreviousがないのでフラグで管理
	bool 
};
