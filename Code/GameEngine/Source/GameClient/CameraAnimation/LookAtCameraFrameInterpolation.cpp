// cl: /O1 /G7 /arch:SSE /MD /DNDEBUG
// Native 540DCA..540E82184B and WB A9D800 establish the frame-channel wrapper.
// The24-byte frame has mode0, a12-byte coordinate at4 and scalar channels10/14.
// Constructing the result evaluates mode, scalar14, scalar10 and coordinates
// in native order. The existing providers retain their established ABI views;
// source frame and helper names are unknown. No reference donor was available.
struct Rva00540E9DSrc { int a,b,c; };
class Rva00540D94 {
public:
    Rva00540D94(const Rva00540E9DSrc &,float,float,int);
    int mode;
    Rva00540E9DSrc position;
    float scalar10,scalar14;
};
class CameraAnimationFrameData {
public:
    float doInterpolate(float,float *,int,float *,int,float *,int,float *,int);
    int mode;
};
class Rva005C71ADView {
public:
    void *rva005C71AD(void *,float,void *,void *,void *,void *,void *,void *,void *,void *);
    int mode;
};
Rva00540D94 Rva00540DCAGet(float t,Rva00540D94 *prevFrame,int ta,Rva00540D94 *startFrame,int tb,Rva00540D94 *endFrame,int tc,Rva00540D94 *nextFrame,int td)
{
    Rva00540E9DSrc position;
    return Rva00540D94(
        *(Rva00540E9DSrc *)((Rva005C71ADView *)startFrame)->rva005C71AD(&position,t,&prevFrame->position,(void *)ta,&startFrame->position,(void *)tb,&endFrame->position,(void *)tc,&nextFrame->position,(void *)td),
        ((CameraAnimationFrameData *)startFrame)->doInterpolate(t,&prevFrame->scalar10,ta,&startFrame->scalar10,tb,&endFrame->scalar10,tc,&nextFrame->scalar10,td),
        ((CameraAnimationFrameData *)startFrame)->doInterpolate(t,&prevFrame->scalar14,ta,&startFrame->scalar14,tb,&endFrame->scalar14,tc,&nextFrame->scalar14,td),
        startFrame->mode);
}

