# StlSweepW5Rva001506BF `_M_fill_insert` link repair (LINK-083 shape), partial

Agent K9, 2026-10-26. Unit `Code/Libraries/Source/WWVegas/WWLib/StlSweepW5Rva001506BF.cpp`
(222 B, matched, does not link). Siblings `StlSweepW5Rva0015079D.cpp` and
`StlSweepW5Rva0015087B.cpp` are the same body over the Rva0014F4A1 / Rva0014F4C2 elements.

## Why it does not link

The unit instantiates `vector<Rva001506BFElement>::_M_fill_insert`, which emits
non-retail COMDATs for the element copy ctor, `fill`, `__uninitialized_copy` and
`_M_insert_overflow`. Retail's callees are already rowed under the real element:

| callee | row |
|---|---|
| 0x0014F480 | `??0Rva0014F480@@QAE@ABV0@@Z` (Rva0014FDerivedCopies.cpp) |
| 0x0014F8E4 | `__uninitialized_copy<Rva0014F480*,Rva0014F480*>` (StlportVectorRva0014F480Overflow.cpp) |
| 0x0014F995 | `Rva0014F995CopyBackward` 3-arg; retail pushes a 4th tag arg |
| 0x0014F9B2 | `Rva0014F9B2Fill(Rva0014F4A1*, ...)` |
| 0x0014F90D | `Rva0014F90DFillN(Rva0014F480*, ...)` |
| 0x00150282 | `vector<Rva0014F480>::_M_insert_overflow` (protected) |

## Best draft: 212 / 222 B (source at the end of this note)

Stub `_STL::vector` (StlSweepR3Rva003F318C.cpp pattern) with
`template <class U, class B> friend class vector;` so the specialization calls
`vector<Rva0014F480>::_M_insert_overflow` directly (a derived-view wrapper is an
extra out-of-line call at /Ob0). Findings:

- A POD `struct __false_type {}` temporary is zero-filled (`33 c0 8d 7d xx aa`)
  when the callee is opaque (declared-only template, explicit-specialization
  declaration or plain function). Retail has no fill. Making it non-POD with a
  declared `__false_type &operator=(const __false_type &);` removes the fill
  without changing the mangled tag type. A `__forceinline` ctor does not inline
  at /Ob0 (it becomes an unresolved call).
- Retail CSEs `_M_finish` across the copy-ctor call (the original instantiation
  saw the element copy ctor's body). An explicit `pointer __finish = _M_finish;`
  before the capacity test, `__elems_after = __finish - __position` after the
  copy, and `__old_finish = _M_finish` (reload) reproduce that dataflow and put
  `__n` in ebx.
- Residual 10 bytes: retail spills `__elems_after` into the `__x` slot
  ([ebp+0x10]) and places all four tag temporaries at [ebp+0x0B]; the draft uses
  [ebp+0x0C] and puts the two `__uninitialized_copy` tags at [ebp+0x13].
  No effect: reordering old_finish/elems_after, `pointer const`, assignment in
  the condition, `const` x_copy, copy-init x_copy, non-const elems_after,
  calling 0x0014F8E4 through a cast function pointer, `__n <= ...` form
  (12 B off), moving `__finish` above `if (__n != 0)` (22 B off).

Next: try spelling the uninitialized_copy calls with a visible template body
whose name still mangles to the rowed one only if the bytes it emits equal
0x0014F8E4 (then the COMDAT is retail's), or find what makes cl colour the
`__x` slot first.

## Same wall in StlSweepW4Rva000C225D.cpp (254/260 B)

`vector<Rva000C225DElement>::_M_fill_insert` (260 B, plus the 5-byte `insert` forwarder at
0x000C3712) is the same body over BfmeStringRecord000B94D2 (EH: the copy has a dtor). Callees
are rowed: 0x000B94D2 copy ctor, 0x000B6CF1 dtor, 0x000BBAA1
`__uninitialized_copy<const BfmeStringRecord000B94D2*, BfmeStringRecord000B94D2*>`, 0x000BBCD4
`uninitialized_fill_n`, 0x000C0C2F `vector<BfmeStringRecord000B94D2>::_M_insert_overflow`, and
0x000B67D9 / 0x000B67F6 `copy_backward` / `fill` over Rva00B6CF1. The same stub-vector draft is
exact except 6 bytes: the `_M_finish - __n` spill goes to [ebp+0x10] (the `__x` slot) where
retail uses [ebp+0x0C] (the `__n` slot), and both `__uninitialized_copy` tags sit one byte
below that spill (0x0F instead of 0x0B). The copy_backward and overflow tags already match.
Here the CSE local is not needed (retail reloads `_M_finish`). Same outcome with: an empty
base class instead of the declared operator=, a named tag, a named `__src` local, a cast
function-pointer call to 0x000BBAA1, a reference local for `__x`, and `size_type(...)` casts.
The rule seems to be: the tag temporary goes one byte below the spill slot, so only the
spill-slot choice (`__n` vs `__x` home) is left. This looks like the wall for the whole
`StlSweepW4`/`W5` `_M_fill_insert` group (001524F9, 0017422D, 00215949, 003F53DA, 005205DA,
0039C415 have the same row and unresolved list).

### W4 draft (254/260 B)

```cpp
// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// Element identity and unconstrained fields remain address-derived structural inference.
// cl: /O1 /Ob0 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// 0x000C225D is vector<Rva000C225DElement>::_M_fill_insert (STLport 4.5.3 _vector.c) over the
// 8-byte BfmeStringRecord000B94D2 records; 0x000C3712 is the insert(pos, n, x) forwarder. The
// callees are rowed under their own spellings: 0x000B94D2 / 0x000B6CF1 the record's copy ctor and
// dtor (StringRecordCopyBFME2.cpp, StringRecordDtors.cpp), 0x000BBAA1
// __uninitialized_copy<const BfmeStringRecord000B94D2*>, 0x000BBCD4 uninitialized_fill_n and 0x000C0C2F
// vector<BfmeStringRecord000B94D2>::_M_insert_overflow, and 0x000B67D9 / 0x000B67F6
// copy_backward / fill over Rva00B6CF1. Instantiating _M_fill_insert over the address-derived
// element emitted non-retail copies of them and left its ctor/dtor/operator= unresolved, so this
// unit spells only the vector shape it needs (StlSweepR3Rva003F318C.cpp) and calls the rows by
// their own types. Retail passes copy_backward its __false_type tag as a fourth argument, hence
// the tag-taking cast. The declared operator= keeps __false_type non-POD: cl 7.1 zero-fills an
// empty POD temporary passed to an opaque callee, and retail does not.
struct Rva000C225DElement { char bytes[8]; };
struct BfmeStringRecord000B94D2
{
	BfmeStringRecord000B94D2(const BfmeStringRecord000B94D2 &);
	~BfmeStringRecord000B94D2();
	char bytes[8];
};
struct Rva00B6CF1;

namespace _STL {
struct __false_type { __false_type &operator=(const __false_type &); };
template <class T> class allocator {};
template <class T, class A> class vector
{
	template <class U, class B> friend class vector;
public:
	typedef T *pointer;
	typedef T *iterator;
	typedef unsigned int size_type;
	void insert(iterator pos, size_type n, const T &x) { _M_fill_insert(pos, n, x); }
	void _M_fill_insert(iterator pos, size_type n, const T &x);
protected:
	void _M_insert_overflow(pointer pos, const T &x, const __false_type &, size_type fill_len, bool atend = false);
	T *_M_start;
	T *_M_finish;
	T *_M_end_of_storage;
};
template <class I, class F> F __uninitialized_copy(I first, I last, F result, const __false_type &);
template <class F, class S, class T> F uninitialized_fill_n(F first, S n, const T &x);
template <class B1, class B2> B2 copy_backward(B1 first, B1 last, B2 result);
template <class F, class T> void fill(F first, F last, const T &x);
}

typedef Rva00B6CF1 *(__cdecl *Rva000B67D9Fn)(Rva00B6CF1 *, Rva00B6CF1 *, Rva00B6CF1 *);
typedef Rva00B6CF1 *(__cdecl *Rva000B67D9TagFn)(Rva00B6CF1 *, Rva00B6CF1 *, Rva00B6CF1 *, const _STL::__false_type &);

namespace _STL {
typedef BfmeStringRecord000B94D2 Rva000C225DRecord;
typedef vector<Rva000C225DRecord, allocator<Rva000C225DRecord> > Rva000C225DRecordVector;
template <>
void vector<Rva000C225DElement, allocator<Rva000C225DElement> >::_M_fill_insert(iterator __position, size_type __n, const Rva000C225DElement &__x)
{
	if (__n != 0) {
		if (size_type(_M_end_of_storage - _M_finish) >= __n) {
			Rva000C225DRecord __x_copy(*(const Rva000C225DRecord *)&__x);
			const size_type __elems_after = _M_finish - __position;
			pointer __old_finish = _M_finish;
			if (__elems_after > __n) {
				__uninitialized_copy((const Rva000C225DRecord *)(_M_finish - __n), (const Rva000C225DRecord *)_M_finish, (Rva000C225DRecord *)_M_finish, __false_type());
				_M_finish += __n;
				((Rva000B67D9TagFn)(Rva000B67D9Fn)&copy_backward<Rva00B6CF1 *, Rva00B6CF1 *>)((Rva00B6CF1 *)__position, (Rva00B6CF1 *)(__old_finish - __n), (Rva00B6CF1 *)__old_finish, __false_type());
				fill((Rva00B6CF1 *)__position, (Rva00B6CF1 *)(__position + __n), *(const Rva00B6CF1 *)&__x_copy);
			}
			else {
				uninitialized_fill_n((Rva000C225DRecord *)_M_finish, __n - __elems_after, __x_copy);
				_M_finish += __n - __elems_after;
				__uninitialized_copy((const Rva000C225DRecord *)__position, (const Rva000C225DRecord *)__old_finish, (Rva000C225DRecord *)_M_finish, __false_type());
				_M_finish += __elems_after;
				fill((Rva00B6CF1 *)__position, (Rva00B6CF1 *)__old_finish, *(const Rva00B6CF1 *)&__x_copy);
			}
		}
		else
			((Rva000C225DRecordVector *)this)->_M_insert_overflow((Rva000C225DRecord *)__position, *(const Rva000C225DRecord *)&__x, __false_type(), __n);
	}
}
}
template void _STL::vector<Rva000C225DElement, _STL::allocator<Rva000C225DElement> >::insert(Rva000C225DElement *, unsigned int, Rva000C225DElement const &);
```

## Draft source (212/222 B)

```cpp
// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// Element identity and unconstrained fields remain address-derived structural inference.
// cl: /O1 /arch:SSE /G7 /Ob0 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// 0x001506BF is vector<Rva001506BFElement>::_M_fill_insert (STLport 4.5.3 _vector.c) over the
// 8-byte Rva0014F480 elements. Its callees are rowed under their own spellings: 0x0014F480
// ??0Rva0014F480 (copy ctor) and 0x0014F8E4 __uninitialized_copy<Rva0014F480*> (Rva0014FDerivedCopies.cpp,
// StlportVectorRva0014F480Overflow.cpp), 0x0014F995 Rva0014F995CopyBackward, 0x0014F9B2 Rva0014F9B2Fill,
// 0x0014F90D Rva0014F90DFillN (Rva0014F995CopyBackward.cpp, Rva0014F9FillN.cpp) and 0x00150282
// vector<Rva0014F480>::_M_insert_overflow. Instantiating _M_fill_insert over the address-derived
// element emitted non-retail copies of all of them, so this unit spells only the vector shape it
// needs (Rva00569F0CAssign.cpp / StlSweepR3Rva003F318C.cpp) and calls the rows by their own types.
// Retail passes copy_backward its __false_type tag as a fourth argument, hence the tag-taking cast.
struct Rva001506BFElement { unsigned words[2]; };
class Rva0014F480 { public: Rva0014F480(const Rva0014F480 &); unsigned words[2]; };
class Rva0014F4A1;
struct Rva0014F718;

namespace _STL {
struct __false_type { __false_type &operator=(const __false_type &); };
template <class T> class allocator {};
template <class T, class A> class vector
{
	template <class U, class B> friend class vector;
public:
	typedef T *pointer;
	typedef T *iterator;
	typedef unsigned int size_type;
	void _M_fill_insert(iterator pos, size_type n, const T &x);
protected:
	void _M_insert_overflow(pointer pos, const T &x, const __false_type &, size_type fill_len, bool atend = false);
	T *_M_start;
	T *_M_finish;
	T *_M_end_of_storage;
};
template <class I, class F> F __uninitialized_copy(I first, I last, F result, const __false_type &);
}

void __cdecl Rva0014F995CopyBackward(Rva0014F718 *first, Rva0014F718 *last, Rva0014F718 *result);
void Rva0014F9B2Fill(Rva0014F4A1 *first, Rva0014F4A1 *last, const Rva0014F4A1 &x);
Rva0014F480 *Rva0014F90DFillN(Rva0014F480 *first, unsigned int n, const Rva0014F480 &x);
typedef void (__cdecl *Rva0014F995TagFn)(Rva0014F718 *, Rva0014F718 *, Rva0014F718 *, const _STL::__false_type &);

namespace _STL {
typedef vector<Rva0014F480, allocator<Rva0014F480> > Rva0014F480Vector;
template <>
void vector<Rva001506BFElement, allocator<Rva001506BFElement> >::_M_fill_insert(iterator __position, size_type __n, const Rva001506BFElement &__x)
{
	if (__n != 0) {
		pointer __finish = _M_finish;
		if (size_type(_M_end_of_storage - __finish) >= __n) {
			Rva0014F480 __x_copy(*(const Rva0014F480 *)&__x);
			const size_type __elems_after = __finish - __position;
			pointer __old_finish = _M_finish;
			if (__elems_after > __n) {
				__uninitialized_copy((Rva0014F480 *)(_M_finish - __n), (Rva0014F480 *)_M_finish, (Rva0014F480 *)_M_finish, __false_type());
				_M_finish += __n;
				((Rva0014F995TagFn)&Rva0014F995CopyBackward)((Rva0014F718 *)__position, (Rva0014F718 *)(__old_finish - __n), (Rva0014F718 *)__old_finish, __false_type());
				Rva0014F9B2Fill((Rva0014F4A1 *)__position, (Rva0014F4A1 *)(__position + __n), *(const Rva0014F4A1 *)&__x_copy);
			}
			else {
				Rva0014F90DFillN((Rva0014F480 *)_M_finish, __n - __elems_after, __x_copy);
				_M_finish += __n - __elems_after;
				__uninitialized_copy((Rva0014F480 *)__position, (Rva0014F480 *)__old_finish, (Rva0014F480 *)_M_finish, __false_type());
				_M_finish += __elems_after;
				Rva0014F9B2Fill((Rva0014F4A1 *)__position, (Rva0014F4A1 *)__old_finish, *(const Rva0014F4A1 *)&__x_copy);
			}
		}
		else
			((Rva0014F480Vector *)this)->_M_insert_overflow((Rva0014F480 *)__position, *(const Rva0014F480 *)&__x, __false_type(), __n);
	}
}
}
```
