#pragma once
#include "event.h"
#include "widget.h"

class ClickEventListener;
class ClickEventCallback : public EventCallback<ClickEventListener>
{
public:
	virtual bool On_Event(const Vector2f &in_Pos) = 0;
};

class ClickEventListener : public EventListener<ClickEventCallback>
{
public:
	template<class... _Types>
	void Emit_Click_Event(_Types &&...Args) { Emit(Args...); }
};


class MoveBeginEventListener;
class MoveBeginEventCallback : public EventCallback<MoveBeginEventListener>
{
public:
	virtual bool On_Event(Widget **in_Item) = 0;
};

class MoveBeginEventListener : public EventListener<MoveBeginEventCallback>
{
public:
	template<class... _Types>
	void Emit_Move_Begin(_Types &&...Args) { Emit(Args...); }
};


class MoveEventListener;
class MoveEventCallback : public EventCallback<MoveEventListener>
{
public:
	virtual bool On_Event(Widget *in_Widget, const Vector2f &in_Pos) = 0;
};

class MoveEventListener : public EventListener<MoveEventCallback>
{
public:
	template<class... _Types>
	void Emit_Move_Event(_Types &&...Args) { Emit(Args...); }
};


class MoveEndEventListener;
class MoveEndEventCallback : public EventCallback<MoveEndEventListener>
{
public:
	virtual bool On_Event(Widget **in_Widget) = 0;
};

class MoveEndEventListener : public EventListener<MoveEndEventCallback>
{
public:
	template<class... _Types>
	void Emit_Move_End_Event(_Types &&...Args) { Emit(Args...); }
};
