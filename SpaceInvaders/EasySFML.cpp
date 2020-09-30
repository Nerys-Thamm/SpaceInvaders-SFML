#include "EasySFML.h"

//CGameObject

// ********************************************************************************
/// <summary>
/// <para>
/// Constructor for Class: CGameObject
/// </para>
/// </summary>
/// <returns></returns>
// ********************************************************************************
CGameObject::CGameObject() : m_pNext(nullptr), m_pPrev(nullptr), bIsEnabled(true)
{
	CObjectController::AddUpdater(this);
}

// ********************************************************************************
/// <summary>
/// <para>
/// Destructor for Class: CGameObject
/// </para>
/// </summary>
/// <returns></returns>
// ********************************************************************************
CGameObject::~CGameObject()
{
	CObjectController::RemoveUpdater(this);
}

//CObjectController

sf::Clock CObjectController::deltaClock;
float CObjectController::deltaTime = 0.0f;
float CObjectController::fixedTime = 0.0f;

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: UpdateObjects
/// Function is part of Class: CObjectController
/// Calls the update methods defined by classes inheriting from CGameObject
/// </para>
/// </summary>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: Update
/// Function is part of Class: CObjectController
/// Calls the Update method on all instances of classes that inherit from CGameObject and define the method
/// Called once every frame
/// </para>
/// </summary>
/// <param name="_fDeltaTime"><para>
/// Type: float, time since last frame
/// </para></param>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: FixedUpdate
/// Function is part of Class: CObjectController
/// Calls the FixedUpdate method on instances of classes that inherit from CGameObject and define the method
/// Called at fixed intervals independant of framerate
/// </para>
/// </summary>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: LateUpdate
/// Function is part of Class: CObjectController
/// Calls the LateUpdate method on instances of classes that inherit from CGameObject and define the method
/// Called once every frame, after all other update methods have finished
/// </para>
/// </summary>
/// <param name="_fDeltaTime"><para>
/// Type: float, time since last frame
/// </para></param>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: AddUpdater
/// Function is part of Class: CObjectController
/// Adds a CGameObject derived class instance to the pool of instances to call update methods on
/// </para>
/// </summary>
/// <param name="_updateable"><para>
/// Type: CGameObject Pointer
/// </para></param>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: RemoveUpdater
/// Function is part of Class: CObjectController
/// Removes an instance from the pool of updated objects, called in the destructor
/// </para>
/// </summary>
/// <param name="_updateable"><para>
/// Type: CGameObject Pointer
/// </para></param>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: GetHead
/// Function is part of Class: CObjectController
/// </para>
/// </summary>
/// <returns>Value of type: CGameObject Pointer</returns>
// ********************************************************************************
CGameObject ** CObjectController::GetHead()
{
	static CGameObject* pHead = nullptr;
	return &pHead;
}

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: Draw
/// Function is part of Class: CWindowUtilities
/// Adds an object to the collection of things to be drawn next frame
/// </para>
/// </summary>
/// <param name="Draw"><para>
/// Type: sf::Drawable Pointer
/// </para></param>
// ********************************************************************************
void CWindowUtilities::Draw(sf::Drawable * Draw)
{
	ToDrawList.push_back(Draw);
}
std::vector<sf::Drawable*> CWindowUtilities::ToDrawList;
