#include "EasySFML.h"

//CGameObject


CGameObject::CGameObject() : m_pNext(nullptr), m_pPrev(nullptr), bIsEnabled(true)
{
	CObjectController::AddUpdater(this);
}


CGameObject::~CGameObject()
{
	CObjectController::RemoveUpdater(this);
}

//CObjectController

sf::Clock CObjectController::deltaClock;
float CObjectController::deltaTime = 0.0f;
float CObjectController::fixedTime = 0.0f;


void CObjectController::UpdateObjects()
{
	deltaTime = deltaClock.restart().asSeconds();
	fixedTime += deltaTime;
	Update(deltaTime);
	while (fixedTime >= (1.0f / 60.0f))
	{
		FixedUpdate();
		fixedTime -= (1.0f / 60.0f);
	}
	LateUpdate(deltaTime + deltaClock.getElapsedTime().asSeconds());
}


void CObjectController::Update(float _fDeltaTime)
{
	CGameObject* pHead = *GetHead();
	CGameObject* pCurrent = pHead;
	if (pCurrent)
	{
		do
		{
			if (pCurrent->bIsEnabled)
			{
				pCurrent->Update(_fDeltaTime);
			}
			pCurrent = pCurrent->m_pNext;
		} while (pCurrent != pHead);
	}
}


void CObjectController::FixedUpdate()
{
	CGameObject* pHead = *GetHead();
	CGameObject* pCurrent = pHead;
	if (pCurrent)
	{
		do
		{
			if (pCurrent->bIsEnabled)
			{
				pCurrent->FixedUpdate();
			}
			pCurrent = pCurrent->m_pNext;
		} while (pCurrent != pHead);
	}
}


void CObjectController::LateUpdate(float _fDeltaTime)
{
	CGameObject* pHead = *GetHead();
	CGameObject* pCurrent = pHead;
	if (pCurrent)
	{
		do
		{
			if (pCurrent->bIsEnabled)
			{
				pCurrent->LateUpdate(_fDeltaTime);
			}
			pCurrent = pCurrent->m_pNext;
		} while (pCurrent != pHead);
	}
}


void CObjectController::AddUpdater(CGameObject * _updateable)
{
	CGameObject** m_pHead = GetHead();
	if (!*m_pHead)
	{
		_updateable->m_pNext = _updateable;
		_updateable->m_pPrev = _updateable;
	}
	else
	{
		(*m_pHead)->m_pPrev->m_pNext = _updateable;
		_updateable->m_pPrev = (*m_pHead)->m_pPrev;
		(*m_pHead)->m_pPrev = _updateable;
		_updateable->m_pNext = (*m_pHead);
	}
	*m_pHead = _updateable;
}


void CObjectController::RemoveUpdater(CGameObject * _updateable)
{
	CGameObject** m_pHead = GetHead();
	*m_pHead = _updateable->m_pNext;
	if (*m_pHead != _updateable)
	{
		_updateable->m_pPrev->m_pNext = _updateable->m_pNext;
		_updateable->m_pNext->m_pPrev = _updateable->m_pPrev;
	}
	else
	{
		*m_pHead = nullptr;
	}
	_updateable->m_pNext = nullptr;
	_updateable->m_pPrev = nullptr;
}


CGameObject ** CObjectController::GetHead()
{
	static CGameObject* pHead = nullptr;
	return &pHead;
}


void CWindowUtilities::Draw(sf::Drawable * Draw)
{
	ToDrawList.push_back(Draw);
}
std::vector<sf::Drawable*> CWindowUtilities::ToDrawList;
