#include "Big_Cont.h"
Big_Cont::Big_Cont()
{
	Container::free_obem = 300;
	Container::space = 300;
	Container::vid_transporta = gen_vid_transporta();
}
bool Big_Cont::check_danger()
{
	return false;
}
