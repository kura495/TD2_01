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
	kHit,//ボスに当たった時
};

class Player {
public:
	Player();
	~Player();

	void Initalize(const Vector3& position);
	void Update();
	void Draw(const ViewProjection& ViewProjection_);
	void OnCollision();
	const Vector3 GetPosition()
	{ return worldTransform_.translation_; }

private:

	void BehaviorRootInitalize();
	void BehaviorRootUpdate();
	void BehaviorJumpInitalize();
	void BehaviorJumpUpdate();
	void BehaviorDropInitalize();
	void BehaviorDropUpdate();
	void BehaviorHitInitalize();
	void BehaviorHitUpdate();

	void Attack();
	//Lerp
	float Lerp(float a,float b,float t);

	//kamataEngine
	std::unique_ptr<Model> model_ = nullptr;
	WorldTransform worldTransform_;
	Input* input = nullptr;
	//
	Behavior behavior_ = Behavior::kRoot;
	std::optional<Behavior> behaviorRequest_ = std::nullopt;
	//ジャンプ関連関数
	float gravity = 0.3f;
	float Jumpforce = 3.0f;
	//左右移動関係関数
	const float kXaxisSpeed = 0.60f;
	float moveXaxisSpeed = kXaxisSpeed;
	//落下攻撃関係関数
	int DropCount = 0;
	const int kDropAnime = 20;
	bool DropFlag = false;
	//ボスに当たった時用
	float t = 0.0f;


	std::list<Leser*> lesers_;
	Model* leser_model;

	//TODO ちゃんといじろう
	int HP = 10;
};
