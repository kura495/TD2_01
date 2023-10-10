﻿#pragma once
//
#include <optional>
//kamataEngine
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "Input.h"
//
#include "Leser.h"

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
	void OnCollision();

private:

	void BehaviorRootInitalize();
	void BehaviorRootUpdate();
	void BehaviorJumpInitalize();
	void BehaviorJumpUpdate();
	void BehaviorDropInitalize();
	void BehaviorDropUpdate();

	void Attack();
	//kamataEngine
	std::unique_ptr<Model> model_ = nullptr;
	WorldTransform worldTransform_;
	Input* input = nullptr;
	//
	Behavior behavior_ = Behavior::kRoot;
	std::optional<Behavior> behaviorRequest_ = std::nullopt;

	float gravity = 0.098f;
	float moveXaxisSpeed = 0.60f;
	float Jumpforce = 1.0f;

	std::list<Leser*> lesers_;
	Model* leser_model;

	int DropCount = 0;
	const int kDropAnime = 20;
	bool DropFlag = false;
	//TODO ちゃんといじろう
	int HP = 10;
};
