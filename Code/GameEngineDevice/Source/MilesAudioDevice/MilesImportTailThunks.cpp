// cl: /O2 /Oi-
// Miles import wrappers omitted by the region-/O1 generated thunk batch.
// The named import gate proves each IAT slot. ABI views follow the existing
// MilesAudioManager and Rva0010F42AFinish declarations; no SDK ownership claim.
extern "C" {
__declspec(dllimport) void __stdcall AIL_set_3D_orientation(void*,float,float,float,float,float,float);
__declspec(dllimport) int __stdcall AIL_quick_startup(int,int,int,int,int);
__declspec(dllimport) int __stdcall AIL_stream_info(void*,int*,int*,int*,int*);
void __stdcall ji_00629d92(void*p,float faceX,float faceY,float faceZ,float upX,float upY,float upZ) { AIL_set_3D_orientation(p,faceX,faceY,faceZ,upX,upY,upZ); }
int __stdcall ji_00629ea0(int m_useDigital,int m_useMidi,int m_outputRate,int m_outputBits,int m_outputChannels) { return AIL_quick_startup(m_useDigital,m_useMidi,m_outputRate,m_outputBits,m_outputChannels); }
int __stdcall ji_00629ef4(void*stream,int*dataRate,int*m_soundType,int*length,int*memory) { return AIL_stream_info(stream,dataRate,m_soundType,length,memory); }
}
