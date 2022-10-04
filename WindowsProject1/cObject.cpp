#include "framework.h"
#include "cObject.h"

cObject::cObject()
	: m_ulRefCount(1)
{
	
}

cObject::~cObject()
{
}

void cObject::AddRef()
{
}

void cObject::Release()
{
}
