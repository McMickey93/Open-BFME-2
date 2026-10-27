// ?Rva008791E0Remove@@YAHPAXPAPAX@Z
struct Rva008791E0Table
{
	void *m_vals[20];
	void *m_keys[20];
	int m_count;
};

extern unsigned long mem_array[2][20];
extern int mem_array_ents;

int __cdecl Rva008791E0Remove(void *key, void **out)
{
	int i;

	for (i = 0; i < mem_array_ents; i++)
	{
		if (((Rva008791E0Table *)mem_array)->m_keys[i] == key)
		{
			*out = ((Rva008791E0Table *)mem_array)->m_vals[i];

			void **p = &((Rva008791E0Table *)mem_array)->m_vals[i];
			int count = mem_array_ents;

			i++;
			if (i < count)
			{
				do
				{
					p[0] = p[1];
					p[20] = p[21];
					p++;
					i++;
				} while (i < count);
			}

			mem_array_ents = count - 1;
			return 0;
		}
	}

	return -1;
}

// 0x008791B0: append the pair while fewer than 20 entries are live, else -1.
// ?Rva008791B0Add@@YAHPAX0@Z
int __cdecl Rva008791B0Add(void *a, void *b)
{
	int i = mem_array_ents;
	if (i >= 20)
		return -1;
	((Rva008791E0Table *)mem_array)->m_vals[i] = a;
	((Rva008791E0Table *)mem_array)->m_keys[i] = b;
	mem_array_ents = i + 1;
	return 0;
}
