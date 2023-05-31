#pragma once
#include "Container.h"
class Big_Cont :public Container
{
public:
	Big_Cont();
	Big_Cont(StateCont* sendedState, StateCont* notSendedState) : Container(sendedState, notSendedState) {
		free_obem = 300;
		space = 300;
		vid_transporta = gen_vid_transporta();
	};
	virtual bool check_danger();
};

