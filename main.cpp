#include "widget-events.h"

class Listener : public ClickEventListener
{

};

class Callback : public ClickEventCallback
{
	bool On_Event(const Vector2f &in_Pos)
	{
		return false;
	}
};

void main()
{
	Listener listener;
	{
		Callback cb;
		cb.HookEvent(&listener);
		listener.Emit_Click_Event(17);
		listener.Emit_Click_Event(1);
	}

	listener.Emit_Click_Event(1);
}