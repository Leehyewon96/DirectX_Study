#include "framework.h"
#include "cGizmo.h"

cGizmo::cGizmo()
{
	D3DXMatrixIdentity(&m_matR);
}

cGizmo::~cGizmo()
{

}

void cGizmo::Setup(D3DCOLOR c, D3DXMATRIXA16& mat)
{
	m_matR = mat;
	ST_PC_VERTEX v;
	//CW : 시계방향 (CCW :반시계방향)

	v.c = c;

	//front
	v.P = D3DXVECTOR3(0, 0, 0);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);

	//right
	v.P = D3DXVECTOR3(0, 0, 0);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);

	//back
	v.P = D3DXVECTOR3(0, 0, 0);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);

	//left
	v.P = D3DXVECTOR3(0, 0, 0);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);

	//bottom
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);

	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
}

void cGizmo::Render()
{
	D3DXMATRIXA16 matWorld, matS;
	D3DXMatrixScaling(&matS, 0.1f, 2.0f, 0.1f);
	D3DXMatrixIdentity(&matWorld);
	matWorld = matS * m_matR;

	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, FALSE);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX)
	);
}
