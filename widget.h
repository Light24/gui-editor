#pragma once
#include <vector>
#include <functional>

#include "vector2f.h"

class Widget
{
public:
	typedef std::function<bool(Widget *)> Enumerator;

public:
	Widget();
	~Widget();

public:
	const Vector2f &Get_Pos() const { return m_Pos; }
	void Set_Pos(const Vector2f &in_Pos) { m_Pos = in_Pos; }

	const Vector2f &Get_Size() const { return m_Size; }
	void Set_Size(const Vector2f &in_Size) { m_Size = in_Size; }

	Widget *Get_Parent() const { return m_Parent; }
	void Set_Parent(Widget *parent);

	size_t Get_Childs_Count() const { return m_Childs.size(); }
	void Enumerate_Childs(Enumerator in_Enumerator);

public:
	virtual void Draw() = 0;

private:
	void On_Parent_Resize();
	void On_Parent_Moved();

private:
	Vector2f m_Pos;
	Vector2f m_Size;

	Widget *m_Parent;
	std::vector<Widget> m_Childs;
};

