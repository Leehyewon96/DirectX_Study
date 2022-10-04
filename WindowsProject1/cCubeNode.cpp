#include "framework.h"
#include "cCubeNode.h"

cCubeNode::cCubeNode()
	: m_fRotDeltaX(0.0f)
	, m_fRotX(0.0f)
	, m_pParentWorldTM(NULL)
	, m_vLocalPos(0,0,0)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);
}

cCubeNode::~cCubeNode()
{

}

void cCubeNode::AddChild(cCubeNode* pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM;
	m_vecChild.push_back(pChild);
}

void cCubeNode::Destroy()
{
	for (auto p : m_vecChild)
	{
		p->Destroy();
	}
	delete this;
}

void cCubeNode::Setup()
{		
	cCubePNT::Setup();
    {
        m_vecVertex[0].t.x = (float)32 / 64;   m_vecVertex[0].t.y = (float)32 / 32;
        m_vecVertex[1].t.x = (float)32 / 64;   m_vecVertex[1].t.y = (float)20 / 32;
        m_vecVertex[2].t.x = (float)40 / 64;   m_vecVertex[2].t.y = (float)20 / 32;    //¾Õ¸é À­»ï°¢ 
                                                                     //0,1,2

        m_vecVertex[3].t.x = (float)32 / 64;   m_vecVertex[3].t.y = (float)32 / 32;
        m_vecVertex[4].t.x = (float)40 / 64;   m_vecVertex[4].t.y = (float)20 / 32;
        m_vecVertex[5].t.x = (float)40 / 64;   m_vecVertex[5].t.y = (float)32 / 32;    //¾Õ¸é ¾Æ·§»ï°¢
                                                                     //0,2,3

        m_vecVertex[6].t.x = (float)28 / 64;   m_vecVertex[6].t.y = (float)32 / 32;
        m_vecVertex[7].t.x = (float)20 / 64;   m_vecVertex[7].t.y = (float)20 / 32;
        m_vecVertex[8].t.x = (float)28 / 64;   m_vecVertex[8].t.y = (float)20 / 32;    //µÞ¸é À­»ï°¢
                                                                     //4,6,5

        m_vecVertex[9].t.x = (float)28 / 64;   m_vecVertex[9].t.y = (float)32 / 32;
        m_vecVertex[10].t.x = (float)20 / 64;   m_vecVertex[10].t.y = (float)32 / 32;
        m_vecVertex[11].t.x = (float)20 / 64;   m_vecVertex[11].t.y = (float)20 / 32;    //µÞ¸é ¾Æ·§»ï°¢
                                                                     //4,7,6

        m_vecVertex[12].t.x = (float)28 / 64;   m_vecVertex[12].t.y = (float)32 / 32;
        m_vecVertex[13].t.x = (float)28 / 64;   m_vecVertex[13].t.y = (float)20 / 32;
        m_vecVertex[14].t.x = (float)32 / 64;   m_vecVertex[14].t.y = (float)20 / 32;    //¿ÞÂÊ¸é À­»ï°¢
                                                                     //4,5,1

        m_vecVertex[15].t.x = (float)28 / 64;   m_vecVertex[15].t.y = (float)32 / 32;
        m_vecVertex[16].t.x = (float)32 / 64;   m_vecVertex[16].t.y = (float)20 / 32;
        m_vecVertex[17].t.x = (float)32 / 64;   m_vecVertex[17].t.y = (float)32 / 32;    //¿ÞÂÊ¸é ¾Æ·§»ï°¢
                                                                     //4,1,0

        m_vecVertex[18].t.x = (float)16 / 64;   m_vecVertex[18].t.y = (float)32 / 32;
        m_vecVertex[19].t.x = (float)16 / 64;   m_vecVertex[19].t.y = (float)20 / 32;
        m_vecVertex[20].t.x = (float)20 / 64;   m_vecVertex[20].t.y = (float)20 / 32;    //¿À¸¥¸é À­»ï°¢
                                                                     //3,2,6

        m_vecVertex[21].t.x = (float)16 / 64;   m_vecVertex[21].t.y = (float)32 / 32;
        m_vecVertex[22].t.x = (float)20 / 64;   m_vecVertex[22].t.y = (float)20 / 32;
        m_vecVertex[23].t.x = (float)20 / 64;   m_vecVertex[23].t.y = (float)32 / 32;    //¿À¸¥¸é ¾Æ·§»ï°¢
                                                                     //3,6,7

        m_vecVertex[24].t.x = (float)28 / 64;   m_vecVertex[24].t.y = (float)16 / 32;
        m_vecVertex[25].t.x = (float)28 / 64;   m_vecVertex[25].t.y = (float)20 / 32;
        m_vecVertex[26].t.x = (float)20 / 64;   m_vecVertex[26].t.y = (float)20 / 32;    //À­¸é À­»ï°¢
                                                                     //1,5,6

        m_vecVertex[27].t.x = (float)28 / 64;   m_vecVertex[27].t.y = (float)16 / 32;
        m_vecVertex[28].t.x = (float)20 / 64;   m_vecVertex[28].t.y = (float)20 / 32;
        m_vecVertex[29].t.x = (float)20 / 64;   m_vecVertex[29].t.y = (float)16 / 32;    //À­¸é ¾Æ·§»ï°¢
                                                                     //1,6,2

        m_vecVertex[30].t.x = (float)28 / 64;   m_vecVertex[30].t.y = (float)16 / 32;
        m_vecVertex[31].t.x = (float)28 / 64;   m_vecVertex[31].t.y = (float)20 / 32;
        m_vecVertex[32].t.x = (float)36 / 64;   m_vecVertex[32].t.y = (float)20 / 32;    //¾Æ·§¸é À­»ï°¢
                                                                     //4,0,3

        m_vecVertex[33].t.x = (float)28 / 64;   m_vecVertex[33].t.y = (float)16 / 32;
        m_vecVertex[34].t.x = (float)36 / 64;   m_vecVertex[34].t.y = (float)20 / 32;
        m_vecVertex[35].t.x = (float)36 / 64;   m_vecVertex[35].t.y = (float)20 / 32;    //¾Æ·§¸é ¾Æ·§»ï°¢
    }
}

void cCubeNode::Update()
{
	cCubePNT::Update();

	{
		m_fRotX += m_fRotDeltaX;
		if (m_fRotX > D3DX_PI / 6.0F)
		{
			m_fRotX = D3DX_PI / 6.0F;
			m_fRotDeltaX *= -1;
		}

		if (m_fRotX < -D3DX_PI / 6.0F)
		{
			m_fRotX = -D3DX_PI / 6.0F;
			m_fRotDeltaX *= -1;
		}
	}

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixRotationX(&matR, m_fRotX);
	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);
	m_matLocalTM = matR * matT;

	m_matWorldTM = m_matLocalTM;
	if (m_pParentWorldTM)
		m_matWorldTM *= *m_pParentWorldTM;

	for (auto p : m_vecChild)
		p->Update();
}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	cCubePNT::Render();

	for (auto p : m_vecChild)
		p->Render();
}
