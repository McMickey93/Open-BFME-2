# SidesList splitter AsciiString adoption, 2026-10-27

Inspected revision: `add01ad2ad`. Source:
`Code/GameEngine/Source/GameLogic/Rva00194810Split_Rva0032abda.cpp`.
This prerequisite was found while investigating the approved SidesList
consolidation cohort; no source paths or ledger rows move in this change.

The original private StringBase granted BfmeWordEL constructor access and
declared a separate private AsciiString view for TheEmptyString. Canonical
StringBase grants constructor access to AsciiString. Deriving the four-byte
wrapper from canonical AsciiString and forwarding construction through its
public copy/substring constructors preserves layout and lifetime behavior.
The existing speed-built getCharAt specialization remains visible with the
canonical declaration's exception specification. Omitting that definition
made the compiler reload the buffer after each accessor call; retaining it
restores the complete 184-byte retail function. The 10-byte cleanup handler
and its EH graph remain exact. These are target byte/codegen observations;
the placeholder wrapper names are not claimed as recovered native identities.

Checks:

- `./build.sh Code/GameEngine/Source/GameLogic/Rva00194810Split_Rva0032abda.cpp`:
  2/2 function rows exact; declared-unmatched check passes.
- `header_adopt_lane.py accept --class AsciiString` on the source: PASS,
  one queue entry retired through the owning lane.
- `eh_verify.py` on the source: EXACT 1, no baseline or missing object.
- `allowed_symbols.py --source` on the source: 10 references, eight owner,
  one EH and one alias; no wrong binding. The accessor reference changes from
  the private folded spelling to its canonical public owner at 0x00035720.
- `data_check.py` on the source: zero findings.
- `link_check.py` on the source, `Common/Bfme5TwoWordPairFactory_Rva0002C621.cpp`
  and `Map/Rva0019B780Lookup_Rva0032d0b5.cpp`: 3/3 LINKS,
  299 -> 299 authored bytes against index `bf3dd31211` (2026-10-27 00:39).
  This is an ordinary preview, not a new census result.
- `hatch_counters.py --update`: class_gate_allow 53 -> 52, removing only this
  source's obsolete AsciiString exemption. Existing optimization pragmas stay.
- `check_csv.py`: all function, symbol and data ledgers pass unchanged.

The official BFME 1 upstream freshness fetch found `a0940f921b5b8d9029fc922b8032abcf4e60d240`,
ahead of the clean pinned checkout `4fa9d591641a743b86f2320343b7a276585b814b`.
Another worker held `file:reference/open-bfme-1`; the checkout, gitlink and
freshness receipt were left unchanged. This repair uses the existing pinned
inputs and canonical BFME 2 header, with no donor-source recovery claim.
