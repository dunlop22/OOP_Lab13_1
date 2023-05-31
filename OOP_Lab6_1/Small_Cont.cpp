#include "Small_Cont.h"

Small_Cont::Small_Cont()
{
	Container::free_obem = 150;
	Container::space = 150;
	Container::vid_transporta = gen_vid_transporta();
}

bool Small_Cont::check_danger()
{
	return false;
}

