#include "Danger_Cont.h"
bool Danger_Cont::check_danger()
{
	return true;
}
Danger_Cont::Danger_Cont()
{
	Container::free_obem = 200;
	Container::space = 200;
	Container::vid_transporta = 1;
	Container::danger = 1;
}