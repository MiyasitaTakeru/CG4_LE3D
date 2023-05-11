#pragma once
#include <string>
#include<DirectXMath.h>
#include <vector>

// �m�[�h
struct Node
{
	// ���O
	std::string name;
	// ���[�J���X�P�[��
	DirectX::XMVECTOR scaling = { 1,1,1,0 };
	// ���[�J����]�p
	DirectX::XMVECTOR rotation = { 0,0,0,0 };
	// ���[�J���ړ�
	DirectX::XMVECTOR translation = { 1,1,1,0 };
	// ���[�J���ό`�s��
	DirectX::XMMATRIX transform;
	// �O���[�o���ό`�s��
	DirectX::XMMATRIX globalTransform;
	// �e�m�[�h
	Node* parent = nullptr;
};

class Model
{
public:
	// �t�����h�N���X
	friend class FbxLoader;

private:
	// ���f����
	std::string name;
	// �m�[�h�z��
	std::vector<Node> nodes;
};
