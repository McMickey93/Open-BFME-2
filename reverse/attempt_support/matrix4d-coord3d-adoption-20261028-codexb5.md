# Matrix4D Coord3D adoption

At base b5353ca4e9, the queued Matrix4D unit declares Coord3D as a class;
the canonical header defines it as a struct. Replacing the private body with
`../../../Include/Lib/Coord3D.h` compiles, but eight existing ledger symbols
are absent because MSVC decorates the struct key as U rather than class V.
A preceding `class Coord3D;` declaration does not preserve the V spelling.
The trial was reverted. The restored unit passes 24/24 matched rows and the
frozen-file check. The queue row remains.

Before adopting the header, establish the target's native class-key identity
and reconcile the existing Matrix4D symbol owners and their consumers together.
The source bytes alone do not establish the decorated names. No linked or
header-debt gain is claimed.
