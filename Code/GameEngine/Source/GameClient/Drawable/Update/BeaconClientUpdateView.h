#pragma once

// BeaconClientUpdate and its module data as the units of the
// BeaconClientUpdate.cpp TU reach them: the ctor (0x004C9598), xfer
// (0x004C95C9), the pool key, hideBeacon and clientUpdate. The ctor stores
// the vtable by hand (novtable); the inherited virtual interface remains
// unreconstructed.
class Thing;
class ModuleData;
class Object;
class Drawable;
class Xfer;
class GameLogic;

extern GameLogic *TheGameLogic;

enum ParticleSystemID
{
    INVALID_PARTICLE_SYSTEM_ID = 0
};

enum NameKeyType
{
    NK_UNKNOWN = 0
};

class NameKeyGenerator
{
public:
    NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

struct ClockView
{
    char pad[0x40];
    unsigned frame;
};

class BeaconClientUpdateModuleData
{
public:
    BeaconClientUpdateModuleData();
    virtual ~BeaconClientUpdateModuleData();

    int m_pad04;
    unsigned framesBetweenRadarPulses;
    unsigned radarPulseDuration;
};

class ObjectModule
{
public:
    ObjectModule(Thing *thing, const ModuleData *moduleData);
    virtual ~ObjectModule();
    void xfer(Xfer *xfer);

protected:
    const ModuleData *m_moduleData;
    Object *m_object;
};

// Opaque intermediate; ctor resolves to the opaque pin at 0x00362EC7.
class Rva00362EC7 : public ObjectModule
{
public:
    Rva00362EC7(Thing *thing, const ModuleData *moduleData);
    virtual ~Rva00362EC7();
};

class __declspec(novtable) BeaconClientUpdate : public Rva00362EC7
{
public:
    BeaconClientUpdate(Thing *thing, const ModuleData *moduleData);
    virtual ~BeaconClientUpdate();
    virtual void clientUpdate();
    virtual NameKeyType getModuleNameKey() const;
    void hideBeacon();

protected:
    virtual void xfer(Xfer *xfer);

    const BeaconClientUpdateModuleData *getBeaconClientUpdateModuleData() const
    {
        return (const BeaconClientUpdateModuleData *)m_moduleData;
    }
    Drawable *getDrawable() const
    {
        return (Drawable *)m_object;
    }

    ParticleSystemID id;
    unsigned lastRadarPulse;
};
