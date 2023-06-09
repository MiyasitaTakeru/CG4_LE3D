#pragma once
#include <string>
#include<DirectXMath.h>
#include <vector>
#include<DirectXTex.h>

// ノード
struct Node
{
	// 名前
	std::string name;
	// ローカルスケール
	DirectX::XMVECTOR scaling = { 1,1,1,0 };
	// ローカル回転角
	DirectX::XMVECTOR rotation = { 0,0,0,0 };
	// ローカル移動
	DirectX::XMVECTOR translation = { 1,1,1,0 };
	// ローカル変形行列
	DirectX::XMMATRIX transform;
	// グローバル変形行列
	DirectX::XMMATRIX globalTransform;
	// 親ノード
	Node* parent = nullptr;
};

class Model
{
public: // サブクラス
	// 頂点データ構造体
	struct VertexPosNormalUv
	{
		// xyz座標
		DirectX::XMFLOAT3 pos;
		// 法線ベクトル
		DirectX::XMFLOAT3 normal;
		// uv座標
		DirectX::XMFLOAT3 uv;
	};
	// メッシュを持つノード
	Node* meshNode = nullptr;
	// 頂点データは配列
	std::vector<VertexPosNormalUv> vertices;
	// 頂点インデックス配列
	std::vector<unsigned short>indices;

	// アンビエント係数
	DirectX::XMFLOAT3 ambient = { 1, 1, 1 };
	// ディフューズ係数
	DirectX::XMFLOAT3 diffuse = { 1, 1, 1 };
	// テクスチャメタデータ
	DirectX::TexMetadata metadata = {};
	// スクラッチイメージ
	DirectX::ScratchImage scratchImg = {};

public:
	// フレンドクラス
	friend class FbxLoader;

private:
	// モデル名
	std::string name;
	// ノード配列
	std::vector<Node> nodes;
};

