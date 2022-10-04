#include "framework.h"
#include "cCubePC.h"

cCubePC::cCubePC()
	: m_vPosition(0,0,0)
	, m_vDirection(0,0,1)
	, m_fRotY(0.0f)
	, m_fRotX(0.0f)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cCubePC::~cCubePC()
{
}

void cCubePC::Setup()
{
	ST_PC_VERTEX v;
	//CW : 시계방향 (CCW :반시계방향)
	//:front
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	  
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);

	//:back
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);
	  
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);

	//:LEFT
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	  
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);

	//:right
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);
	  
	v.P = D3DXVECTOR3(1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);

	//:top
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.P = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);
	  
	v.P = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, 1.0f, -1.0f);  m_vecVertex.push_back(v);

	//:bottom
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	  
	v.P = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, -1.0f);  m_vecVertex.push_back(v);
	v.P = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  m_vecVertex.push_back(v);

}

void cCubePC::Update()
{
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}
	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
	}
	/*if (GetKeyState('E') & 0x8000)
	{
		m_fRotX -= 0.1f;
	}
	if (GetKeyState('Q') & 0x8000)
	{
		m_fRotX += 0.1f;
	}*/

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationX(&matR, m_fRotX);
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;

}

void cCubePC::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, FALSE);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX)
	);
}

D3DXVECTOR3& cCubePC::GetPosition()
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_vPosition;
}
