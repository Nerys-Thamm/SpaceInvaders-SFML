#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <vector>

class CGameObject
{
	friend class CObjectController;
public:
	virtual void Update(float _fDeltaTime) {};
	virtual void FixedUpdate() {};
	virtual void LateUpdate(float _fDeltaTime) {};
	
	bool bIsEnabled = true;
protected:
	CGameObject();
	virtual ~CGameObject();
private:
	CGameObject* m_pNext;
	CGameObject* m_pPrev;
};
class CObjectController
{
	friend class CGameObject;
public:
	
	static void UpdateObjects();
	static void Update(float _fDeltaTime);
	static void FixedUpdate();
	static void LateUpdate(float _fDeltaTime);
private:
	static sf::Clock deltaClock;
	static float deltaTime;
	static float fixedTime;
	static void AddUpdater(CGameObject* _updateable);
	static void RemoveUpdater(CGameObject* _updateable);
	static CGameObject** GetHead();

};
class CWindowUtilities
{
public:
	static std::vector<sf::Drawable*> ToDrawList;
	static void Draw(sf::Drawable* Draw);
	
};



