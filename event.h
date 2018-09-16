#pragma once
#include <functional>

#include "widget.h"

/*
typedef std::function <bool (size_t in_Health)> HealthListener;
typedef std::function <bool (Widget *in_Widget)> DestroyListener;
typedef std::function <bool (const Vector2f &pos)> ClickListener;
typedef std::function <bool (Widget ** ref_Widget)> MoveBeginListener;
typedef std::function <bool (Widget *in_Widget, const Vector2f &in_Pos)> MoveListener;
typedef std::function <bool (Widget **ref_Widget)> MoveEndListener;
*/

template <typename T>
class EventListener
{
public:
	typedef std::function<bool (T *)> CallListener;

	virtual ~EventListener()
	{
		for (auto it = m_CallbacksListeners.begin(); it != m_CallbacksListeners.end(); )
		{
			T *cls = *it;
			it = m_CallbacksListeners.erase(it);
			cls->UnhookEvent();
		}
	}

public:
	template <typename BaseClass>
	void Add_Listener(BaseClass *in_BasePtr)
	{
		T *childPtr = dynamic_cast<T *>(in_BasePtr);
		m_CallbacksListeners.push_back(childPtr);
	}

	template <typename BaseClass>
	void Remove_Listener(BaseClass *in_BasePtr)
	{
		for (auto it = m_CallbacksListeners.begin(); it != m_CallbacksListeners.end(); ++it)
		{
			if (*it == in_BasePtr)
			{
				T *cls = *it;
				it = m_CallbacksListeners.erase(it);
				cls->UnhookEvent();
				return;
			}
		}
	}

protected:
	template<class... _Types>
	void Emit(_Types &&...Args)
	{
		for (auto it = m_CallbacksListeners.begin(); it != m_CallbacksListeners.end(); ++it)
			(*it)->On_Event(Args...);
	}

private:
	std::vector<T *> m_CallbacksListeners;
};

template <typename T>
class EventCallback
{
public:
	EventCallback() : m_EventListener(NULL)
	{
	}

	virtual ~EventCallback()
	{
		UnhookEvent();
	}

public:
	void HookEvent(T *in_EventListener)
	{
		UnhookEvent();

		m_EventListener = in_EventListener;
		m_EventListener->Add_Listener(this);
	}

	void UnhookEvent()
	{
		if (m_EventListener)
		{
			m_EventListener->Remove_Listener(this);
			m_EventListener = NULL;
		}
	}

private:
	T *m_EventListener;
};
