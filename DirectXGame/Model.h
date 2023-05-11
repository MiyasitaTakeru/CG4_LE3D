#pragma once
#include <string>
#include<DirectXMath.h>
#include <vector>
#include<DirectXTex.h>

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
public: // �T�u�N���X
	// ���_�f�[�^�\����
	struct VertexPosNormalUv
	{
		// xyz���W
		DirectX::XMFLOAT3 pos;
		// �@���x�N�g��
		DirectX::XMFLOAT3 normal;
		// uv���W
		DirectX::XMFLOAT3 uv;
	};
	// ���b�V�������m�[�h
	Node* meshNode = nullptr;
	// ���_�f�[�^�͔z��
	std::vector<VertexPosNormalUv> vertices;
	// ���_�C���f�b�N�X�z��
	std::vector<unsigned short>indices;

	// �A���r�G���g�W��
	DirectX::XMFLOAT3 ambient = { 1, 1, 1 };
	// �f�B�t���[�Y�W��
	DirectX::XMFLOAT3 diffuse = { 1, 1, 1 };
	// �e�N�X�`�����^�f�[�^
	DirectX::TexMetadata metadata = {};
	// �X�N���b�`�C���[�W
	DirectX::ScratchImage scratchImg = {};

public:
	// �t�����h�N���X
	friend class FbxLoader;

private:
	// ���f����
	std::string name;
	// �m�[�h�z��
	std::vector<Node> nodes;
};

