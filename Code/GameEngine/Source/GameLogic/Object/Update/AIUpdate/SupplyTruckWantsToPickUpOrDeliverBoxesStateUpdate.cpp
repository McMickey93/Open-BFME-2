// cl: /O1 /DNDEBUG /MD
// ?update@SupplyTruckWantsToPickUpOrDeliverBoxesState@@UAE?AW4StateReturnType@@XZ,
// retail 0x004A7275 (182 bytes).
// Donor (Zero Hour SupplyTruckAIUpdate.cpp
// SupplyTruckWantsToPickUpOrDeliverBoxesState::update): with boxes, dock at
// the player's best supply center; without, at the best warehouse.
// Target evidence: WorldBuilder lead names 0x004A7275
// SupplyTruckWantsToPickUpOrDeliverBoxesState::update. Retail reads the
// machine owner (State+0x18 -> StateMachine+0x14), its AI (Object+0x258),
// the controlling player's ResourceGatheringManager (Player+0x2E4), the AI's
// supply-truck interface (AI vslot 95), and docks through the matched
// AICommandInterface 0x0026C3AC (aiDock's argument order) with CMD_FROM_AI.
// The manager calls 0x004F5DFB / 0x004F5C84 sit in the boxes / no-boxes
// arms exactly where the donor calls findBestSupplyCenter /
// findBestSupplyWarehouse, and are pinned from this body.
// BFME 2 deltas (target): a null manager also fails; with no warehouse, an
// interface flag (vslot 6) asks the manager (0x004F5A67, unnamed) for a
// harvest position and orders the matched aiHarvest there; and the
// fall-through returns STATE_CONTINUE instead of STATE_FAILURE.
// The classes spell SupplyTruckStateMachine.cpp's views (both join the
// SupplyTruckAIUpdate.cpp TU): the AI module is read as Object's member and
// the supply truck interface's slot 6 keeps that view's v06 name.
#include "../../../../../../Libraries/Include/Lib/Coord3D.h"

typedef bool Bool;
typedef int Int;
typedef unsigned int UnsignedInt;

class Object;

enum StateReturnType
{
	STATE_CONTINUE = 0,
	STATE_SUCCESS = -1,
	STATE_FAILURE = -2
};

typedef UnsignedInt StateID;

class SupplyTruckAIInterface
{
public:
	virtual Int getNumberBoxes() const; // slot 0
	virtual void v01(); virtual void v02(); virtual void v03();
	virtual Bool isAvailableForSupplying() const; // slot 4 (+0x10), ownerAvailableForSupplying
	virtual void v05();
	virtual Bool v06() const; // slot 6 (+0x18)
	virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10();
	virtual void setForceWantingState(Bool v); // +0x2C
	virtual Bool isForcedIntoWantingState() const; // +0x30
	virtual void setForceBusyState(Bool v); // +0x34
	virtual Bool isForcedIntoBusyState() const; // +0x38
};

enum CommandSourceType
{
	CMD_FROM_AI = 2
};

class AICommandInterface
{
public:
	void aiDock(Object *obj, CommandSourceType cmdSource);
	void aiHarvest(const Coord3D *pos, CommandSourceType cmdSource);
};

class AIUpdateInterface
{
public:
	virtual void v000(); virtual void v001(); virtual void v002(); virtual void v003();
	virtual void v004(); virtual void v005(); virtual void v006(); virtual void v007();
	virtual void v008(); virtual void v009(); virtual void v010(); virtual void v011();
	virtual void v012(); virtual void v013(); virtual void v014(); virtual void v015();
	virtual void v016(); virtual void v017(); virtual void v018(); virtual void v019();
	virtual void v020(); virtual void v021(); virtual void v022(); virtual void v023();
	virtual void v024(); virtual void v025(); virtual void v026(); virtual void v027();
	virtual void v028(); virtual void v029(); virtual void v030(); virtual void v031();
	virtual void v032(); virtual void v033(); virtual void v034(); virtual void v035();
	virtual void v036(); virtual void v037(); virtual void v038(); virtual void v039();
	virtual void v040(); virtual void v041(); virtual void v042(); virtual void v043();
	virtual void v044(); virtual void v045(); virtual void v046(); virtual void v047();
	virtual void v048(); virtual void v049(); virtual void v050(); virtual void v051();
	virtual void v052(); virtual void v053(); virtual void v054(); virtual void v055();
	virtual void v056(); virtual void v057(); virtual void v058(); virtual void v059();
	virtual void v060(); virtual void v061(); virtual void v062(); virtual void v063();
	virtual void v064(); virtual void v065(); virtual void v066(); virtual void v067();
	virtual void v068(); virtual void v069(); virtual void v070(); virtual void v071();
	virtual void v072(); virtual void v073(); virtual void v074(); virtual void v075();
	virtual void v076(); virtual void v077(); virtual void v078(); virtual void v079();
	virtual void v080(); virtual void v081(); virtual void v082(); virtual void v083();
	virtual void v084(); virtual void v085(); virtual void v086(); virtual void v087();
	virtual void v088(); virtual void v089(); virtual void v090(); virtual void v091();
	virtual void v092(); virtual void v093(); virtual void v094();
	virtual SupplyTruckAIInterface *getSupplyTruckAIInterface(); // slot 95 (+0x17C)
	virtual void v096(); virtual void v097(); virtual void v098(); virtual void v099();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
	virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
	virtual void v108(); virtual void v109();
	virtual Bool isIdle(); // slot 110 (+0x1B8)
	Int getCurrentStateID() const; // rowed 0x00262FC3

	char m_pad04[0x20 - 0x04];
	AICommandInterface m_commands; // +0x20
};

class ResourceGatheringManager
{
public:
	Object *findBestSupplyWarehouse(Object *queryObject);
	Object *findBestSupplyCenter(Object *queryObject);
	bool rva004F5A67(Object *queryObject, Coord3D *pos);
};

class Player
{
public:
	ResourceGatheringManager *getResourceGatheringManager() const { return m_resourceGatheringManager; }

	char m_pad[0x5C];
	int m_playerType; // +0x5C
	char m_pad60[0x2E4 - 0x60];
	ResourceGatheringManager *m_resourceGatheringManager; // +0x2E4
};

class Object
{
public:
	unsigned char m_pad000[0x258];
	AIUpdateInterface *m_ai; // +0x258
	Player *getControllingPlayer() const;
};

struct State;

struct StateConditionInfo
{
	Bool (*test)(State *thisState, void *userData);
	StateID toStateID;
	void *userData;
};

class StateMachine
{
public:
	StateMachine(Object *owner, UnsignedInt nameKey, Bool flag);
	virtual ~StateMachine();
	void defineState(StateID id, State *state, StateID successID, StateID failureID, const StateConditionInfo *conditions = 0);
	Object *getOwner() const { return m_owner; }
protected:
	unsigned char m_pad04[0x14 - 0x04];
	Object *m_owner; // +0x14
	unsigned char m_pad18[0x3C - 0x18]; // operator new size 0x3C
};

struct State
{
public:
	virtual ~State();
	Object *getMachineOwner() const { return m_machine->getOwner(); }
protected:
	unsigned char m_pad04[0x18 - 0x04];
	StateMachine *m_machine; // +0x18
	unsigned char m_pad1C[0x20 - 0x1C];
};

class SupplyTruckWantsToPickUpOrDeliverBoxesState : public State
{
public:
	virtual StateReturnType update();
};

StateReturnType SupplyTruckWantsToPickUpOrDeliverBoxesState::update()
{
	Object *owner = getMachineOwner();
	AIUpdateInterface *ownerAI = owner->m_ai;
	if (!ownerAI)
		return STATE_FAILURE;

	Player *ownerPlayer = owner->getControllingPlayer();
	ResourceGatheringManager *manager = ownerPlayer->getResourceGatheringManager();
	if (!manager)
		return STATE_FAILURE;

	SupplyTruckAIInterface *update = ownerAI->getSupplyTruckAIInterface();
	if (!update)
		return STATE_FAILURE;

	if (!update->isAvailableForSupplying())
		return STATE_FAILURE;

	int numBoxes = update->getNumberBoxes();
	if (numBoxes > 0)
	{
		Object *bestCenter = manager->findBestSupplyCenter(owner);
		if (bestCenter)
		{
			ownerAI->m_commands.aiDock(bestCenter, CMD_FROM_AI);
			return STATE_SUCCESS;
		}
	}
	else
	{
		Object *bestWarehouse = manager->findBestSupplyWarehouse(owner);
		if (bestWarehouse)
		{
			ownerAI->m_commands.aiDock(bestWarehouse, CMD_FROM_AI);
			return STATE_SUCCESS;
		}
		if (update->v06())
		{
			Coord3D pos;
			if (manager->rva004F5A67(owner, &pos))
			{
				ownerAI->m_commands.aiHarvest(&pos, CMD_FROM_AI);
				return STATE_SUCCESS;
			}
		}
	}
	return STATE_CONTINUE;
}
