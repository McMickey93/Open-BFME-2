// cl: /GX-
// ?rva005977D3@Rva005977D3@@QAEXXZ @0x005977D3 74B: prune vector<ObjectID> at +0x18 erasing null or float280 below 0 via rowed findObjectByID 0x00049DC5 and erase 0x0025BF5D with virtual slot0(obj 1); caller 0x00597FC5
#include "../../SkirmishAI/AIUpgrade/AIUpgradeScienceBuilder/ScienceBuilderPruneView.h"

struct SciencePruneObjectView
{
	char m_pad00[0x280];
	float m_float280;
};


extern GameLogic *TheGameLogic;

void Rva005977D3::rva005977D3()
{
	ObjectID *it = m_ids.m_begin;
	while (it != m_ids.m_end)
	{
		Object *obj = TheGameLogic->findObjectByID(*it);
		if (obj == 0)
		{
			it = m_ids.erase(it);
		}
		else if (((SciencePruneObjectView *)obj)->m_float280 < 0.0f)
		{
			slot0(obj, 1);
			it = m_ids.erase(it);
		}
		else
		{
			++it;
		}
	}
}
