// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /GX- /GS-
// Notifies the indexed shader through virtual slot 1 and clears the current-shader latch.
class Rva00075695Item
{
public:
	virtual void f0();
	virtual void f1();
};

class ShaderInterface;
extern ShaderInterface *W3DShaders[];
class W3DShaderManager
{
	friend void Rva00075695Notify(int index);
protected:
	static int m_currentShader;
};

void __cdecl Rva00075695Notify(int index)
{
	if (W3DShaderManager::m_currentShader != 0) {
		Rva00075695Item * volatile *slot = (Rva00075695Item * volatile *)&W3DShaders[index];
		if (*slot != 0)
			(*slot)->f1();
		W3DShaderManager::m_currentShader = 0;
	}
}
